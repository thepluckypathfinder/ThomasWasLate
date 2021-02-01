//
//  PlayableCharacter.cpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#include "PlayableCharacter.hpp"

void PlayableCharacter::spawn(Vector2f startPosition, float gravity){
    //place the player at the starting position
    m_Position.x = startPosition.x;
    m_Position.y = startPosition.y;
    
    //initialize the gravity
    m_Gravity = gravity;
    
    //move the sprite into position
    m_Sprite.setPosition(m_Position);
    
}

void PlayableCharacter::update(float elapsedTime){
    if (m_RightPressed){
        m_Position.x += m_Speed * elapsedTime;
        
    }
    if (m_LeftPressed) {
        m_Position.x -= m_Speed * elapsedTime;
    }
    
    //Handle Jumping
    if(m_IsJumping){
        // Update how long the jump has been going on
        m_TimeThisJump += elapsedTime;
        // is the jump is gonig upwards?
        if(m_TimeThisJump<m_JumpDuration){
            // Move up at twice gravity
            m_Position.y -= 2 * m_Gravity *elapsedTime;
            
            
        }
        else{
            m_IsJumping = false;
            m_IsFalling = true;
        }
    }//end is jumping
    
    //Apply gravity
    if (m_IsFalling) {
        m_Position.y += m_Gravity * elapsedTime;
    }
    
    
    //update the rect for all body parts
    FloatRect r = getPosition();
    
    //Feet
    m_Feet.left = r.left + 3;
    m_Feet.top = r.top + r.height - 1;
    m_Feet.width = r.width - 6;
    m_Feet.height = 1;
    
    //Head
    m_Head.left = r.left ;
    m_Head.top = r.top + (r.height * .3);
    m_Head.width = r.width;
    m_Head.height = 1;
    
    //Right
    m_Right.left = r.left + r.width -2;
    m_Right.top = r.top + (r.height * .35);
    m_Right.width = 1;
    m_Right.height = r.height * .3;
    
    //Left
    m_Left.left = r.left ;
    m_Left.top = r.top + (r.height * .5);
    m_Left.width = 1;
    m_Left.height = r.height * .3;
    
    // movet the sprite into position
    m_Sprite.setPosition(m_Position);

    
    
}//end update

FloatRect PlayableCharacter::getPosition(){
    return m_Sprite.getGlobalBounds();
    
}

Vector2f PlayableCharacter::getCenter(){
    return Vector2f(m_Position.x + m_Sprite.getGlobalBounds().width/2, m_Position.y +m_Sprite.getGlobalBounds().height/2);
}

FloatRect PlayableCharacter::getFeet(){
    return m_Feet;
}
FloatRect PlayableCharacter::getHead(){
    return m_Head;
}

FloatRect PlayableCharacter::getRight(){
    return m_Right;
}

FloatRect PlayableCharacter::getLeft(){
    return m_Left;
}

Sprite PlayableCharacter::getSprite(){
    return m_Sprite;
}

void PlayableCharacter::stopFalling(float position){
    m_Position.y = position - m_Sprite.getGlobalBounds().height; // it was getPosition() initially
    m_Sprite.setPosition(m_Position);
    m_IsFalling = false;
    
}

void PlayableCharacter::stopRight(float position){
    m_Position.x = position - m_Sprite.getGlobalBounds().width;
    m_Sprite.setPosition(m_Position);

    
}

void PlayableCharacter::stopLeft(float position){
    m_Position.x = position + m_Sprite.getGlobalBounds().width;// shouldnt this just be without width?
    m_Sprite.setPosition(m_Position);

    
}

void PlayableCharacter::stopJump(){
    //Stop a jump early
    m_IsJumping = false;
    m_IsFalling =  true;
}










