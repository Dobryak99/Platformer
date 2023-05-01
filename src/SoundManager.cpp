#include "SoundManager.hpp"

SoundManager * SoundManager::SM_Instance = nullptr;

SoundManager::SoundManager()
{
    assert(SM_Instance == nullptr);
    SM_Instance = this;
}

SoundBuffer & SoundManager::getSoundBuffer(const std::string &filename)
{
    //get a reference to SoundBuffers
    auto & s = SM_Instance -> SoundBuffers;
    
    //Create an iterator to hold a key-value-pair(kvp)
    // and seacrh for the required kvp
    // using the passed in file name
    auto KeyValuePair = s.find(filename);
    
    if(KeyValuePair != s.end())
    {
        return KeyValuePair -> second;
    }else{
        auto & sound = s[filename];
        sound.loadFromFile(filename);
        return sound;
    }
}
