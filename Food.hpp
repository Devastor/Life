//
//  Food.hpp
//  Life
//
//  Created by Devastor on 05.09.17.
//  Copyright © 2017 Devastor. All rights reserved.
//

#ifndef Food_hpp
#define Food_hpp

#include <stdio.h>
#include <SDL2/SDL.h>

class Food
{
public:
    int x;
    int y;
    Uint8 _r;
    Uint8 _g;
    Uint8 _b;
    Uint8 _a;
    int radius;
    int _id;
    
    Food () {};
    Food (int id, SDL_Renderer *renderer, int cx, int cy, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
    
    void draw();
    
private:
    
    SDL_Renderer *rnd;
    
};

#endif /* Food_hpp */
