#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL.h>
#include "player.h"
#include "set.h"
#include "constante.h"

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
			if (player->y_pos > obstacle->y)
			{
				player->y_pos = obstacle->y + obstacle->h + 10;
				player->rect.y = obstacle->y + obstacle->h + 10;
			}
			else
			{
				player->y_pos = obstacle->y - player->rect.h - 1;
				player->rect.y = obstacle->y - player->rect.h - 1;
				player->jumpCount = 0;
			}
		}
		/*si l'intersection est verticale, c'est que le joueur est entre
		en contact avec l'obstacle par la gauche en allant vers la droite
		ou par la doite en allant vers la gauche. Dans les deux cas, on
		change le signe de ca vitesse horizontale*/
		else if (intersect.w < intersect.h)
		{
			player->x_vel = -player->x_vel;
			if (player->x_pos > obstacle->x)
			{
				player->x_pos = obstacle->x + obstacle->w + 1;
				player->rect.x = obstacle->x + obstacle->w + 1;
				player->jumpCount = 0;
			}
			else
			{
				player->x_pos = obstacle->x - player->rect.w - 1;
				player->rect.x = obstacle->x - player->rect.w - 1;
				player->jumpCount = 0;
			}
		}
	}
}