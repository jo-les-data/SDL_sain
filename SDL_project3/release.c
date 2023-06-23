#include <SDL.h>
#include "player.h"


// Liberation des ressources SDL
void ressourceRelease(SDL_Renderer * renderer, SDL_Window * window, 
    SDL_Surface * image, 
    SDL_Surface * imageBu, SDL_Surface * imageRab, SDL_Surface* imageCar,
    SDL_Texture * texture, SDL_Texture * textureBu,
    SDL_Texture * textureRab , SDL_Texture* textureCar )
{
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(image);
    SDL_DestroyTexture(textureBu);
    SDL_FreeSurface(imageBu);
    SDL_DestroyTexture(textureRab);
    SDL_FreeSurface(imageRab);
    SDL_DestroyTexture(textureCar);
    SDL_FreeSurface(imageCar);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

