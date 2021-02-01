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
    if (m_Playing) {
        //count down the remaining time the player has left
        m_TimeRemaining -=dtAsSeconds;
        
        //have thomas and bob run out of time?
        if (m_TimeRemaining<=0) {
            m_NewLevelRequired = true;
        }
    }// end if-playing= true
}//end update
