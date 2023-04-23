#include "Engine.hpp"

void Engine::DetectCollision()
{
    FloatRect block;                // Create a Rect for block to detect collision
    block.width = TILE_SIZE;
    block.height = TILE_SIZE;
    
    // Check blocks around player for collision
    for(int y = Player.getPosition().top / TILE_SIZE;y < (Player.getPosition().top + Player.getPosition().height) / TILE_SIZE; y++)
    {
        for(int x = Player.getPosition().left / TILE_SIZE;x < (Player.getPosition().left + Player.getPosition().width) / TILE_SIZE; x++)
            {
                block.left = x * TILE_SIZE; // X coordinate of the block( every 50 pixel new block)
                block.top = y * TILE_SIZE;  // Y coordinate of the block( every 50 pixel new block)
                
                if(arrayLevel[y][x] == '1' || arrayLevel[y][x] == '2') // Collide with the block
                {
                    if(Player.getPosition().intersects(block))          // Player collide with the block
                    {
                        if(Player.getFeet().intersects(block))          // Feet rect collide with the block
                        {
                            Player.stopFalling(block.top);
                        }
                        if(Player.getRight().intersects(block))         // Right rect collide with the block
                        {
                            Player.stopRight(block.left);
                        }
                        if(Player.getLeft().intersects(block))          // Left rect collide with the block
                        {
                            Player.stopLeft(block.left);
                        }
                        if(Player.getHead().intersects(block))          // Head rect collide with the block
                        {
                            Player.stopJumping();
                        }
                    }
                }
                if(arrayLevel[y][x] == '4' || arrayLevel[y][x] == '7')     // if player reached goal
                {
                    if(Player.getPosition().intersects(block))
                    {
                        if(LM.getCurrentLevel() < LM.getMaxLevel() && IsPlaying)     // current level should be less than max level 
                        {
                            LoadNextLevel = true;       //load new level
                            NewLevelRequired = true;    //New level load
                        }else{
                            LoadNextLevel = false;      //stop loading levels
                            IsPlaying = false;          //stop playing
                            MainMenu = true;            //return to main menu
                            LM.setCurrentLevel(0);      //set level number to 0
                            Player.resetHealth();       //reset player's health
                            Score = 0;                  //reset score
                        }
                    }
                }
                if(arrayLevel[y][x] == '5' || arrayLevel[y][x] == '6')             //if player collide with spikes
                {
                    if(Player.getFeet().intersects(block) || Player.getHead().intersects(block))
                    {
                        if(Player.getHealth() > 1)      //if player's health greater than 1
                        {
                            Player.spawn(LM.getStartPosition(), GRAVITY);   //spawn player at the start of the level
                            Player.Damage();            // -1 HP
                            
                        }else{                          // Player dies
                            GameOver = true;            //return to game over menu
                            NewLevelRequired = true;    //new level should be loaded
                        }
                    }
                }
            }
    }
    
    //Enemy Collision with the block
    for(int i = 0; i < LM.getEnemyNumber(); i++)
    {
        //Check blocks around enemies
        for(int y = Enemies[i].getPosition().top / TILE_SIZE; y < (Enemies[i].getPosition().top + Enemies[i].getPosition().height) / TILE_SIZE; y++)
        {
            for(int x = Enemies[i].getPosition().left / TILE_SIZE; x < (Enemies[i].getPosition().left + Enemies[i].getPosition().width) / TILE_SIZE; x++)
            {
                block.left = x * TILE_SIZE; // X coordinate of the block( every 50 pixel new block)
                block.top = y * TILE_SIZE;  // Y coordinate of the block( every 50 pixel new block)
                
                if(arrayLevel[y][x] == '1' || arrayLevel[y][x] == '2' || arrayLevel[y][x] == '5' || arrayLevel[y][x] == '6') // Collide with the grass
                {
                    if(Enemies[i].getPosition().intersects(block))  // Enemy collide with the block
                    {
                        if(Enemies[i].getFeet().intersects(block))  // Feet rect collide with the grass
                        {
                            Enemies[i].stopFalling(block.top);
                        }
                        if(Enemies[i].getLeft().intersects(block))  // Right rect collide with the grass
                        {
                            Enemies[i].stopLeft(block.left);
                        }
                        if(Enemies[i].getRight().intersects(block)) // Left rect collide with the grass
                        {
                            Enemies[i].stopRight(block.left);
                        }
                    }
                }
            }
        }
        if(Player.getPosition().intersects(Enemies[i].getPosition()))       // Player intersects enemy
        {
            // if Player's feet collide with the enemy's head
            if(Player.getFeet().intersects(Enemies[i].getHead()))
            {
                Player.Bounce();    // Player make a small jump
                Enemies.erase(Enemies.begin() + i);         // Enemy dies
                LM.setEnemyNumber(static_cast<int>(Enemies.size()));          // Change the number of enemies on the level
                Score += 20;                                // +20 points
            }
            //if Player's side  or head collide with the enemy's side
            if( Player.getRight().intersects(Enemies[i].getLeft()) || Player.getLeft().intersects(Enemies[i].getRight()) || Player.getHead().intersects(Enemies[i].getFeet()) || Player.getPosition().intersects(Enemies[i].getBody()) )
            {
                
                if(Player.getHealth() > 1)      //if player's health greater than 1
                {
                    Player.spawn(LM.getStartPosition(), GRAVITY);   //spawn player at the start of the level
                    Player.Damage();            // -1 HP
                    
                }else{                          // Player dies
                    GameOver = true;            //return to game over menu
                    NewLevelRequired = true;    //new level should be loaded
                }
            }
        }
    }
     
    
    for(int i = 0; i < LM.getCoinNumber(); i++)         //Collision with the coins
    {
        if(Player.getPosition().intersects(Coins[i].getGlobalBounds()))         //Player collide with the coin
        {
            Coins.erase(Coins.begin() + i);                                     // coin disappear
            LM.setCoinNumber(static_cast<int>(Coins.size()));                   // set new coin number on the level
            Score += 10;                                                        // +10 points
        }
    }
    
    for(int i = 0; i < LM.getHeartNumber(); i++)        //Collision with the collectable hearts
    {
        if(Player.getPosition().intersects(CollectableHearts[i].getGlobalBounds()))
        {
            CollectableHearts.erase(CollectableHearts.begin() + i);             //Heart disappear
            LM.setHeartNumber(static_cast<int>(CollectableHearts.size()));      //set new number of hearts on the level
            Player.HealthUp();                                                  // +1 HP
            Score += 5;                                                         // + 5 points
        }
    }
    
    // Collision between enemies
    for(int i = 0; i < LM.getEnemyNumber(); i++)
    {
        for(int j = 0; j < LM.getEnemyNumber(); j++)
        {
            if(Enemies[j].getPosition().intersects(Enemies[i].getPosition()))
            {
                
                if(Enemies[j].getRight().intersects(Enemies[i].getLeft()))
                {
                    Enemies[j].stopRight(Enemies[i].getLeft().left);
                    Enemies[i].stopLeft(Enemies[j].getRight().left - Enemies[i].getPosition().width);
                }
                
                if(Enemies[j].getLeft().intersects(Enemies[i].getRight()))
                {
                    Enemies[j].stopLeft(Enemies[i].getRight().left - Enemies[i].getPosition().width);
                    Enemies[i].stopRight(Enemies[j].getLeft().left);
                }
            }
        }
    }
     

    //if Player reach one of the side of the map, than Player can't go to that direction
    // Left side of the map(screen)
    if(Player.getAXIS().x < 0)
    {
        Player.stopLeft(0 - Player.getPosition().width);
    }
        
    // Right side of the map(screen)
    if(Player.getAXIS().x > LM.getLevelSize().x * TILE_SIZE - Player.getPosition().width)
    {
        Player.stopRight(LM.getLevelSize().x * TILE_SIZE);
    }
    
    //if enemy reach one of the side of the map, than enemy should go to the opposite direction
    // The same for the enemies
    for(int i = 0; i < LM.getEnemyNumber(); i++)
    {
        if(Enemies[i].GetAXIS().x < 0)
        {
            Enemies[i].stopLeft(0 - Enemies[i].getPosition().width);
        }
        if(Enemies[i].GetAXIS().x > LM.getLevelSize().x * TILE_SIZE - Enemies[i].getPosition().width)
        {
            Enemies[i].stopRight(LM.getLevelSize().x * TILE_SIZE);
        }
    }
}
