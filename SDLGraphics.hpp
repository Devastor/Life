//
//  SDLGraphics.hpp
//  Life
//
//  Created by Devastor on 02.09.17.
//  Copyright © 2017 Devastor. All rights reserved.
//

#ifndef SDLGraphics_hpp
#define SDLGraphics_hpp

#include "SDL2/SDL.h"
#include <SDL2_ttf/SDL_ttf.h>

class SDLGraphics
{
    // Methods
public:
    // This creates a window and initializes the graphics object.
    // The last three parameters are the desired background color.
    // Call setBackgroundColor() to change this later.
    SDLGraphics(int windowWidth, int windowHeight,
                const char* windowTitle,
                int bgR, int bgG, int bgB);
    ~SDLGraphics();
    // Each call to loadBitmap() must have a corresponding call to closeBitmap().
    SDL_Surface* loadBitmap(const char* bitmapFileName,
                            int transparentRed, int transparentGreen, int transparentBlue);
    void closeBitmap(SDL_Surface* bitmap);
    
    // These calls must surround all drawing routines.
    void beginScene();
    void endScene();
    
    void drawSprite(SDL_Surface* imageSurface,
                    int srcX, int srcY,
                    int dstX, int dstY,
                    int width, int height);
    
    void drawText(const char* string,
                  int size,
                  int x, int y,
                  int fR, int fG, int fB,
                  int bR, int bG, int bB);
    
    void drawCircle(int centerX, int centerY, int radius, SDL_Color color);
    
    void setBackgroundColor(int r, int g, int b);
    
    // Data
private:
    SDL_Surface* m_screen;
    
    int m_backgroundColorRed;
    int m_backgroundColorGreen;
    int m_backgroundColorBlue;
};

#endif /* SDLGraphics_hpp */
