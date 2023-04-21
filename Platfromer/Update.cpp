#include "Engine.hpp"

void Engine::Update(float & dtAsSeconds)
{
    if(NewLevelRequired)
    {
        LoadLevel();
    }
    if(MainMenu)
    {
        CoordinatesForView(resolution);
        HUD();
    }
    if(GameOver)
    {
        CoordinatesForView(resolution);
        HUD();
    }
    if(IsPaused)
    {
        CoordinatesForView(resolution);
        HUD();
    }
    if(LoadNextLevel)
    {
        if(waitTime < 2)
        {
            IsPlaying = false;                          //stop playing
            waitTime += dtAsSeconds;                    // add time
            CoordinatesForView(resolution);             // set view coordinates
            HUD();                                      // draw hud
        }else{
            waitTime = 0;                               //set time to 0
            IsPlaying = true;                           // play again
            LoadNextLevel = false;                      // stop loading level
        }
    }
    if(IsPlaying)
    {
        Player.update(dtAsSeconds);
        CoordinatesForView(Player.getAXIS());           //set view center
        UpdateCoins(dtAsSeconds);                       //animating coins
        UpdateHearts(dtAsSeconds);                      //animate hearts
        
        for(int i = 0; i < LM.getEnemyNumber(); i++)
        {
            Enemies[i].update(dtAsSeconds);
        }
        
        HUD();
        DetectCollision();
    }
}
