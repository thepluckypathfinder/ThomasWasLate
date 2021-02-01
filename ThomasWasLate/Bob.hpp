//
//  Bob.hpp
//  ThomasWasLate
//
//  Created by gautham baichapur on 01/02/21.
//  Copyright © 2021 holler. All rights reserved.
//

#ifndef Bob_hpp
#define Bob_hpp

#include <stdio.h>
#include "PlayableCharacter.hpp"

class Bob : public PlayableCharacter{
public:
    // A constructor specific to thomas
    Bob();
    
    // the overridden input handler for thomas
    bool virtual handleInput();
};

#endif /* Bob_hpp */
