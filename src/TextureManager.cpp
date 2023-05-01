#include "TextureManager.hpp"
#include <assert.h>

TextureManager * TextureManager::TM_Instance = nullptr;

TextureManager::TextureManager()
{
    assert(TM_Instance == nullptr);
    TM_Instance = this;
}

Texture & TextureManager::GetTexture(const string &filename)
{
    //get a reference to TM_Textures
    auto & m = TM_Instance -> TM_Textures;
    
    //Create an iterator to hold a key-value-pair(kvp)
    // and seacrh for the required kvp
    // using the passed in file name
    auto KeyValuePair = m.find(filename);
    
    if(KeyValuePair != m.end())
    {
        return KeyValuePair -> second;
    }else{
        auto & texture = m[filename];
        texture.loadFromFile(filename);
        return texture;
    }
}
