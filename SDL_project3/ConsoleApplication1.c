#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "player.h"
#include "set.h"
#include "update.h"
#include "release.h"
#include "constante.h"



int main(int argc, char* argv[])
{


    // Initialisation de la librairie SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL: %s\n", SDL_GetError());

    }




    // Creation de la fenêtre
    SDL_Window* wind = SDL_CreateWindow("Never chase the rabbit!",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT, 0);



    if (!wind)
    {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
    }


    // Creation du renderer
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;



    SDL_Renderer* rend = SDL_CreateRenderer(wind, -1, render_flags);
    SDL_Surface* image = SDL_LoadBMP("image1.bmp");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(rend, image);
    SDL_Surface* imageBu = SDL_LoadBMP("bunny.bmp");
    SDL_Texture* textureBu = SDL_CreateTextureFromSurface(rend, imageBu);
    SDL_Surface* imageRab = SDL_LoadBMP("brownrabbit.bmp");
    SDL_Texture* textureRab = SDL_CreateTextureFromSurface(rend, imageRab);
    SDL_Surface* imageCar = SDL_LoadBMP("carrot.bmp");
    SDL_Texture* textureCar = SDL_CreateTextureFromSurface(rend, imageCar);





    SDL_SetWindowIcon(wind, SDL_LoadBMP("logo.bmp"));


    if (!rend)
    {

        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(wind);
        SDL_Quit();
    }


    // Initialisation de la boucle update et des deux joueurs

    Player p1;
    Player p2;
    bool running = setGame(&p1, &p2);

    SDL_Rect obstacle = { WIDTH/2, HEIGHT/2, SIZE*2 , SIZE };

    // Fonction update
    update(running, &p1, &p2, rend, textureBu, textureRab, textureCar, texture, &obstacle);


    // Libération des ressources SDL
    ressourceRelease(rend, wind, image, imageBu, imageRab, imageCar, texture, textureBu, textureRab, textureCar);



    return 0;
}

