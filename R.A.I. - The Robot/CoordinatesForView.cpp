#include "Engine.hpp"

void Engine::CoordinatesForView(Vector2f coord)
{
    if(IsPlaying)
    {
        if(coord.x < engine_window.getSize().x / 2)     // if coord X of the player < half of the screen
        {
            coord.x = 0 + engine_window.getSize().x / 2;    //set view coord X half of the screen
        }
        if(coord.x > LM.getLevelSize().x * TILE_SIZE - engine_window.getSize().x / 2)
        {
            coord.x = LM.getLevelSize().x * TILE_SIZE - engine_window.getSize().x / 2;
        }
        if(coord.y > 0)                                 //if coord Y of the player > 0
        {
            coord.y =  engine_window.getSize().y / 2;   //set view coord Y half of the screen
        }
        if(coord.y <= 0)                                //if coord Y of the player <= 0
        {
            coord.y =  engine_window.getSize().y / 2;   //set view coord Y half of the screen
            Player.stopJumping();                       //player stops jumping
        }
        GameView.setCenter(coord);
    }
    if(MainMenu)
    {
        MainMenuView.setCenter(coord.x / 2, coord.y / 2);
    }
    if(GameOver)
    {
        GameOverView.setCenter(coord.x / 2, coord.y / 2);
    }
    if(IsPaused)
    {
        PauseView.setCenter(coord.x / 2, coord.y / 2);
    }
    if(LoadNextLevel)
    {
        LoadNextLevelView.setCenter(coord.x / 2, coord.y / 2);
    }
    if(CreditMenu)
    {
        CreditMenuView.setCenter(coord.x / 2, coord.y / 2);
    }
}
