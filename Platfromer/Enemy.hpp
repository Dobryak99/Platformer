#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include "RESOURCES.h"
#include "TextureManager.hpp"

using namespace sf;

class Enemy
{
private:
    float Speed = 150.f;                            // Enemy speed
    float Gravity;                                  // Enemy Garvity
    float currentEnemyFrame = 0;                    // current enemy texture frame
    Vector2f Position;                              //Enemy Position
    Texture EnemyTexture;                           //Enemy Texture
    Sprite EnemySprite;                             // Enemy Sprite
    FloatRect Feet;                                 // rect of the Feet to detect collision with the block
    FloatRect Head;                                 // rect of the head to detect collision with the block and player
    FloatRect RightSide;                            // rect of the right side  to detect collision with the block and player
    FloatRect LeftSide;                             // rect of the left side to detect collision with the block and player
    FloatRect Body;                                 // rect of the body to detect collision with the player
    bool IsFalling = true;                          //is the enemy falling?
    bool LeftMoving = false;                        //enemy moving to the right
    bool RightMoving = false;                       //enemy moving to the right
public:
    Enemy();                                        //Constructor
    void Spawn(Vector2f & position, float gravity); //spawn enemy
    void update(float & dt);                          //update enemy
    FloatRect & getFeet();                            //get rect of the feet
    FloatRect & getHead();                            //get rect of the Head
    FloatRect & getRight();                           //get rect of the right side
    FloatRect & getLeft();                            //get rect of the left side
    FloatRect & getBody();                            //get rect of the body
    FloatRect getPosition();                        //get enemy's global bounds
    Sprite & getSprite();                             //get enemy's sprite
    void stopFalling(float position);               //stop moving down
    void stopRight(float position);                 //stop moving right
    void stopLeft(float position);                  //stop moving left
    Vector2f & GetAXIS();                             //get enemy's X and Y coordinates
};
