//
//  Input.cpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#include <stdio.h>
#include "Engine.hpp"

void Engine::input(){
    Event event;
    while (m_Window.pollEvent(event)) {
        if (event.type == Event::KeyPressed) {
            // handle the player quitting
            if(Keyboard::isKeyPressed(Keyboard::Escape)){
                m_Window.close();
            }
            // Handle player starting the game
            if(Keyboard::isKeyPressed(sf::Keyboard::Return)){
                m_Playing = true;
            }
            //switch between thomas and bob
            if(Keyboard::isKeyPressed(Keyboard::Q)){
                m_Character1 = !m_Character1;
            }
            //Switch between full screen and split screen
            if(Keyboard::isKeyPressed(Keyboard::E)){
                m_SplitScreen = !m_SplitScreen;
            }
            
            
            
        }//end key pressed
    }//wnd poll event
    
}//end input
