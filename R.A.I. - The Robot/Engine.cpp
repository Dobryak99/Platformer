#include "Engine.hpp"

Engine::Engine()
{
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    engine_window.create(VideoMode(resolution.x, resolution.y), "My Game", Style::Fullscreen);
    
    //Set View
    GameView.setSize(resolution);
    MainMenuView.setSize(resolution);
    GameOverView.setSize(resolution);
    PauseView.setSize(resolution);
    LoadNextLevelView.setSize(resolution);
    
    //Load background texture
    MainMenuBackgroundTexture = TextureManager::GetTexture(BACKGROUND_TEXTURE);
    MainMenuBackgroundTexture.setRepeated(true);
    MainMenuBackgroundSprite.setTextureRect(IntRect(0,0,1280 * 2, 800));
    MainMenuBackgroundSprite.setTexture(MainMenuBackgroundTexture);
    
    GameBackgroundTexture = TextureManager::GetTexture(BACKGROUND_GAME_TEXTURE);
    GameBackgroundTexture.setRepeated(true);
    GameBackgroundSprite.setTextureRect(IntRect(0,0,1280 * 5, 800 ));
    GameBackgroundSprite.setTexture(GameBackgroundTexture);
    
    GameCaveBackgroundTexture = TextureManager::GetTexture(BACKGROUND_CAVE_TEXTURE);
    GameCaveBackgroundTexture.setRepeated(true);
    GameCaveBackgroundSprite.setTextureRect(IntRect(0,0,1280 * 5, 800));
    GameCaveBackgroundSprite.setTexture(GameCaveBackgroundTexture);
    
    LoadNewLeveltexture = TextureManager::GetTexture(LOAD_NEW_LEVEL_TEXTURE);
    LoadNewLevelSprite.setTexture(LoadNewLeveltexture);
    
    //Load heart texture
    HeartTexture = TextureManager::GetTexture(HEART_TEXTURE);
    HeartSprite.setTexture(HeartTexture);
    
    //Load collectable heart texture
    CollectableHeartTexture = TextureManager::GetTexture(COLLECTABLE_HEART_TEXTURE);
    CollectableHeartSprite.setTexture(CollectableHeartTexture);
    
    //Load Coin texture
    CoinTexture = TextureManager::GetTexture(COIN_TEXTURE);
    CoinSprite.setTexture(CoinTexture);
    
    tileTexture = TextureManager::GetTexture(TILE_SHEET_TEXTURE);
    
    //Sounds
    CollectCoinSound.setBuffer(SoundManager::getSoundBuffer(COLLECT_COIN_SOUND));
    CollectHeartSound.setBuffer(SoundManager::getSoundBuffer(COLLECT_HEART_SOUND));
    EnemyDeathSound.setBuffer(SoundManager::getSoundBuffer(ENEMY_DEATH_SOUND));
    ReachedGoalSound.setBuffer(SoundManager::getSoundBuffer(NEW_LEVEL_SOUND));
    ReachedGoalSound.setVolume(25);
    ButtonClickSound.setBuffer(SoundManager::getSoundBuffer(CLICK_SOUND));
    
    //Music
    MainMenuMusic.openFromFile(MAIN_MENU_MUSIC);
    MainMenuMusic.setLoop(true);
    MainMenuMusic.setVolume(25);
    
    GameMusic.openFromFile(GAME_MUSIC);
    GameMusic.setLoop(true);
    GameMusic.setVolume(25);
}

void Engine::run()
{
    MainMenuMusic.play();                                                   //playing main menu music
    Clock clock;
    while(engine_window.isOpen())
    {
        mousePos = Mouse::getPosition(engine_window);                        //get mouse position
        mouseRect = FloatRect(mousePos.x, mousePos.y, 1,1);                  //set rect to mouse pos with width and height = 1
        Time dt = clock.restart();
        float dtAsSeconds = dt.asSeconds();
        TotalGameTime += dt;
        Input();
        Update(dtAsSeconds);
        Draw();
    }
    
}
