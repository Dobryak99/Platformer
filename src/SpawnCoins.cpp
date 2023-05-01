#include "Engine.hpp"

void Engine::SpawnCoins()
{
    for(int i = 0; i < LM.getCoinNumber(); i++)
    {
        Coins.push_back(CoinSprite);
        Coins[i].setPosition(LM.getCoinPosition()[i]);
    }
}
