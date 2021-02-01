//
//  TextureHolder.hpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#pragma once
#ifndef TextureHolder_hpp
#define TextureHolder_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder{
private:
    // a map container from the STL that holds related pairs of string and Texture
    std::map<std::string, sf::Texture> m_Textures;
    
    // a pointer of the same type as the class itself
    static TextureHolder* m_s_Instance;
    
public:
    TextureHolder();
    static sf::Texture& GetTexture(std::string const& filename);
};


#endif /* TextureHolder_hpp */
