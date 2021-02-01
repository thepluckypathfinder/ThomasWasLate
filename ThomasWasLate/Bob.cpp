//
//  Bob.cpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#include "Bob.hpp"
#include "TextureHolder.hpp"

Bob::Bob(){
    // Associate a textue with a sprite
    m_Sprite = Sprite(TextureHolder::GetTexture("bob.png"));
    m_JumpDuration = 0.25;
    
}

//Virtual function

bool Bob::handleInput(){
    m_JustJumped = false;
    
    if (Keyboard::isKeyPressed(Keyboard::Up)){
        // Start a jump is not already falling but only if standing on a block
        if(!m_IsJumping && !m_IsFalling){
            m_IsJumping = true;
            m_TimeThisJump = 0;
            m_JustJumped = true;
            
        }
    }
    else{
        m_IsJumping = false;
        m_IsFalling = true;
        
    }// keyboard w
    
    if(Keyboard::isKeyPressed(Keyboard::Left)){
        m_LeftPressed = true;
        
    }
    else{
        m_LeftPressed = false;
    }// keyboard a
    
    if(Keyboard::isKeyPressed(Keyboard::Right)){
        m_RightPressed = true;
        
    }
    else{
        m_RightPressed = false;
    }// keyboard a

    return m_JustJumped;
}// handle input
