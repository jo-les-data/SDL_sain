#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL.h>
#include "player.h"
#include "set.h"

void colorIntersection(SDL_Renderer* rend, SDL_Rect* rect1, SDL_Rect* rect2)
{
	SDL_Rect intersect;
	SDL_bool hasIntersect = SDL_IntersectRect(rect1, rect2, &intersect);
	printf("%d\n", hasIntersect == SDL_TRUE);
	if (hasIntersect == SDL_TRUE)
	{
		SDL_SetRenderDrawColor(rend, 255, 255, 255, 150);
		SDL_RenderFillRect(rend, &intersect);
	}
}

void colision(Player* player, SDL_Rect* obstacle)
{
	SDL_Rect intersect;
	SDL_bool hasIntersect = SDL_IntersectRect(&(player->rect), obstacle, &intersect);
	if (hasIntersect == SDL_TRUE)
	{
		/*si l'intersection est horizontale, ca veux dir que le joueur 
		est entre en contact avec l'obstacle par en bas en montant ou
		par en hau en descendant, dans les deux cas, on chage le signe
		de ca vitesse verticale*/
		if (intersect.w > intersect.h)
		{
			player->y_vel = -player->y_vel;
		}
		/*si l'intersection est verticale, c'est que le joueur est entre 
		en contact avec l'obstacle par la gauche en allant vers la droite
		ou par la doite en allant vers la gauche. Dans les deux cas, on 
		change le signe de ca vitesse horizontale*/
		else if (intersect.w < intersect.h)
		{
			player->x_vel = -player->x_vel;
		}
	}
}

