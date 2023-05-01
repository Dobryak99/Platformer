#pragma once

#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

using namespace sf;
using namespace std;

class TextureManager
{
private:
    map<string, Texture> TM_Textures;
    
    static TextureManager * TM_Instance;
public:
    TextureManager();
    static Texture & GetTexture(const string & filename);    
};

#endif

