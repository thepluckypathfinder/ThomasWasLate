//
//  TextureHolder.cpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#include "TextureHolder.hpp"
#include <cassert>

using namespace sf;
using namespace std;

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder(){
    assert(m_s_Instance ==nullptr);
    m_s_Instance = this;
}

sf::Texture& TextureHolder::GetTexture(const std::string& filename){
    // get a reference to m_textures using m_s_instance
    auto& m = m_s_Instance -> m_Textures;
    // auto is equivalent to map<string,texture>
    
    //create and iterator  to hold a key value pair and search for the required kvp using the passed in the filename
    auto keyValuePair = m.find(filename);
    // auto is equal to the map<string>,<>texture:: iterator
    
    
    //did we find a match?
    if (keyValuePair != m.end()){
        //yes, return the second part of the kvp the texture
        return keyValuePair->second;
    }
    else{
        //filename not found, create a new keyvalue pair
        auto& texture = m[filename];
        // load texture from file in the usual way
        texture.loadFromFile("/Users/mistyleaf/Desktop/Cpp Games/ThomasWasLate/ThomasWasLate/Resources/graphics/"+filename);
        
        return texture;
    }
}
