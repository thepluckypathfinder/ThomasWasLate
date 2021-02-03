//
//  Engine.hpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#ifndef Engine_hpp
#define Engine_hpp

#include <stdio.h>
#include "TextureHolder.hpp"
#include <SFML/Graphics.hpp>
#include "Bob.hpp"
#include "Thomas.hpp"
#include "LevelManager.hpp"

using namespace sf;

class Engine{
private:
    // The texture holder
    TextureHolder th;
    
    // thomas and his friend bob
    Thomas m_Thomas;
    Bob m_Bob;
    
    // A class to manage all the levels
    LevelManager m_LM; 
    
    const int TILE_SIZE = 50;
    const int VERTS_IN_QUAD = 4;
    
    // the force pushing the characters down
    const int GRAVITY = 300;
    
    // A regular Renderwindow
    RenderWindow m_Window;
    
    // The main views
    View m_MainView;
    View m_LeftView;
    View m_RightView;
    
    // The three views for the bckground
    View m_BGMainView;
    View m_BGLeftView;
    View m_BGRightView;
    
    View m_HudView;
    
    //Declare a sprite and a texture for the background
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    
    // The vertex array for the level design
    VertexArray m_VALevel;

    // The 2d array with the map for the level
    // A pointer to a pointer
    int** m_ArrayLevel = NULL;
    
    
    // Texture for the background and the level tiles
    Texture m_TextureTiles;
    
    // Is the game currently playing?
    bool m_Playing = false;
    
    //Is character 1 or 2?
    bool m_Character1 = true;
    
    //Start in full screen
    bool m_SplitScreen = false;
    
    //Time left in the current level
    float m_TimeRemaining = 10;
    Time m_GameTimeTotal;
    
    //Is it time fo the new/first level?
    bool m_NewLevelRequired = true;
    
    //Private functions for internal use only
    void input();
    void update(float dtAsSeconds);
    void draw();
    
    // Load a new level
    void loadLevel();

    // Run will call all the private functions
    bool detectCollisions(PlayableCharacter& character);
public:
    //The engine constructor
    Engine();
    
    //Run will call all the private functions
    void Run();
    
    
    
};


#endif /* Engine_hpp */
