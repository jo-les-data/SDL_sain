#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include "player.h"

void colorIntersection(SDL_Renderer* rend, SDL_Rect* rect1, SDL_Rect* rect2);
void colision(Player* player, SDL_Rect* obstacle);