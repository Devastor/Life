//
//  Entity.hpp
//  Life
//
//  Created by Devastor on 02.09.17.
//  Copyright © 2017 Devastor. All rights reserved.
//

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <vector>

class Entity
{
public:
    int food;
    bool mother;
    double x;
    double y;
    int radius;
    int life;
    Uint8 _r;
    Uint8 _g;
    Uint8 _b;
    Uint8 _a;
    int wx = 1600;
    int wy = 1200;
    
    int _id;
    
    Entity () {};
    Entity (int id, SDL_Renderer *renderer, int cx, int cy, int rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int windX, int windY);
    
    void draw();
    
    void move(Entity objectList[1000], int length, int dir, int dist);
    
    Entity BornObject(int id);
    
    std::vector<double> CanCreate(Entity objectList[1000], int id, int length);
    
private:
    
    SDL_Renderer *rnd;
    
};

#endif /* Entity_hpp */
