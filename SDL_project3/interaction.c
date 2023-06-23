#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <SDL.h>
#include "player.h"

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
		if (intersect.w > intersect.h)
		{
			player->y_vel = -player->y_vel;
		}
		else if (intersect.w < intersect.h)
		{
			player->x_vel = -player->x_vel;
		}
	}
}

void victoireChasseur(Player* chasseur, Player* proie)
{
	if (SDL_HasIntersection(chasseur, proie)== SDL_TRUE)
	{
		resetGame();
	}
}