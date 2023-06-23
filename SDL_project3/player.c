#include <SDL.h>
#include <stdbool.h>
#include "player.h"
#include "constante.h"


// Initialisation du joueur avec les positions x et y
void playerInit(Player* ptr,  int x, int y, bool isPrey)
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
        ptr->isPrey = isPrey;
        ptr->score = 0;
}

// Initialisation du joueur avec les positions x et y
void playerInitPos(Player* ptr, int x, int y)
{
    ptr->x_pos = x;
    ptr->y_pos = y;
    ptr->x_vel = 0;
    ptr->y_vel = 0;

    SDL_Rect rect = { (int)ptr->x_pos, (int)ptr->y_pos, SIZE, SIZE };

    ptr->rect = rect;
}

// Fonction de deplacement du joueur
void movement(Player* p, SDL_Rect * obstacle)
{
    // Deplacements verticaux et horizontaux du joueur
    p->x_vel = (p->right_pressed - p->left_pressed) * SPEED;
    p->y_vel += GRAVITY;

    // Le joueur monte si il est en train de sauter
    if (p->jump_pressed && (p->jumpCount <= MAX_JUMP ))
    {
        // Passage du booleen a false pour empecher les sauts infinis
        p->jump_pressed = false;
        
        p->y_vel = JUMP;
    }

    // Deplacement du joueur en fonction de la vitesse
    p->x_pos += p->x_vel / 60;
    p->y_pos += p->y_vel / 60;


    // Protections pour empecher le joueur de traverser les limites
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
        // Reinitialisation du compteur de saut si le joueur retourne en bas
        p->jumpCount = 0;
        p->y_vel = 0;
        p->y_pos = HEIGHT - p->rect.h;
    }

    colision(p, obstacle);


    // Assignation des positions au sprite du joueur
    p->rect.x = (int)p->x_pos;
    p->rect.y = (int)p->y_pos;


}

