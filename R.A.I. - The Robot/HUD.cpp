#include "Engine.hpp"

void Engine::HUD()
{
    if(MainMenu)
    {
        //set title sprite
        TitleSprite.setPosition(Vector2f(engine_window.getSize().x / 2 - TitleSprite.getGlobalBounds().width / 2, 200));
        
        //set button on the center of the screen
        PlayButton.setPosition(Vector2f( (engine_window.getSize().x / 2) - PlayButton.getPosition().width / 2, (engine_window.getSize().y / 2) - PlayButton.getPosition().height / 2) );
        PlayButton.setSize(100);
        PlayButton.setText("PLAY");
        
         CreditButton.setPosition(Vector2f(engine_window.getSize().x / 2 - CreditButton.getPosition().width / 2, engine_window.getSize().y / 2 - CreditButton.getPosition().height / 2 + 100) );
        CreditButton.setSize(80);
        CreditButton.setText("CREDIT");
        
        //set button on the center of X coordinate and a little lower of Y coordinate
        QuitButton.setPosition(Vector2f( (engine_window.getSize().x / 2) - QuitButton.getPosition().width / 2, (engine_window.getSize().y / 2) - QuitButton.getPosition().height / 2 + 200 ) );
        QuitButton.setSize(80);
        QuitButton.setText("QUIT");
        
        RestartButton.setPosition(Vector2f(-1000, -1000));                  //hide button
        ReturnToMainMenuButton.setPosition(Vector2f(-1000, -1000));         //hide button
        ResumeButton.setPosition(Vector2f(-1000, -1000));                   //hide button
        Credits.setPosition(Vector2f(-1000, -1000));                        //hide button
    }
    
    if(IsPlaying)
    {
        PlayButton.setPosition(Vector2f(-1000, -1000));         //hide button
        QuitButton.setPosition(Vector2f(-1000, -1000));         //hide button
        ResumeButton.setPosition(Vector2f(-1000, -1000));       //hide button
        CreditButton.setPosition(Vector2f(-1000, -1000));       //hide button
        
        
        stringstream ssScore;
        ssScore << Score;
        ScoreButton.setSize(60);
        ScoreButton.setText("Score: " + ssScore.str());
        
        Vector2f posHeart;
        Vector2f posScore;
        
        //add hearts to array
        for(int i = 0; i < Player.getHealth(); i++)     //GetHealth can change, because player collide with the enemy
        {
            Hearts.push_back(HeartSprite);              //Add heart
            
            //if Player's coordinate X less than half of the screen
            // or Player's coordinate Y greater than 0 or less/equal than 0
            if(Player.getAXIS().x < engine_window.getSize().x / 2 || Player.getAXIS().y > 0 || Player.getAXIS().y <= 0)
            {
                posHeart.x = i * 60 + 30;
                posHeart.y = 50;
                posScore.x = 30;
                posScore.y = 90;
            }
            //if Player's coordinate X greater than Level size - half size of the screen
            if(Player.getAXIS().x > LM.getLevelSize().x * TILE_SIZE - engine_window.getSize().x / 2)
            {
                posHeart.x = i * 60 + 30 +(LM.getLevelSize().x * TILE_SIZE - engine_window.getSize().x);
                posHeart.y = 50;
                posScore.x = 30 + (LM.getLevelSize().x * TILE_SIZE - engine_window.getSize().x);
                posScore.y = 90;
            }
            // if Player's position between start and end
            if(Player.getAXIS().x > engine_window.getSize().x / 2 && Player.getAXIS().x < LM.getLevelSize().x * TILE_SIZE - engine_window.getSize().x / 2)
            {
                posHeart.x = i * 60 + 30 + (Player.getAXIS().x - engine_window.getSize().x / 2);
                posHeart.y = 50;
                posScore.x = 30 + (Player.getAXIS().x - engine_window.getSize().x / 2);
                posScore.y = 90;
            }
            Hearts[i].setPosition(posHeart);       //set it's position
        }
        ScoreButton.setPosition(posScore);
        Hearts.clear();         //without this line leak of memory
    }
    
    if(GameOver)
    {
        //set the button on the center of the screen
        RestartButton.setPosition(Vector2f( (engine_window.getSize().x / 2) - RestartButton.getPosition().width / 2, (engine_window.getSize().y / 2) - RestartButton.getPosition().height / 2) );
        RestartButton.setSize(100);
        RestartButton.setText("RESTART");
        
        //set button on the center of X coordinate and a little lower of Y coordinate
        ReturnToMainMenuButton.setPosition(Vector2f( (engine_window.getSize().x / 2) - ReturnToMainMenuButton.getPosition().width / 2, (engine_window.getSize().y / 2) - ReturnToMainMenuButton.getPosition().height / 2 + 100 ) );
        ReturnToMainMenuButton.setSize(80);
        ReturnToMainMenuButton.setText("MAIN MENU");
    }
    
    if(IsPaused)
    {
        ResumeButton.setPosition(Vector2f( (engine_window.getSize().x / 2) - ResumeButton.getPosition().width / 2, (engine_window.getSize().y / 2) - ResumeButton.getPosition().height / 2) );
        ResumeButton.setSize(100);
        ResumeButton.setText("RESUME");
        
        ReturnToMainMenuButton.setPosition(Vector2f( (engine_window.getSize().x / 2) - ReturnToMainMenuButton.getPosition().width / 2, (engine_window.getSize().y / 2) - ReturnToMainMenuButton.getPosition().height / 2 + 100 ) );
        ReturnToMainMenuButton.setSize(80);
        ReturnToMainMenuButton.setText("MAIN MENU");
    }
    
    if(LoadNextLevel)
    {
        Loading.setPosition( Vector2f( (engine_window.getSize().x / 2) - Loading.getPosition().width / 2 , (engine_window.getSize().y / 2) - Loading.getPosition().height / 2) );
        Loading.setSize(100);
        Loading.setText("Loading...");
    }
    
    if(CreditMenu)
    {
        PlayButton.setPosition(Vector2f(-1000, -1000));         //hide button
        QuitButton.setPosition(Vector2f(-1000, -1000));         //hide button
        CreditButton.setPosition(Vector2f(-1000, -1000));       //hide button
        
        Credits.setPosition(Vector2f((engine_window.getSize().x / 2) - Credits.getPosition().width / 2, (engine_window.getSize().y / 2) - Credits.getPosition().height / 2 - 100));
        Credits.setSize(30);
        Credits.setText("All the sounds and music created by:\n-jobromedia\n-Ogrebane\n-Dklon\n-Sauer2\n-Jalastram\n-den_yes\n-Jkjkke\n-Hitctrl");
        
        ReturnToMainMenuButton.setPosition(Vector2f( (engine_window.getSize().x / 2) - ReturnToMainMenuButton.getPosition().width / 2, (engine_window.getSize().y / 2) - ReturnToMainMenuButton.getPosition().height / 2 + 200 ) );
        ReturnToMainMenuButton.setSize(80);
        ReturnToMainMenuButton.setText("MAIN MENU");
    }
}
