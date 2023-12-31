#pragma once
#include "interaction.h"
#include "player.h"
#include "update.h"
#include "set.h"
#include "constante.h"



/*Le chasseur remporte la victoire quand il rentre en contact
avec la proie (il l'attrape)*/
void victoireChasseur(Player* player1, Player* player2)
{
    if (SDL_HasIntersection(&player1->rect, &player2->rect) == SDL_TRUE)
    {
        if (player1->isPrey)
        {
            player2->score++;
        }
        else
        {
            player1->score++;
        }
        resetGame(player1, player2);
        SDL_Delay(1000);
    }
}

void victoireProie(Player* player1, Player* player2)
{
    if (player1->isPrey && player1->x_pos >= WIDTH - SIZE - 10)
    {
        player1->score++;
        resetGame(player1, player2);
        SDL_Delay(1000);
    }
    else if (player2->isPrey && player2->x_pos <= 10)
    {
        player2->score++;
        resetGame(player1, player2);
        SDL_Delay(1000);
    }
}


// Fonction update
void update(bool running, Player* p1, Player* p2, SDL_Renderer* rend,
    SDL_Texture* textureBu, SDL_Texture* textureRab, SDL_Texture* textureCar, 
    SDL_Texture* texture,  SDL_Rect *obstacle)
{
    SDL_Event event;


    while (running)
    {
        // Verification des touches appuyees
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                running = false;
                break;


                // Changement de l etat des boutons quand les touches sont appuyees
            case SDL_KEYDOWN:
                switch (event.key.keysym.scancode)
                {
                case SDL_SCANCODE_UP:
                    p2->jump_pressed = true;
                    p2->jumpCount++;
                    break;

                case SDL_SCANCODE_LEFT:
                    p2->left_pressed = true;
                    break;

                case SDL_SCANCODE_RIGHT:
                    p2->right_pressed = true;
                    break;

                case SDL_SCANCODE_W:
                    p1->jump_pressed = true;
                    p1->jumpCount++;
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


                //Changement de l'etat des boutons quand les touches sont enleves
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

        // Nettoyage de l'ecran
        SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
        SDL_RenderClear(rend);

        // Calcul des nouvelles positions
        movement(p1,obstacle);
        movement(p2,obstacle);

        // calcule des interactions
        victoireChasseur(p1, p2);
        victoireProie(p1, p2);


        // Dessine les sprite en fonction des nouvelles positions
        SDL_SetRenderDrawColor(rend, 255, 0, 0, 255);
        SDL_RenderFillRect(rend, &p1->rect);
        SDL_RenderFillRect(rend, &p2->rect);
        

        // Affichage des sprite et definition du pas 
        SDL_RenderCopy(rend, texture, NULL, NULL);
        if (p1->isPrey == true)
        {
            SDL_Rect rectCarrot = {WIDTH-SIZE, HEIGHT/2+SIZE, SIZE, SIZE };
            SDL_RenderCopy(rend, textureCar, NULL, &rectCarrot);

        }
        else if (p2->isPrey == true)
        {
            SDL_Rect rectCarrot = { 0, HEIGHT / 2+SIZE, SIZE, SIZE };
            SDL_RenderCopy(rend, textureCar, NULL, &rectCarrot);

        }


        SDL_RenderCopy(rend, textureBu, NULL, &p1->rect);
        SDL_RenderCopy(rend, textureRab, NULL, &p2->rect);
        SDL_RenderFillRect(rend, obstacle);
        SDL_RenderPresent(rend);
        SDL_Delay(1000 / FPS);

    }
}
