#ifndef LevelManager_hpp
#define LevelManager_hpp

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "TextureManager.hpp"
#include "RESOURCES.h"
#include <fstream>

using namespace sf;

class LevelManager
{
private:
    Vector2i LevelSize;                                     //size of the map
    Vector2f StartPosition;                                 //Player's start position
    std::vector<Vector2f> EnemyStartPosition;               //Array of enemies' start positions
    std::vector<Vector2f> CoinPosition;                     //Array of coins posittions
    std::vector<Vector2f> HeartPosition;                    //Array of hearts posittions
    const int MAX_LEVEL = 7;                                //Maximum levels of the game
    int CurrentLevel = 0;                                   //current level
    int EnemyNumber = 0;                                    //Count of enemies on the level
    int coinNumber = 0;                                     //Count of coins on the level
    int heartNumber = 0;                                    //Count of hearts' on the level
public:
    const int TILE_SIZE = 32;                               //Size of the texture
    const int VERTS_IN_QUAD = 4;                            //Verticies of the texture
    Vector2i & getLevelSize();                              //get Level Size
    Vector2f & getStartPosition();                          //get Player's start position
    std::vector<Vector2f> & getEnemyStartPosition();        //get enemies' start positions
    std::vector<Vector2f> & getCoinPosition();              //get coins' positions
    std::vector<Vector2f> & getHeartPosition();             //get hearts' positions
    int getMaxLevel();                                      //get max level number
    int getEnemyNumber();                                   //get Number of enemies on the level
    int getCoinNumber();                                    //get coin number on the level
    int getHeartNumber();                                   //get heart number on the level
    void setEnemyNumber(int num);                           //set enemy number
    void setCoinNumber(int num);                            //set coin number
    void setHeartNumber(int num);                           //set heart number on the level
    int getCurrentLevel();                                  //get current level
    void setCurrentLevel(int num);                          //set level number
    char ** createLevel(VertexArray & rVaLevel);            //get 2D array (Level) from txt file
};

#endif /* LevelManager_hpp */
