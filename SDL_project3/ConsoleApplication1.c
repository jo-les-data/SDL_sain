#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "player.h"


// Taille de la fenêtre et du joueur
#define WIDTH 1200
#define HEIGHT 800
#define SIZE 100




int main(int argc, char* argv[])
{

    
    // Initialisation de la librairie SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL: %s\n", SDL_GetError());

    }



    // Creation de la fenêtre
    SDL_Window* wind = SDL_CreateWindow("Hello Platformer!",
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
    SDL_Surface* imagebu = SDL_LoadBMP("bunny.bmp");
    SDL_Texture* texturebu = SDL_CreateTextureFromSurface(rend, imagebu);
    SDL_Surface* imagerab = SDL_LoadBMP("brownrabbit.bmp");
    SDL_Texture* texturerab = SDL_CreateTextureFromSurface(rend, imagerab);



    if (!rend)
    {

        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(wind);
        SDL_Quit();
    }



    // Initialisation de la boucle update et des deux joueurs
    bool running = true;
    int start = HEIGHT - SIZE;

    Player p1;  playerInit(&p1,0, start);
    Player p2;  playerInit(&p2,WIDTH, start);


    
    // Fonction update
    update(running, &p1, &p2, rend, texturebu, texturerab, texture);

    
    // Libération des ressources SDL
    ressourceRelease(rend, wind);


    
    return 0;
}


