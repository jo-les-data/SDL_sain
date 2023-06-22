#include <SDL.h>
#include <stdbool.h>
#include "player.h"

#define SIZE 100


Player* playerInit(int x, int y)
{

    Player* ptr = (Player*)malloc(sizeof(Player));

    if (ptr != NULL)
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
        return ptr;




    }
    else
    {
        return NULL;
    }


}