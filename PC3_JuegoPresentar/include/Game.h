#ifndef GAME_H
#define GAME_H

#include <SDL3/SDL.h>
#include "Nave.h"

class Game {
public:
    Game();
    ~Game();
    void run();

private:
    void handleEvents();
    void update();
    void render();

    SDL_Window* window;
    SDL_Renderer* renderer;
    Nave* nave;
    bool running;
};

#endif