//
//  Draw.cpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#include <stdio.h>
#include "Engine.hpp"


void Engine::draw(){
    // Rub out the last frame
    m_Window.clear();
    
    if (!m_SplitScreen) {
        //switch to background view
        m_Window.setView(m_BGMainView);
        //Draw the background
        m_Window.draw(m_BackgroundSprite);
        //switch to main view
        m_Window.setView(m_MainView);
        
        // Draw the Level
        m_Window.draw(m_VALevel, &m_TextureTiles);
        
        // draw thomas and bob
        m_Window.draw(m_Thomas.getSprite());
        m_Window.draw(m_Bob.getSprite());
        
        }
    else{
        // Split Screen view is active.
        
        //First draw thomas' side of the screen
        
        // switch to background view
        m_Window.setView(m_BGLeftView);
        //Draw the background
        m_Window.draw(m_BackgroundSprite);
        //switch to leftview
        m_Window.setView(m_LeftView);
        
        // Draw the Level
        m_Window.draw(m_VALevel, &m_TextureTiles);
        
        // draw thomas and bob
        m_Window.draw(m_Bob.getSprite());
        m_Window.draw(m_Thomas.getSprite());
        
        
        // Now draw Bob's side of the screen
        
        //switch to background view
        m_Window.setView(m_BGRightView);
        //Draw the background
        m_Window.draw(m_BackgroundSprite);
        //switch to RightView
        m_Window.setView(m_RightView);
        
        // Draw the Level
        m_Window.draw(m_VALevel, &m_TextureTiles);
        
        // draw thomas and bob
        m_Window.draw(m_Thomas.getSprite());
        m_Window.draw(m_Bob.getSprite());
        
    }// if else splitscreen
    
    // Draw the HUD
    
    //switch view to HUD
    m_Window.setView(m_HudView);
    
    //show everything we've just drawn
    m_Window.display();
    
    
}// end draw
