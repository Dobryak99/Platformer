#pragma once

#ifndef Engine_hpp
#define Engine_hpp

#include <SFML/Graphics.hpp>
#include "RESOURCES.h"
#include "TextureManager.hpp"
#include "SoundManager.hpp"
#include "LevelManager.hpp"
#include "PlayableCharacter.hpp"
#include "Enemy.hpp"
#include "Button.hpp"
#include <iostream>
#include <sstream>

using namespace sf;
using namespace std;

class Engine
{
private:
    //Boolean
    bool IsPlaying = false;
    bool IsPaused = false;
    bool MainMenu = true;
    bool NewLevelRequired = false;
    bool GameOver = false;
    bool LoadNextLevel = false;
    bool CreditMenu = false;
    
    //Variables
    const float TILE_SIZE = 32.0f;
    const float VERTS_IN_QUAD = 4.0f;
    const int GRAVITY = 600;
    float coinCurrentFrame = 0;         //current frame of the coin
    float heartCurrentFrame = 0;        //current frame of the heart
    float waitTime = 0.0f;
    int Score = 0;
    stringstream ssScore;
    
    //Window
    RenderWindow engine_window;
    
    //resolution
    Vector2f resolution;
    
    //Texture manager instance
    TextureManager TM;
    
    //SoundBuffer manager instance
    SoundManager SM;
    
    //Level manager instance
    LevelManager LM;
    
    //Player
    PlayableCharacter Player;
    
    //Mouse
    Vector2i mousePos;                      //Position of the mouse on the screen
    FloatRect mouseRect;                    //invisible rect of the mouse position to detect collision
    
    //Enemies
    Enemy enemy;
    std::vector<Enemy> Enemies;
    
    //Buttons
    Button PlayButton;
    Button QuitButton;
    Button RestartButton;
    Button ReturnToMainMenuButton;
    Button ResumeButton;
    Button CreditButton;
    Button ScoreButton;                     // Non-clickable
    Button Loading;                         // Non-clickable
    Button Credits;                         // Non-clickable
    
    //Sounds
    Sound CollectCoinSound;
    Sound CollectHeartSound;
    Sound EnemyDeathSound;
    Sound ReachedGoalSound;
    Sound ButtonClickSound;
    
    //Music
    Music MainMenuMusic;
    Music GameMusic;
    
    //Views
    View MainMenuView;
    View GameView;
    View GameOverView;
    View PauseView;
    View LoadNextLevelView;
    View CreditMenuView;
    
    
    /*======================
       Textures and Sprites
     ======================*/
    
    //Texture for backgrounds
    Texture MainMenuBackgroundTexture;
    Texture GameBackgroundTexture;
    Texture GameCaveBackgroundTexture;
    Texture LoadNewLeveltexture;
    Texture Playertexture;
    Texture Title;
    
    //Tiles Texture
    Texture tileTexture;
    
    //Texture for Heart
    Texture HeartTexture;
    
    Texture CollectableHeartTexture;
    
    //texture for coin
    Texture CoinTexture;
    
    //Sprite for the background textures
    Sprite MainMenuBackgroundSprite;
    Sprite GameBackgroundSprite;
    Sprite GameCaveBackgroundSprite;
    
    //Othe sprites
    Sprite LoadNewLevelSprite;
    Sprite TitleSprite;
    
    //array of Sprites for hearts to display palyer's health
    Sprite HeartSprite;
    std::vector<Sprite> Hearts;
    
    //array of sprites for collectable hearts
    Sprite CollectableHeartSprite;
    std::vector<Sprite> CollectableHearts;
    
    //Array of sprites for coins
    Sprite CoinSprite;
    std::vector<Sprite> Coins;
    
    //Time
    Time TotalGameTime;
    
    //2D map array
    char ** arrayLevel = nullptr;
    
    //Vertex array to draw level
    VertexArray VALevel;
    
    /*======================
            Functions
     ======================*/
    
    //load level function
    void LoadLevel();
    
    //Collision Detection function
    void DetectCollision();
    
    //Set coordinates for View
    void CoordinatesForView(Vector2f coord);
    
    //Set Buttons on the screen
    void HUD();
    
    void SpawnEnemies();
    void SpawnCoins();
    void SpawnHearts();
    void UpdateCoins(float dt);
    void UpdateHearts(float dt);
    
    
    void Input();
    void Draw();
    void Update(float & dtAsSeconds);
    
    
public:
    Engine();
    void run();    
};

#endif /* Engine_hpp */
