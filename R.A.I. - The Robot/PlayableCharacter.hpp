#pragma once

#ifndef PlayableCharacter_hpp
#define PlayableCharacter_hpp

#include <SFML/Graphics.hpp>
#include "TextureManager.hpp"
#include "SoundManager.hpp"
#include "RESOURCES.h"

using namespace sf;

class PlayableCharacter
{
private:
    float Speed = 400.f;                            //Speed of the player
    float Gravity;                                  //Player's gravity
    float jumpDuration;                             //Player's jump duration
    float TimeOfJump;                               //How long is the player jumping at the moment
    int Health;                                     //health of the player
    const int MAXHEALTH = 3;                        //Max health of the player
    float playerCurrentFrame = 0;                   //current player's texture frame
    Vector2f Position;                              //Player's position
    Texture CharacterTextureStill;                  //Texture when player don't move
    Texture CharacterTextureRun;                    //Texture when player move right
    Sprite CharacterSprite;                         //Sprite
    Sound JumpSound;                                //Jump sound of the player
    Sound DeathSound;                               //Death sound
    FloatRect Feet;                                 // rect of the Feet to detect collision with the block
    FloatRect Head;                                 // rect of the head to detect collision with the block
    FloatRect RightSide;                            // rect of the right side  to detect collision with the block
    FloatRect LeftSide;                             // rect of theleft side to detect collision with the block
    bool IsJumped = false;                          //has the player just jumped
    bool IsFalling = true;                          //is the player falling
    bool RightPressed;                              //is the player moving right
    bool LeftPressed;                               //is the player moving left
    bool isOnEnemyHead = false;                     //is the player on enemy's head?
public:
    PlayableCharacter();                            //constructor
    void spawn(Vector2f & position, float gravity); //spawn function
    void handleInput();                             //how to manipulate the player
    void update(float & dt);                        //update function
    void Damage();                                  //subrtact health point
    void HealthUp();                                //plus one health point
    void stopLeft(float position);                  //stop moving left
    void stopRight(float position);                 //stop moving right
    void stopFalling(float position);               //stop moving down
    void stopJumping();                             //stop moving up
    void Bounce();                                  //player bounce from enemy's head
    int getHealth();                                //get player's health
    void resetHealth();                             //reset player's health after death or after complete all levels
    void PlayDeathSound();                          //Play death sound
    FloatRect & getFeet();                          //get rect of the feet
    FloatRect & getHead();                          //get rect of the Head
    FloatRect & getRight();                         //get rect of the right side
    FloatRect & getLeft();                          //get rect of the left side
    FloatRect getPosition();                        //get player's global bounds
    Sprite & getSprite();                           //get player's sprite
    Vector2f getAXIS();                             //get player's X and Y
};

#endif /* PlayableCharacter_hpp */
