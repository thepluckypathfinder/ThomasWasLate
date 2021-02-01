//
//  Update.cpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#include <stdio.h>
#include "Engine.hpp"
#include <sstream>

//#include <Sfml/Graphics.hpp>
//using namespace sf;

void Engine::update(float dtAsSeconds){
    if(m_NewLevelRequired){
        // these calls to spawn will be moved to a new load level function soon
        //Spawn tohomas and bob
        
        m_Thomas.spawn(Vector2f(0,0), GRAVITY);
        m_Bob.spawn(Vector2f(100,0), GRAVITY);
        
        // make sure spawn is clle donly once
        m_TimeRemaining = 10;
        m_NewLevelRequired = false;
    }
    
    if (m_Playing) {
        
        
        
        //count down the remaining time the player has left
        m_TimeRemaining -=dtAsSeconds;
        
        //Update Thomas
        m_Thomas.update(dtAsSeconds);
        //Update Bob
        m_Bob.update(dtAsSeconds);
        
        
        //have thomas and bob run out of time?
        if (m_TimeRemaining<=0) {
            m_NewLevelRequired = true;
        }
    }// end if-playing= true
    
    // set the appropriate view around the appropriate character
    if (m_SplitScreen){
        m_LeftView.setCenter(m_Thomas.getCenter());
        m_RightView.setCenter(m_Bob.getCenter());
    }
    else{
        //center the full screen around appropriate character
        if(m_Character1){
            m_MainView.setCenter(m_Thomas.getCenter());
            
        }
        else{
            m_MainView.setCenter(m_Bob.getCenter());
        }
    }
    
}//end update
