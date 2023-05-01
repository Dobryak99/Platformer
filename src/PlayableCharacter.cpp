#include "PlayableCharacter.hpp"

PlayableCharacter::PlayableCharacter()
{
    jumpDuration = 0.2f;
    Health = MAXHEALTH;
    CharacterTextureStill = TextureManager::GetTexture(PLAYER_STILL_SHEET_TEXTURE);
    CharacterTextureRun = TextureManager::GetTexture(PLAYER_RUN_TEXTURE);
    CharacterSprite.setTexture(CharacterTextureStill);
    JumpSound.setBuffer(SoundManager::getSoundBuffer(JUMP_SOUND));
    DeathSound.setBuffer(SoundManager::getSoundBuffer(DEATH_SOUND));
}

void PlayableCharacter::spawn(Vector2f & position, float gravity)
{
    Gravity = gravity;
    Position = position;
    CharacterSprite.setPosition(Position);
    IsFalling = true;
}

void PlayableCharacter::update(float & dt)
{
    CharacterSprite.setTexture(CharacterTextureStill);
    playerCurrentFrame += dt * 10;
    if(playerCurrentFrame > 2)
    {
        playerCurrentFrame = 0;
    }
    CharacterSprite.setTextureRect(IntRect(32 * static_cast<int>(playerCurrentFrame), 0, 32, 50));      //change current frame to animate player
    
    
    if(LeftPressed)
    {
        Position.x -= Speed * dt;
        CharacterSprite.setTexture(CharacterTextureRun);
        playerCurrentFrame += dt * 5;
        if(playerCurrentFrame > 2)
        {
            playerCurrentFrame = 0;
        }
        CharacterSprite.setTextureRect(IntRect(32 * static_cast<int>(playerCurrentFrame) + 32, 0,-32, 50));      //change current frame to animate player
    }
    
    if(RightPressed)
    {
        Position.x += Speed * dt;
        CharacterSprite.setTexture(CharacterTextureRun);
        playerCurrentFrame += dt * 5;
        if(playerCurrentFrame > 2)
        {
            playerCurrentFrame = 0;
        }
        CharacterSprite.setTextureRect(IntRect(32 * static_cast<int>(playerCurrentFrame), 0, 32, 50));      //change current frame to animate player
    }
    if(IsJumped)
    {
        TimeOfJump += dt;
        if(TimeOfJump > jumpDuration)
        {
            IsJumped = false;
            IsFalling = true;
        }else{
            Position.y -= Gravity * dt;
        }
    }
    
    if(isOnEnemyHead)
    {
        TimeOfJump += dt;
        if(TimeOfJump > 0.1f)
        {
            IsJumped = false;
            IsFalling = true;
            isOnEnemyHead = false;
        }else{
            Position.y -= Gravity * dt;
        }
    }
    
    
    
    if(IsFalling)
    {
        Position.y += Gravity * 0.70 * dt;
    }
    
    //Set the rects of the player's sides
    
    FloatRect r = getPosition();    //set r with the player's global bounds
    
    //Feet rect
    Feet.left = r.left + 2;            // X coordinate
    Feet.top = r.top + r.height - 1;   // Y coordinate
    Feet.width = r.width - 4;          // Width of the rectangle
    Feet.height = 1;                    // Height of the rectangle
    
    //Head rect
    Head.left = r.left + 15;
    Head.top = r.top;
    Head.width = r.width - 30;
    Head.height = 1;
    
    //Right side rect
    RightSide.left = r.left + r.width - 1;
    RightSide.top = r.top + (r.height * 0.3f) - 10;
    RightSide.width = 1;
    RightSide.height = (r.height * 0.3f) + 10;
    
    //Left side rect
    LeftSide.left = r.left;
    LeftSide.top = r.top + (r.height * 0.3f) - 10;
    LeftSide.width = 1;
    LeftSide.height = (r.height * 0.3f) + 10;
    
    CharacterSprite.setPosition(Position);
}

void PlayableCharacter::handleInput()
{
    if(Keyboard::isKeyPressed(Keyboard::A))
    {
        LeftPressed = true;
    }else{
        LeftPressed = false;
    }
    
    if(Keyboard::isKeyPressed(Keyboard::D))
    {
        RightPressed = true;
    }else{
        RightPressed = false;
    }
    
    if(Keyboard::isKeyPressed(Keyboard::W))
    {
        if(!IsJumped && !IsFalling)     //not jumping and not falling at the moment
        {
            TimeOfJump = 0;
            IsJumped = true;
            JumpSound.play();
        }
    }else{
        IsJumped = false;
        IsFalling = true;
    }
}

FloatRect & PlayableCharacter::getFeet()
{
    return Feet;
}

FloatRect & PlayableCharacter::getHead()
{
    return Head;
}

FloatRect & PlayableCharacter::getLeft()
{
    return LeftSide;
}

FloatRect & PlayableCharacter::getRight()
{
    return RightSide;
}

FloatRect PlayableCharacter::getPosition()
{
    return CharacterSprite.getGlobalBounds();
}

Sprite & PlayableCharacter::getSprite()
{
    return CharacterSprite;
}

void PlayableCharacter::stopLeft(float position)
{
    Position.x = position + CharacterSprite.getGlobalBounds().width;
    CharacterSprite.setPosition(Position);
}

void PlayableCharacter::stopRight(float position)
{
    Position.x = position - CharacterSprite.getGlobalBounds().width;
    CharacterSprite.setPosition(Position);
}

void PlayableCharacter::stopJumping()
{
    IsJumped = false;
    IsFalling = true;
}

void PlayableCharacter::stopFalling(float position)
{
    Position.y = position - CharacterSprite.getGlobalBounds().height;
    CharacterSprite.setPosition(Position);
    IsFalling = false;
}

Vector2f PlayableCharacter::getAXIS()
{
    return Position;
}

void PlayableCharacter::Bounce()
{
    TimeOfJump = 0;
    isOnEnemyHead = true;
}


int PlayableCharacter::getHealth()
{
    return Health;
}

void PlayableCharacter::Damage()
{
    Health--;
}

void PlayableCharacter::resetHealth()
{
    Health = MAXHEALTH;
}

void PlayableCharacter::HealthUp()
{
    if(Health < MAXHEALTH)
    {
        Health++;
    }
}

void PlayableCharacter::PlayDeathSound()
{
    DeathSound.play();
}
