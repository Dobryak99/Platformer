#include "Engine.hpp"

void Engine::LoadLevel()
{
    //Delete the previous level(if exist)
    for(int i = 0; i < LM.getLevelSize().y; i++)
    {
        delete [] arrayLevel[i];
    }
    delete [] arrayLevel;
    
    Enemies.clear();                                //Clear array of enemies
    LM.getEnemyStartPosition().clear();             //Clear array of enemies' positions
    LM.setEnemyNumber(0);                           //clear number of enemies on the level
    Coins.clear();                                  //clear array of coins
    LM.getCoinPosition().clear();                   //clear array of coins' position
    LM.setCoinNumber(0);                            //clear number of coins on the level
    CollectableHearts.clear();                      //Clear array of hearts
    LM.getHeartPosition().clear();                  //Clear array of hearts' positions
    LM.setHeartNumber(0);                           //clear number of coins on the level
    
    if(GameOver)                                    //if Player was killed
    {
        IsPlaying = false;                          //stop playing
        LM.setCurrentLevel(0);                      //Set level number 0
        Player.resetHealth();                       //reset Player's health
        Score = 0;                                  //reset score
    }
    
    
    arrayLevel = LM.createLevel(VALevel);           //create level
    
    Player.spawn(LM.getStartPosition() , GRAVITY);  //spawn player
    
    SpawnCoins();                                   //spawn coins
    
    SpawnHearts();                                  //Spawn hearts
    
    SpawnEnemies();                                 //Spawn enemies
    
    NewLevelRequired = false;
}
