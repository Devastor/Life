//
//  Entity.h
//  Life
//
//  Created by Devastor on 02.09.17.
//  Copyright © 2017 Devastor. All rights reserved.
//

#ifndef Entity_h
#define Entity_h

#include <SDL2/SDL.h>

class Entity
{
public:
    int _id;
    
    Entity (int id);
    
    void CreateObject(SDL_Renderer* gRenderer);
};

#endif /* Entity_h */
