#include "Engine.hpp"

void Engine::UpdateCoins(float dt)
{
    coinCurrentFrame += dt * 10;
    if(coinCurrentFrame > 4)
    {
        coinCurrentFrame = 0;
    }
    for(int i = 0; i < Coins.size(); i++)
    {
        Coins[i].setTextureRect(IntRect(TILE_SIZE * static_cast<int>(coinCurrentFrame), 0, TILE_SIZE, TILE_SIZE));
    }
}
