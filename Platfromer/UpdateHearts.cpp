#include "Engine.hpp"

void Engine::UpdateHearts(float dt)
{
    heartCurrentFrame += dt * 10;
    
    if(heartCurrentFrame > 4)
    {
        heartCurrentFrame = 0;
    }
    
    for(int i = 0; i < CollectableHearts.size(); i++)
    {
        CollectableHearts[i].setTextureRect(IntRect(0, 0 + TILE_SIZE * static_cast<int>(heartCurrentFrame), TILE_SIZE, TILE_SIZE));
    }
}
