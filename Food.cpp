//
//  Food.cpp
//  Life
//
//  Created by Devastor on 05.09.17.
//  Copyright © 2017 Devastor. All rights reserved.
//

#include "Food.hpp"

Food::Food(int id, SDL_Renderer *renderer, int cx, int cy, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    _id = id;
    x = cx;
    y = cy;
    _r = r;
    _g = g;
    _b = b;
    _a = a;
    radius = 5;
    
    rnd = renderer;
}

void Food::draw()
{
    for (double dy = 1; dy <= radius; dy += 2)
    {
        double dx = floor(sqrt((2.0 * this->radius * dy) - (dy * dy)));
        SDL_SetRenderDrawColor(rnd, _r, _g, _b, _a);
        
        SDL_RenderDrawLine(rnd, this->x - dx, this->y + dy - this->radius, this->x + dx, this->y + dy - this->radius);
        SDL_RenderDrawLine(rnd, this->x - dx, this->y - dy + this->radius, this->x + dx, this->y - dy + this->radius);
    }
}
