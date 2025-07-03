#ifndef NAVE_H
#define NAVE_H

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

class Nave {
public:
    Nave(SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer);
    void mover(int dx);

private:
    SDL_Texture* texture;
    SDL_Rect rect;
    int velocidad = 5;
};

#endif