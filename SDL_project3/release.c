#include <SDL.h>
#include "player.h"



ressourceRelease(SDL_Renderer* renderer, SDL_Window* window)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}


freeElements(Player* p1, Player* p2)
{
    free(p1);
    free(p2);
}
