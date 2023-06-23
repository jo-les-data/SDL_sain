#include <SDL.h>
#include <stdbool.h>
#include "player.h"


// Definition des constantes
#define WIDTH 1200
#define HEIGHT 800
#define SIZE 100
#define SPEED 600
#define GRAVITY 60
#define JUMP -1200
#define MAX_JUMP 2


// Initialisation du joueur avec les positions x et y
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



// Fonction de deplacement du joueur
void movement(Player* p)
{
    // Deplacements verticaux et horizontaux du joueur
    p->x_vel = (p->right_pressed - p->left_pressed) * SPEED;
    p->y_vel += GRAVITY;

    // Le joueur monte si il est en train de sauter
    if (p->jump_pressed && (p->jumpCount <= MAX_JUMP ))
    {
            p->y_vel = JUMP;
    }

    // Deplacement du joueur en fonction de la vitesse
    p->x_pos += p->x_vel / 60;
    p->y_pos += p->y_vel / 60;


    // Protections pour emp�cher le joueur de traverser les limites
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
        p->jumpCount = 0;
        p->y_vel = 0;
        p->y_pos = HEIGHT - p->rect.h;
    }



    // Assignation des positions au sprite du joueur
    p->rect.x = (int)p->x_pos;
    p->rect.y = (int)p->y_pos;


}

