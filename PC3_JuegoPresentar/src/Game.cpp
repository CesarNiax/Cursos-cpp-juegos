#include "../include/Game.h"

Game::Game() {
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow("Nave SDL3", 800, 600, 0);
    renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
    nave = new Nave(renderer);
    running = true;
}

Game::~Game() {
    delete nave;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) running = false;
    }
}

void Game::update() {
    const Uint8* keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_LEFT]) nave->mover(-1);
    if (keystates[SDL_SCANCODE_RIGHT]) nave->mover(1);
}

void Game::render() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    nave->render(renderer);
    SDL_RenderPresent(renderer);
}

void Game::run() {
    while (running) {
        handleEvents();
        update();
        render();
        SDL_Delay(16); // ~60 FPS
    }
}