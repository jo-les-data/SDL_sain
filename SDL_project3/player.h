#pragma once

#include <SDL.h>
#include <stdbool.h>

typedef struct Player
{
    bool jump_pressed;
    bool left_pressed;
    bool right_pressed;
    int x_pos;
    int y_pos;
    int x_vel;
    int y_vel;
    SDL_Rect rect;

} Player;

void playerInit(Player* ptr, int x, int y);