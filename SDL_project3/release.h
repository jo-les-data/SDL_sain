#pragma once
#include <SDL.h>
void ressourceRelease(SDL_Renderer* renderer, SDL_Window* window,
    SDL_Surface* image,
    SDL_Surface* imageBu, SDL_Surface* imageRab, SDL_Surface* imageCar,
    SDL_Texture* texture, SDL_Texture* textureBu,
    SDL_Texture* textureRab, SDL_Texture* textureCar);