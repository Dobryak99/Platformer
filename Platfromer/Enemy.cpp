#include "Enemy.hpp"
#include <ctime>

Enemy::Enemy()
{
    EnemyTexture = TextureManager::GetTexture(ENEMY_TEXTURE);      //add texture
    EnemySprite.setTexture(EnemyTexture);                          //set texture
}

void Enemy::Spawn(Vector2f & position, float gravity)
{
    srand(time(0));                                     //set random generator
    Gravity = gravity;
    Position = position;
    EnemySprite.setPosition(Position);
    
    int choice  = (rand() % 2);                         // 0 or 1
    switch(choice)
    {
        case 0: LeftMoving = true;
                break;
        case 1: RightMoving = true;
                break;
    }
}

void Enemy::update(float & dt)
{
    IsFalling = true;
    
    if(RightMoving)
    {
        Position.x += Speed * dt;               //moving right
        //animation
        currentEnemyFrame += dt * 10;
        if(currentEnemyFrame > 4)
        {
            currentEnemyFrame = 0;
        }
        EnemySprite.setTextureRect(IntRect(32 * static_cast<int>(currentEnemyFrame), 0, 32,50));
    }
    if(LeftMoving)
    {
        Position.x -= Speed * dt;               //moving left
        //Animation
        currentEnemyFrame += dt * 10;
        if(currentEnemyFrame > 4)
        {
            currentEnemyFrame = 0;
        }
        EnemySprite.setTextureRect(IntRect(32 * static_cast<int>(currentEnemyFrame) + 32, 0, -32,50));
    }
     
    if(IsFalling)
    {
        Position.y += Gravity * 0.25 * dt;      //falling down
    }
    
    FloatRect r = getPosition();                //copy global bounds
    
    //Feet (if you want to know what is it, check PlayableCharacter.cpp)
    Feet.left = r.left + 1;
    Feet.top = r.top + r.height - 1;
    Feet.width = r.width  - 2;
    Feet.height = 1;
    
    //Head
    Head.left = r.left + 1;
    Head.top = r.top;
    Head.width = r.width - 1;
    Head.height = 1;
    
    //Right side
    RightSide.left = r.left + r.width - 1;
    RightSide.top = r.top + (r.height * 0.35);
    RightSide.width = 1;
    RightSide.height = r.height * 0.3;
    
    //Left side
    LeftSide.left = r.left;
    LeftSide.top = r.top + (r.height * 0.35);
    LeftSide.width = 1;
    LeftSide.height = r.height * 0.3;
    
    //Body
    Body.left = r.left + 3;
    Body.top = r.top + 3;
    Body.width = r.width - 6;
    Body.height = r.height - 6;
    
    EnemySprite.setPosition(Position);              //set enemy position
}

FloatRect Enemy::getPosition()
{
    return EnemySprite.getGlobalBounds();
}

FloatRect & Enemy::getFeet()
{
    return Feet;                                                    //get Feet rect
}

FloatRect & Enemy::getHead()
{
    return Head;                                                    //get head rect
}

FloatRect & Enemy::getRight()
{
    
    return RightSide;                                               //get right side rect
}

FloatRect & Enemy::getLeft()
{
    
    return LeftSide;                                                //get left side rect
}

FloatRect & Enemy::getBody()                                        //get rect of the body
{
    return Body;
}

Sprite & Enemy::getSprite()
{
    return EnemySprite;                                             //Get sprite
}

void Enemy::stopFalling(float position)
{
    IsFalling = false;                                              //stop falling
    Position.y = position - EnemySprite.getGlobalBounds().height;   //set new position for Y coordinate
    EnemySprite.setPosition(Position);                              //set enemy position
}

void Enemy::stopLeft(float position)
{
    Position.x = position + EnemySprite.getGlobalBounds().width;    //set new position for X coordinate
    EnemySprite.setPosition(Position);
    LeftMoving = false;
    RightMoving = true;
}

void Enemy::stopRight(float position)
{
    Position.x = position - EnemySprite.getGlobalBounds().width;    //set new position for X coordinate
    EnemySprite.setPosition(Position);
    RightMoving = false;
    LeftMoving = true;
}

Vector2f & Enemy::GetAXIS()
{
    return Position;                        //get X and Y coordinates
}

