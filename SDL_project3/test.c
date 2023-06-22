#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "player.h"



#define WIDTH 1200
#define HEIGHT 800
#define SIZE 100
#define SPEED 600
#define GRAVITY 60
#define FPS 60
#define JUMP -1200














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


        /* Move the rectangle */
        p1->x_vel = (p1->right_pressed - p1->left_pressed) * SPEED;
        p1->y_vel += GRAVITY;


        p2->x_vel = (p2->right_pressed - p2->left_pressed) * SPEED;
        p2->y_vel += GRAVITY;

        if (p1->jump_pressed)
        {
            p1->y_vel = JUMP;

        }

        if (p2->jump_pressed)
        {
            p2->y_vel = JUMP;
        }

        p1->x_pos += p1->x_vel / 60;
        p1->y_pos += p1->y_vel / 60;

        p2->x_pos += p2->x_vel / 60;
        p2->y_pos += p2->y_vel / 60;

        if (p1->x_pos <= 0)
        {
            p1->x_pos = 0;
        }

        if (p2->x_pos <= 0)
        {
            p2->x_pos = 0;
        }





        if (p1->x_pos >= WIDTH - p1->rect.w)
        {
            p1->x_pos = WIDTH - p1->rect.w;
        }

        if (p2->x_pos >= WIDTH - p2->rect.w)
        {
            p2->x_pos = WIDTH - p2->rect.w;
        }

        if (p1->y_pos <= 0)
        {
            p1->y_pos = 0;
        }

        if (p2->y_pos <= 0)
        {
            p2->y_pos = 0;
        }


        if (p1->y_pos >= HEIGHT - p1->rect.h)
        {
            p1->y_vel = 0;
            p1->y_pos = HEIGHT - p1->rect.h;


        }

        if (p2->y_pos >= HEIGHT - p2->rect.h)
        {
            p2->y_vel = 0;
            p2->y_pos = HEIGHT - p2->rect.h;

        }


        p1->rect.x = (int)p1->x_pos;
        p1->rect.y = (int)p1->y_pos;
                
        p2->rect.x = (int)p2->x_pos;
        p2->rect.y = (int)p2->y_pos;



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




    initSDL();

    SDL_Window* wind = initWindow();


    SDL_Renderer* rend = initRenderer(wind);


    bool running = true;


    int start = HEIGHT - SIZE;

    Player *p1 = playerInit(0, start);
    Player *p2 = playerInit(WIDTH, start);


    

    update(running, p1, p2, rend);

    /* Release resources */

    ressourceRelease(rend, wind);

    freeElements(p1, p2);

    
    return 0;
}
