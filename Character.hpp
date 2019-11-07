//
//  Character.hpp
//  Life
//
//  Created by Devastor on 02.09.17.
//  Copyright © 2017 Devastor. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include "SDL2/SDL.h"
#include "SDLGraphics.hpp"

class Character
{
    // Methods
public:
    // This class holds a pointer to the graphics object but will not destroy it.
    Character(SDLGraphics* graphics,
              int imageX, int imageY,
              int width, int height,
              int transparentR, int transparentG, int transparentB,
              const char* bitmapFileName,
              float x, float y,
              float maxSpeed);
    
    ~Character();
    
    // This must be called each frame
    void update(float deltaTime);
    
    void draw();
    
    void moveLeft();
    void moveRight();
    void stopMoving();
    
    // Data
private:
    SDLGraphics* m_graphics;
    SDL_Surface* m_bitmap;
    
    float m_x;
    float m_y;
    float m_width;
    float m_height;
    
    float m_imageX;
    float m_imageY;
    
    float m_maxSpeed;
    float m_currentSpeedX;
};

#endif /* Character_hpp */
