#include <SDL.h>
#include "player.h"


// Libération des ressources SDL
ressourceRelease(SDL_Renderer* renderer, SDL_Window* window, SDL_Surface* image, SDL_Surface* imagebu, SDL_Surface* imagerab, SDL_Texture* texture, SDL_Texture* texturebu, SDL_Texture* texturerab)
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyTexture(texturebu);
    SDL_FreeSurface(imagebu);
    SDL_DestroyTexture(texturerab);
    SDL_FreeSurface(imagerab);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

