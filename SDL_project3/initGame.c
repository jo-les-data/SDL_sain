#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

#define WIDTH 1200
#define HEIGHT 800


void initSDL()
{
    /* Initializes the timer, audio, video, joystick,
haptic, gamecontroller and events subsystems */
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        
    }
    
}

SDL_Window* initWindow()
{
    /* Create a window */
    SDL_Window* wind = SDL_CreateWindow("Hello Platformer!",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT, 0);

    if (!wind)
    {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return NULL;
    }

    printf("avant : %p\n", wind);

    return wind;
}


SDL_Renderer* initRenderer(SDL_Window* wind)
{
    /* Create a renderer */
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    printf("apr�s : %p\n", wind);


    SDL_Renderer* rend = SDL_CreateRenderer(wind, -1, render_flags);

    

   
    if (!rend)
    {

        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(wind);
        SDL_Quit();
        return NULL;
    }

    return rend;
}