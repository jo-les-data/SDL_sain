

#include "player.h"


// Constantes
#define WIDTH 1200
#define HEIGHT 800
#define FPS 60
#define SIZE 100



// Fonction update
void update(bool running, Player* p1, Player* p2, SDL_Renderer* rend, SDL_Texture* texturebu, SDL_Texture* texture)
{
    SDL_Event event;


    while (running)
    {
        // Verification des touches appuy�es
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;


                // Changement de l'�tat des boutons quand les touches sont appuy�es
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


                //Changement de l'�tat des boutons quand les touches sont enlev�s
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

        // Nettoyage de l'�cran
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);

        // Calcul des nouvelles positions
        movement(p1);
        movement(p2);



        // Dessine les sprite en fonction des nouvelles positions
        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        SDL_RenderFillRect(rend, &p1->rect);
        SDL_RenderFillRect(rend, &p2->rect);

        // Affichage des sprite et d�finition du pas 
        SDL_RenderCopy(rend, texture, NULL, NULL);
        SDL_RenderCopy(rend, texturebu, NULL, &p1->rect);
        SDL_RenderCopy(rend, texturebu, NULL, &p2->rect);
        SDL_RenderPresent(rend);
        SDL_Delay(1000 / FPS);

    }
}
