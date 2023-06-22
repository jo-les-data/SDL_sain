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

void colision(Player* player1, Player* player2)
{
	SDL_Rect intersect;
	SDL_bool hasIntersect = SDL_HasIntersection(&(player1->rect), &(player2->rect), &intersect);
	if (hasIntersect == SDL_TRUE)
	{
		float x_v = player1->x_vel;
		float y_v = player1->y_vel;
		player1->x_vel = player2->x_vel;
		player1->y_vel = player2->y_vel;
		player2->x_vel = x_v;
		player2->y_vel = y_v;
	}
}