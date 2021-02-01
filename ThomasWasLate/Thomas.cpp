//
//  Thomas.cpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#include "Thomas.hpp"
#include "TextureHolder.hpp"

Thomas::Thomas(){
    // Associate a textue with a sprite
    m_Sprite = Sprite(TextureHolder::GetTexture("thomas.png"));
    m_JumpDuration = 0.45;
    
}

//Virtual function

bool Thomas::handleInput(){
    m_JustJumped = false;
    
    if (Keyboard::isKeyPressed(Keyboard::W)){
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
    
    if(Keyboard::isKeyPressed(Keyboard::A)){
        m_LeftPressed = true;
        
    }
    else{
        m_LeftPressed = false;
    }// keyboard a
    
    if(Keyboard::isKeyPressed(Keyboard::D)){
        m_RightPressed = true;
        
    }
    else{
        m_RightPressed = false;
    }// keyboard a

    return m_JustJumped;
}// handle input

