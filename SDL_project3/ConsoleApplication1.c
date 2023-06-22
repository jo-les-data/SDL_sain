/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

// test changement

//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct Player
{
    bool *jump_pressed; 
    bool *left_pressed;
    bool *right_pressed;
    int x_pos;
    int y_pos;
    int x_vel;
    int y_vel;

} Player;


Player* playerInit(int x, int y)
{

    Player* ptr = malloc(sizeof(Player));

    if (ptr != NULL)
    {
        ptr->jump_pressed = false;
        ptr->left_pressed = false;
        ptr->right_pressed = false;
        ptr->x_pos = x;
        ptr->y_pos = y;
        ptr->x_vel = 0;
        ptr->y_vel = 0;



        return ptr;
    }
    else
    {
        return NULL;
    }


}



int main(int argc, char* argv[])
{
    /* Initializes the timer, audio, video, joystick,
    haptic, gamecontroller and events subsystems */
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        printf("Error initializing SDL: %s\n", SDL_GetError());
        return 0;
    }

    /* Create a window */
    SDL_Window* wind = SDL_CreateWindow("Hello Platformer!",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WIDTH, HEIGHT, 0);

    if (!wind)
    {
        printf("Error creating window: %s\n", SDL_GetError());
        SDL_Quit();
        return 0;
    }

    /* Create a renderer */
    Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
    SDL_Renderer* rend = SDL_CreateRenderer(wind, -1, render_flags);

    if (!rend)
    {

        printf("Error creating renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(wind);
        SDL_Quit();
        return 0;

    }

    /* Main loop */
    bool running = true;
    bool jump_pressed = false, left_pressed = false, right_pressed = false;
    bool jump_pressed2 = false, left_pressed2 = false, right_pressed2 = false;


    float x_pos = 0;
    float y_pos = (HEIGHT - SIZE);

    float x2_pos = (WIDTH);
    float y2_pos = (HEIGHT - SIZE);

    float x_vel = 0;
    float y_vel = 0;

    float x2_vel = 0;
    float y2_vel = 0;

    SDL_Rect rect = { (int)x_pos, (int)y_pos, SIZE, SIZE };
    SDL_Rect rect2 = { (int)x_pos, (int)y_pos, SIZE, SIZE };

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
                    jump_pressed = true;
                    break;

                case SDL_SCANCODE_LEFT:
                    left_pressed = true;
                    break;

                case SDL_SCANCODE_RIGHT:
                    right_pressed = true;
                    break;

                case SDL_SCANCODE_W :
                    jump_pressed2 = true;
                    break;

                case SDL_SCANCODE_A:
                    left_pressed2 = true;
                    break;

                case SDL_SCANCODE_D:
                    right_pressed2 = true;
                    break;



                default:
                    break;

                }
                break;

            case SDL_KEYUP:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_UP:
                    jump_pressed = false;
                    break;

                case SDL_SCANCODE_LEFT:
                    left_pressed = false;
                    break;

                case SDL_SCANCODE_RIGHT:
                    right_pressed = false;
                    break;

                case SDL_SCANCODE_W:
                    jump_pressed2 = false;
                    break;

                case SDL_SCANCODE_A:
                    left_pressed2 = false;
                    break;

                case SDL_SCANCODE_D:
                    right_pressed2 = false;
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
        x_vel = (right_pressed - left_pressed) * SPEED;
        y_vel += GRAVITY;

        x2_vel = (right_pressed2 - left_pressed2) * SPEED;
        y2_vel += GRAVITY;

        if (jump_pressed)
        {
            y_vel = JUMP;
            
        }

        if (jump_pressed2)
        {
            y2_vel = JUMP;
        }

        x_pos += x_vel / 60;
        y_pos += y_vel / 60;

        x2_pos += x2_vel / 60;
        y2_pos += y2_vel / 60;

        if (x_pos <= 0)
        {
            x_pos = 0;
        }

        if (x2_pos <= 0)
        {
            x2_pos = 0;
        }

        if (x_pos >= WIDTH - rect.w)
        {
            x_pos = WIDTH - rect.w;
        }
            
        if (x2_pos >= WIDTH - rect2.w)
        {
            x2_pos = WIDTH - rect2.w;
        }

        if (y_pos <= 0) 
        {
            y_pos = 0;
        }

        if (y2_pos <= 0)
        {
            y2_pos = 0;
        }
            

        if (y_pos >= HEIGHT - rect.h)
        {
            y_vel = 0;
            y_pos = HEIGHT - rect.h;

                
        }

        if (y2_pos >= HEIGHT - rect2.h)
        {
            y2_vel = 0;
            y2_pos = HEIGHT - rect2.h;

        }


        rect.x = (int)x_pos;
        rect.y = (int)y_pos;

        rect2.x = (int)x2_pos;
        rect2.y = (int)y2_pos;

        /* Draw the rectangle */
        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        SDL_RenderFillRect(rend, &rect);
        SDL_RenderFillRect(rend, &rect2);

        /* Draw to window and loop */
        SDL_RenderPresent(rend);
        SDL_Delay(1000 / FPS);

    }

    /* Release resources */
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(wind);
    SDL_Quit();

    return 0;
}
