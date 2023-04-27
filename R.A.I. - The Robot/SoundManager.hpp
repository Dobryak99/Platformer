#ifndef SoundManager_hpp
#define SoundManager_hpp

#include <SFML/Audio.hpp>
#include <assert.h>
#include <map>

using namespace sf;

class SoundManager
{
private:
    std::map<std::string, SoundBuffer> SoundBuffers;
    static SoundManager * SM_Instance;
public:
    SoundManager();
    static SoundBuffer & getSoundBuffer(std::string const & filename );
};

#endif /* SoundManager_hpp */
