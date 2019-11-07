//
//  Input.hpp
//  Life
//
//  Created by Devastor on 02.09.17.
//  Copyright © 2017 Devastor. All rights reserved.
//

#ifndef Input_hpp
#define Input_hpp

#include "SDL2/SDL.h"

class Input
{
    // Methods
public:
    Input();
    ~Input();
    
    // Call this before any other methods
    void readInput();
    
    bool* getInput();
    
    // Check this each frame
    bool windowClosed();
    
    // Data
private:
    SDL_Event m_event;
    bool m_keysHeld[323];
    bool m_windowClosed;
};

#endif /* Input_hpp */
