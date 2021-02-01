//
//  PlayableCharacter.hpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#ifndef PlayableCharacter_h
#define PlayableCharacter_h
#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter {
protected:
    //of course we need a sprite
    Sprite m_Sprite;
    
    //How long does the jump last?
    float m_JumpDuration;
    
    //Is character currently jumping of falling?
    bool m_IsJumping;
    bool m_IsFalling;
    
    //Which directions is the character currently moving in?
    bool m_LeftPressed;
    bool m_RightPressed;
    
    //How long has this jup lasted so far
    float m_TimeThisJump;
    
    //Has the player just initiated the jump?
    bool m_JustJumped = false;
    
    //private variables and functions come next
private:
    //what is the gravity?
    float m_Gravity;
    
    //How fast is the character
    float m_Speed = 400;
    
    //Where is the player
    Vector2f m_Position;
    
    //Where are the character's various body parts?
    FloatRect m_Feet;
    FloatRect m_Head;
    FloatRect m_Right;
    FloatRect m_Left;
    
    // Add a texture
    Texture m_Texture;
    
    
public:
    void spawn (Vector2f startPosition, float gravity);
    
    //this is a pure virtual function
    bool virtual handleInput() = 0;
    
    //Where is the player/?
    FloatRect getPosition();
   
    //A rectangle representing diffeent parts of the sprite
    FloatRect getFeet();
    FloatRect getHead();
    FloatRect getRight();
    FloatRect getLeft();
    
    //Send a copy of the sprite to main
    Sprite getSprite();
    
    //Make the character stand firm
    void stopFalling(float position);
    void stopRight(float position);
    void stopLeft(float position);
    void stopJump();
    
    // Where is the center of the charcter?
    Vector2f getCenter();
    
    //We will call this function once every frame
    void update(float elapsedTime);
    
    
    
    
    
    
    
    
    
};



#endif /* PlayableCharacter_h */
