#include <SDL.h>
#include "player.h"


// Lib�ration des ressources SDL
ressourceRelease(SDL_Renderer* renderer, SDL_Window* window)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

