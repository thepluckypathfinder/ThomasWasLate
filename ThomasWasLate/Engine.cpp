//
//  Engine.cpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#include "Engine.hpp"

Engine::Engine(){
    //get the screen resolution and create and SFML window and view
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y =VideoMode::getDesktopMode().height;
    
    m_Window.create(VideoMode(resolution.x,resolution.y), "Thomas Was Late", Style::Fullscreen);
    
    //Initialize the Full screen view
    m_MainView.setSize(resolution);
    m_HudView.reset(FloatRect(0,0,resolution.x,resolution.y));
    
    
    
    // Initialize split screenviews
    m_LeftView.setViewport(FloatRect(0.001f,0.001f,0.498f,0.998f));
    m_RightView.setViewport(FloatRect(0.5f,0.001f,0.499f,0.998f));
    
    m_BGLeftView.setViewport(FloatRect(0.001f,0.001f,0.498f,0.998f));
    m_BGRightView.setViewport(FloatRect(0.5f,0.001f,0.499f,0.998f));
    
    m_BackgroundTexture = TextureHolder::GetTexture("background.png");
    
    //Associate the sprite with the texture
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    
    
}

void Engine::Run(){
    Clock clock;
    
    while(m_Window.isOpen()){
        Time dt = clock.restart();
        
        //update the total game time
        m_GameTimeTotal += dt;
        
        // make a decimal fraction from the delta time
        float dtAsSeconds = dt.asSeconds();
        
        
        //Call each part of the game loop in turn
        input();
        update(dtAsSeconds);
        draw();
        
        
        
        
        
    }
    
}
