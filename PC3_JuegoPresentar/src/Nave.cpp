#include "../include/Nave.h"

Nave::Nave(SDL_Renderer* renderer) {
    SDL_Surface* surface = IMG_Load("assets/sprites/nave.png");
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    rect = { 400, 500, 64, 64 }; // Posición inicial (x, y, ancho, alto)
}

void Nave::render(SDL_Renderer* renderer) {
    SDL_RenderTexture(renderer, texture, NULL, &rect);
}

void Nave::mover(int dx) {
    rect.x += dx * velocidad;
    // Limitar a los bordes de la pantalla
    if (rect.x < 0) rect.x = 0;
    if (rect.x > 800 - rect.w) rect.x = 800 - rect.w;
}