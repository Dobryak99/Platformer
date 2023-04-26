#include "Engine.hpp"

void Engine::SpawnHearts()
{
    for(int i = 0; i < LM.getHeartNumber(); i++)
    {
        CollectableHearts.push_back(CollectableHeartSprite);
        CollectableHearts[i].setPosition(LM.getHeartPosition()[i]);
    }
}
