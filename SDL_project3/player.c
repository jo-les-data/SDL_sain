#include <SDL.h>
#include <stdbool.h>
#include "player.h"

#define WIDTH 1200
#define HEIGHT 800
#define SIZE 100
#define SPEED 600
#define GRAVITY 60
#define JUMP -1200


void playerInit(Player* ptr,  int x, int y)
{


        ptr->jump_pressed = false;
        ptr->left_pressed = false;
        ptr->right_pressed = false;

        ptr->x_pos = x;
        ptr->y_pos = y;
        ptr->x_vel = 0;
        ptr->y_vel = 0;

        SDL_Rect rect = { (int)ptr->x_pos, (int)ptr->y_pos, SIZE, SIZE };


        ptr->rect = rect;



}


void movement(Player* p)
{
    /* Move the rectangle */
    p->x_vel = (p->right_pressed - p->left_pressed) * SPEED;
    p->y_vel += GRAVITY;




    if (p->jump_pressed)
    {
        p->y_vel = JUMP;

    }



    p->x_pos += p->x_vel / 60;
    p->y_pos += p->y_vel / 60;



    if (p->x_pos <= 0)
    {
        p->x_pos = 0;
    }







    if (p->x_pos >= WIDTH - p->rect.w)
    {
        p->x_pos = WIDTH - p->rect.w;
    }


    if (p->y_pos <= 0)
    {
        p->y_pos = 0;
    }




    if (p->y_pos >= HEIGHT - p->rect.h)
    {
        p->y_vel = 0;
        p->y_pos = HEIGHT - p->rect.h;


    }




    p->rect.x = (int)p->x_pos;
    p->rect.y = (int)p->y_pos;


}

