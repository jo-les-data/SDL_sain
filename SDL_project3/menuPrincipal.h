#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

typedef struct Button {
	//defini l'�tat du bouton : 0 = rien de se passe ; 1 = curseur situ� sur le bouton ; 2 = bouton cliqu�
	int buttonState;
	// conteneur du bouton
	SDL_Rect* buttonShape;
	// texture qui s'affiche dans le rectangle
	SDL_Texture* buttonFont;
} Button;

void creerFenetrePrincipale(SDL_Renderer* renderer);