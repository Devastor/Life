//
//  Entity.cpp
//  Life
//
//  Created by Devastor on 02.09.17.
//  Copyright © 2017 Devastor. All rights reserved.
//

#include "Entity.hpp"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <vector>

#define PI 3.14159

Entity::Entity(int id, SDL_Renderer *renderer, int cx, int cy, int rad, Uint8 r, Uint8 g, Uint8 b, Uint8 a, int windX, int windY)
{
    _id = id;
    food = 0;
    life = 15;
    
    mother = 0;
    x = cx;
    y = cy;
    radius = rad;
    _r = r;
    _g = g;
    _b = b;
    _a = a;
    
    wx = windX;
    wy = windY;
    
    rnd = renderer;
}

void Entity::draw()
{
    for (double dy = 1; dy <= radius; dy += 1)
    {
        double dx = floor(sqrt((2.0 * this->radius * dy) - (dy * dy)));
        SDL_SetRenderDrawColor(rnd, _r, _g, _b, _a);
        SDL_RenderDrawLine(rnd, this->x - dx, this->y + dy - this->radius, this->x + dx, this->y + dy - this->radius);
        SDL_RenderDrawLine(rnd, this->x - dx, this->y - dy + this->radius, this->x + dx, this->y - dy + this->radius);
    }
}

int distance(int x1, int x2, int y1, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

std::vector<double> CheckCollision2(Entity objectList[1000], int id, int length, int ang)
{
    int x0 = objectList[id].x;
    int y0 = objectList[id].y;
    int rad = objectList[id].radius;
    std::vector<double> vect;
    std::vector<int> angles;
    int anglesCount = 0;
    
    bool can = false;
    
    if (length > 1)
    {
        if (ang == -1)
        {
            for (int angle = 0; angle < 360; angle++)
            {
                for (int i = 0; i < length; i++)
                {
                    if (i != id && objectList[i].life > 0)
                    {
                        if ( distance(objectList[i].x, x0 + 2*rad*cos(angle * PI / 180), objectList[i].y, y0 + 2*rad*sin(angle * PI / 180))
                            < (rad + objectList[i].radius) ||
                            x0 >= objectList[i].wx - 2*rad||
                            x0 <= 2*rad ||
                            y0 >= objectList[i].wy - 2*rad ||
                            y0 <= 2*rad) ;
                        else
                        {
                            can = true;
                            angles.push_back(angle);
                            anglesCount++;
                        }
                    }
                }
            }
            
            if (can)
            {
                int dirRnd = std::rand() % anglesCount;
                vect.push_back(cos(angles[dirRnd] * PI / 180));
                vect.push_back(sin(angles[dirRnd] * PI / 180));
            }
            else
            {
                vect.push_back(-1);
                vect.push_back(-1);
                
                return vect;
            }
        
        }
        else
        {
            
            int angle = ang;
            for (int i = 0; i < length; i++)
            {
                if (/*i != id && */objectList[i].life > 0)
                {
                    if ( distance(objectList[i].x, x0 + 2*rad*cos(angle * PI / 180), objectList[i].y, y0 + 2*rad*sin(angle * PI / 180))
                        < (rad + objectList[i].radius) ||
                        x0 >= objectList[i].wx - 2*rad||
                        x0 <= 2*rad ||
                        y0 >= objectList[i].wy - 2*rad ||
                        y0 <= 2*rad)
                    {
                        vect.push_back(-1);
                        vect.push_back(-1);

                        return vect;
                    }
                    else
                    {
                        vect.push_back(cos(ang * PI / 180));
                        vect.push_back(sin(ang * PI / 180));
                        return vect;
                    }
                }
            }
        }
    }
    else
    {
        if (objectList[id].life > 0)
        {

            vect.push_back(cos(ang * PI / 180));
            vect.push_back(sin(ang * PI / 180));
            
            return vect;
        }
    }
    
    vect.push_back(-1);
    vect.push_back(-1);
    
    return vect;
}

void Entity::move(Entity objectList[1000], int length, int dir, int dist)
{
    std::vector<double> direction = CheckCollision2(objectList, this->_id, length, dir);
    
    if (direction[0] != - 1 && direction[1] != -1)
    {
        x += direction[0] * dist;
        y += direction[1] * dist;
    }
}

std::vector<double> Entity::CanCreate(Entity objectList[1000], int id, int length)
{
    // если достаточно пищи
    if (this->food == 1 && this->mother == 0)
    {
        return CheckCollision2(objectList, id, length, -1);
    }
    
    std::vector<double> temp;
    temp.push_back(-1);
    temp.push_back(-1);

    return temp;
}





