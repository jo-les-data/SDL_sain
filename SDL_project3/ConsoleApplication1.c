#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "player.h"



#define WIDTH 1200
#define HEIGHT 800
#define FPS 60
#define SIZE 100





void update(bool running, Player* p1, Player* p2, SDL_Renderer* rend)
{
    SDL_Event event;
    

    while (running)
    {
        /* Process events */
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_UP:
                    p2->jump_pressed = true;
                    break;

                case SDL_SCANCODE_LEFT:
                    p2->left_pressed = true;
                    break;

                case SDL_SCANCODE_RIGHT:
                    p2->right_pressed = true;
                    break;

                case SDL_SCANCODE_W:
                    p1->jump_pressed = true;
                    break;

                case SDL_SCANCODE_A:
                    p1->left_pressed = true;
                    break;

                case SDL_SCANCODE_D:
                    p1->right_pressed = true;
                    break;



                default:
                    break;

                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_UP:
                    p2->jump_pressed = false;
                    break;

                case SDL_SCANCODE_LEFT:
                    p2->left_pressed = false;
                    break;

                case SDL_SCANCODE_RIGHT:
                    p2->right_pressed = false;
                    break;

                case SDL_SCANCODE_W:
                    p1->jump_pressed = false;
                    break;

                case SDL_SCANCODE_A:
                    p1->left_pressed = false;
                    break;

                case SDL_SCANCODE_D:
                    p1->right_pressed = false;
                    break;



                default:
                    break;

                }
                break;

            default:
                break;
            }
        }

        /* Clear screen */
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);


        movement(p1);
        movement(p2);



        /* Draw the rectangle */
        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        SDL_RenderFillRect(rend, &p1->rect);
        SDL_RenderFillRect(rend, &p2->rect);

        /* Draw to window and loop */
        SDL_RenderPresent(rend);
        SDL_Delay(1000 / FPS);

    }
}






int main(int argc, char* argv[])
{

    

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL: %s\n", SDL_GetError());

    }


    SDL_Window* wind = SDL_CreateWindow("Hello Platformer!",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT, 0);

    if (!wind)
    {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
    }


    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;



    SDL_Renderer* rend = SDL_CreateRenderer(wind, -1, render_flags);



    if (!rend)
    {

        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(wind);
        SDL_Quit();
    }




    bool running = true;


    int start = HEIGHT - SIZE;

    Player p1;  playerInit(&p1,0, start);
    Player p2;  playerInit(&p2,WIDTH, start);


    

    update(running, &p1, &p2, rend);

    /* Release resources */

    ressourceRelease(rend, wind);


    
    return 0;
}


