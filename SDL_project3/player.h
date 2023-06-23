#pragma once

#include <SDL.h>
#include <stdbool.h>



// Definition du joueur
typedef struct Player
{
    // Deplacement du joueur
    bool jump_pressed;
    bool left_pressed;
    bool right_pressed;

    // Position du joueur
    int x_pos;
    int y_pos;

    // Vitesse du joueur
    int x_vel;
    int y_vel;

    // Compteur de saut
    int jumpCount;

    // Sprite du joueur
    SDL_Rect rect;
    
    // est-ce une proie, si false, alors c'est un chasseur
    bool isPrey;

    // nombre de vistoire
    int score;

} Player;

void playerInit(Player* ptr, int x, int y, bool isPrey);
void playerInitPos(Player* ptr, int x, int y);