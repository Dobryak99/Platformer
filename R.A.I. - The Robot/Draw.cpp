#include "Engine.hpp"

void Engine::Draw()
{
    engine_window.clear();
    
    //if the player in the main menu
    if(MainMenu)
    {
        engine_window.setMouseCursorVisible(true);          //reveal cursor
        engine_window.setView(MainMenuView);
        engine_window.draw(MainMenuBackgroundSprite);
        engine_window.draw(PlayButton.getText());
        engine_window.draw(QuitButton.getText());
        engine_window.draw(CreditButton.getText());
        engine_window.draw(TitleSprite);
    }
    if(GameOver)
    {
        engine_window.setMouseCursorVisible(true);          //reveal cursor
        engine_window.setView(GameOverView);
        engine_window.draw(GameBackgroundSprite);
        engine_window.draw(RestartButton.getText());
        engine_window.draw(ReturnToMainMenuButton.getText());
    }
    if(IsPaused)
    {
        engine_window.setMouseCursorVisible(true);          //reveal cursor
        engine_window.setView(PauseView);
        engine_window.draw(GameBackgroundSprite);
        engine_window.draw(ResumeButton.getText());
        engine_window.draw(ReturnToMainMenuButton.getText());
    }
    
    if(LoadNextLevel)
    {
        engine_window.setView(LoadNextLevelView);
        engine_window.draw(LoadNewLevelSprite);
        engine_window.draw(Loading.getText());
    }
    
    if(CreditMenu)
    {
        engine_window.setView(CreditMenuView);
        engine_window.draw(GameBackgroundSprite);
        engine_window.draw(ReturnToMainMenuButton.getText());
        engine_window.draw(Credits.getText());
    }
    
    //if the player in the game or in pause menu
    if(IsPlaying)
    {
        engine_window.setMouseCursorVisible(false);         //hide cursor when playing
        if(LM.getCurrentLevel() < 4)
        {
            engine_window.draw(GameBackgroundSprite);
        }else{
            engine_window.draw(GameCaveBackgroundSprite);
        }
        engine_window.draw(VALevel, &tileTexture);
        
        
        for(int i = 0; i < Player.getHealth(); i++)
        {
            engine_window.draw(Hearts[i]);
        }
         
        
        for(int i = 0; i < LM.getCoinNumber(); i++)
        {
            engine_window.draw(Coins[i]);
        }
        
        for(int i = 0; i < LM.getHeartNumber(); i++)
        {
            engine_window.draw(CollectableHearts[i]);
        }
        
        for(int i = 0; i < LM.getEnemyNumber(); i++)
        {
            engine_window.draw(Enemies[i].getSprite());
        }
        
        engine_window.draw(Player.getSprite());
        
        for(int i = 0; i < Player.getHealth(); i++)
        {
            engine_window.draw(Hearts[i]);
        }
        engine_window.draw(ScoreButton.getText());
        engine_window.setView(GameView);
    }
    
    
    engine_window.display();
}
