#include "Engine.hpp"

void Engine::SpawnEnemies()
{
    for(int i = 0 ; i < LM.getEnemyNumber(); i++)
    {
        Enemies.push_back(enemy);
        Enemies[i].Spawn(LM.getEnemyStartPosition()[i], GRAVITY);
    }
}
