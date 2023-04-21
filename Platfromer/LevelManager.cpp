#include "LevelManager.hpp"
#include <cstdlib>
char ** LevelManager::createLevel(VertexArray & rVaLevel)
{
    LevelSize.x = 0;
    LevelSize.y = 0;
    
    CurrentLevel++;
    
    string levelToLoad;
    switch(CurrentLevel)
    {
        case 1: levelToLoad = LEVEL1;
                StartPosition.x = 100;
                StartPosition.y = 450;
                break;
        case 2: levelToLoad = LEVEL2;
                StartPosition.x = 100;
                StartPosition.y = 450;
                break;
        case 3: levelToLoad = LEVEL3;
                StartPosition.x = 100;
                StartPosition.y = 450;
                break;
    }
    
    ifstream inputFile(levelToLoad);        //open txt file with drawn map
    string row;
    
    //Count rows
    while(inputFile >> row)
    {
        LevelSize.y++;
    }
    LevelSize.x = row.length();         //count length of row
    
    inputFile.clear();                  //reset the EOF flag
    inputFile.seekg(0, ios::beg);       //move to the start of the file
    
    
    //Prepare 2D array
    char ** arrayLevel = new char * [LevelSize.y];
    for(int i = 0; i < LevelSize.y; i++)
    {
        arrayLevel[i] = new char[LevelSize.x];
    }
    
    row.clear();                        //clear string
    int y = 0;
    while(inputFile >> row)             //read and save map in 2D array
    {
        for(int x = 0; x < row.length(); x++)
        {            
            arrayLevel[y][x] = row[x];
        }
        y++;
    }
    inputFile.close();
    
    //What type of primitive to use
    rVaLevel.setPrimitiveType(Quads);
    
    //Resize the array
    rVaLevel.resize(LevelSize.x * LevelSize.y * VERTS_IN_QUAD);
    
    int currentVertex = 0;
    
    for(int x = 0; x < LevelSize.x; x++)
    {
        for(int y = 0; y < LevelSize.y; y++)
        {
            //Set the position of each QUAD
            rVaLevel[currentVertex + 0].position = Vector2f(x * TILE_SIZE , y * TILE_SIZE);     //first coordinate
            rVaLevel[currentVertex + 1].position = Vector2f((x * TILE_SIZE) + TILE_SIZE, y * TILE_SIZE);    //second coordinate
            rVaLevel[currentVertex + 2].position = Vector2f((x * TILE_SIZE) + TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE); //third coordinate
            rVaLevel[currentVertex + 3].position = Vector2f(x * TILE_SIZE, (y * TILE_SIZE) + TILE_SIZE);    //fourth
            
            //Decide which of the tile to choose
            int verticalOffset = 0;
            if(arrayLevel[y][x] == '0')             //blank
            {
                verticalOffset = 0 * TILE_SIZE;
            }
            if(arrayLevel[y][x] == '1')             //grass block
            {
                verticalOffset = 1 * TILE_SIZE;
            }
            if(arrayLevel[y][x] == '2')             //dirt block
            {
                verticalOffset = 2 * TILE_SIZE;
            }
            if(arrayLevel[y][x] == '3')             //part of the portal
            {
                verticalOffset = 3 * TILE_SIZE;
            }
            if(arrayLevel[y][x] == '4')             //point to load new level
            {
                verticalOffset = 4 * TILE_SIZE;
            }
            if(arrayLevel[y][x] == 'S')             //spawn enemies
            {
                EnemyStartPosition.push_back(Vector2f(x * TILE_SIZE,y * TILE_SIZE));
                EnemyNumber++;
                verticalOffset = 0 * TILE_SIZE;
            }
            if(arrayLevel[y][x] == 'C')             //spawn coins
            {
                CoinPosition.push_back(Vector2f(x * TILE_SIZE, y * TILE_SIZE));
                coinNumber++;
                verticalOffset = 0 * TILE_SIZE;
            }
            if(arrayLevel[y][x] == 'H')             //spawn collectable heart
            {
                HeartPosition.push_back(Vector2f(x * TILE_SIZE, y * TILE_SIZE));
                heartNumber++;
                verticalOffset = 0 * TILE_SIZE;
            }
            if(arrayLevel[y][x] == '5')
            {
                verticalOffset = 5 * TILE_SIZE;
            }
            
            //Set each QUAD with the texture
            rVaLevel[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
            rVaLevel[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
            rVaLevel[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
            rVaLevel[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
            
            //next QUAD
            currentVertex += VERTS_IN_QUAD;
        }
    }
    
    return arrayLevel;
}

Vector2i & LevelManager::getLevelSize()
{
    return LevelSize;
}

Vector2f & LevelManager::getStartPosition()
{
    return StartPosition;
}

int LevelManager::getCurrentLevel()
{
    return CurrentLevel;
}

int LevelManager::getEnemyNumber()
{
    return EnemyNumber;
}

std::vector<Vector2f> & LevelManager::getEnemyStartPosition()
{
    return EnemyStartPosition;
}

void LevelManager::setEnemyNumber(int num)
{
    EnemyNumber = num;
}

void LevelManager::setCurrentLevel(int num)
{
    CurrentLevel = num;
}

int LevelManager::getMaxLevel()
{
    return MAX_LEVEL;
}

std::vector<Vector2f> & LevelManager::getCoinPosition()
{
    return CoinPosition;
}

int LevelManager::getCoinNumber()
{
    return coinNumber;
}

void LevelManager::setCoinNumber(int num)
{
    coinNumber = num;
}

std::vector<Vector2f> & LevelManager::getHeartPosition()
{
    return HeartPosition;
}

int LevelManager::getHeartNumber()
{
    return heartNumber;
}

void LevelManager::setHeartNumber(int num)
{
    heartNumber = num;
}
