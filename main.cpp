#include "SDL2/SDL.h"
#include "Entity.hpp"
#include "Food.hpp"
#include <iostream>
#include <cstdio>
#include <ctime>
#include <memory>
#include <vector>

#define MAX_FOOD 60
#define EAT_DISTANCE 10
#define WINDOW_X 1600
#define WINDOW_Y 1000

int rad = 15;
int var = 2;
Entity objectList[1000];
Food foodList[MAX_FOOD];
int foods = 0;
int objects = 0;
int dr;

std::clock_t start;
double duration;

std::vector<double> vect;

int dist_between(int x1, int x2, int y1, int y2)
{
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

void checkFood(Entity ent)
{
    for (int i = 0; i < MAX_FOOD; i++)
    {
        if (dist_between(ent.x, foodList[i].x, ent.y, foodList[i].y) < EAT_DISTANCE + ent.radius*2 && foodList[i]._id != -1)
        {
            //ent.food = 1;
            objectList[ent._id].food = 1;
            foodList[i]._id = -1;
            break;
        }
    }
}

int main(int argc, char* argv[])
{
    start = std::clock();
    std::srand(std::time(0));
    
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
        
        vect.push_back(-1);
        vect.push_back(-1);
        
        if (SDL_CreateWindowAndRenderer(WINDOW_X, WINDOW_Y, 0, &window, &renderer) == 0)
        {
            SDL_bool done = SDL_FALSE;
            
            // create first objects
            objectList[objects] = *new Entity(0, renderer, WINDOW_X/2, WINDOW_Y/2, rad, 0xFF, 0x00, 0x00, 0xFF, WINDOW_X, WINDOW_Y);
            objects++;
            
            int rx, ry;
            
            for (int i = 0; i < MAX_FOOD; i++)
            {
                rx = std::rand() % (WINDOW_X - 20) + 10;
                ry = std::rand() % (WINDOW_Y - 20) + 10;
                foodList[i] = *new Food(foods, renderer, rx, ry, 0x00, 0xFF, 0x00, 0xFF);
                foods++;
            }
            
            std::cout << "Adam created!\n";
            
            while (!done)
            {
                SDL_Event event;
                
                if (SDL_PollEvent(&event))
                {
                    if (event.type == SDL_QUIT)
                    {
                        done = SDL_TRUE;
                    }
                    
                }
                
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
                SDL_RenderClear(renderer);
                
                for (int i = 0; i < objects; i++)
                {
                    int dirRnd = std::rand() % 360;
                    
                    //std::cout << "rnd = " << objects << "\n";
                    
                    int distRnd = 1;//std::rand() % 1;objectList[i].radius;
                    if (objectList[i].life > 0) objectList[i].move(objectList, objects, dirRnd, distRnd);
                    
                    if (objectList[i].life > 0 && objectList[i].food == 0) checkFood(objectList[i]);
                    
                    if (objectList[i].life > 0) objectList[i].draw();
                }
                
                for (int i = 0; i < foods; i++)
                {
                    if (foodList[i]._id != -1) foodList[i].draw();
                }
                
                SDL_RenderPresent(renderer);
                
                duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
                
                if (duration > 0.3)
                {
                    for (int i = 0; i < objects; i++)
                    {
                        if (objectList[i].life > 0) objectList[i].life--;
                    }
                    
                    int num = objects + 1;
                    
                    for (int i = 1; i < num; i++)
                    {
                        if (objectList[i-1].life > 0) vect = objectList[i-1].CanCreate(objectList, i-1, objects);
                        
                        dr = std::rand() % var - std::rand() % var;
                        
                        if (vect[0] != -1 && vect[1] != -1)
                        {
                            //std::cout << "x = " << vect[0] << "\n";
                            //std::cout << "y = " << vect[1] << "\n";
                            // create object
                            objectList[objects] = *new Entity(objects, renderer,
                                                              vect[0] + objectList[i-1].x,
                                                              vect[1] + objectList[i-1].y,
                                                              objectList[i-1].radius+dr,
                                                              0xFF, 0x00, 0x00, 0xFF, WINDOW_X, WINDOW_Y);
                            //objectList[i-1].mother = 1;
                            objectList[i-1].food = 0;
                            objects++;
                        }
                    }
                    start = std::clock();
                }
            }
        }
        
        if (renderer)
        {
            SDL_DestroyRenderer(renderer);
        }
        if (window)
        {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
    return 0;
}

