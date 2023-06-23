#pragma once
#include <SDL.h>
#include <stdbool.h>
#include "player.h"
void update(bool running, Player* p1, Player* p2, SDL_Renderer* rend, SDL_Texture* texturebu, SDL_Texture* texturerab, SDL_Texture* texture);