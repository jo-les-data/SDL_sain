#pragma once
#include <SDL.h>
void ressourceRelease(SDL_Renderer* renderer, SDL_Window* window,
    SDL_Surface* image,
    SDL_Surface* imagebu, SDL_Surface* imagerab,
    SDL_Texture* texture, SDL_Texture* texturebu,
    SDL_Texture* texturerab);