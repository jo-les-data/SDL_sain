#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>

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