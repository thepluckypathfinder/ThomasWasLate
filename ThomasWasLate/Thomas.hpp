//
//  Thomas.hpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#ifndef Thomas_hpp
#define Thomas_hpp
#pragma once
#include <stdio.h>
#include "PlayableCharacter.hpp"

class Thomas : public PlayableCharacter{
public:
    // A constructor specific to thomas
    Thomas();
    
    // the overridden input handler for thomas
    bool virtual handleInput();
};

#endif /* Thomas_hpp */
