#include "player.h"


#define HEIGHT 800
#define SIZE 100
#define WIDTH 1200


// Reset des positions

bool setGame(Player* p1, Player* p2)
{
    int start_y = HEIGHT - SIZE;

    playerInit(p1, 0, start_y, true);
    playerInit(p2, WIDTH, start_y, false);
    return true;
}

void resetGame(Player* p1, Player* p2)
{
    int start_y = HEIGHT - SIZE;
    if (p1->score + p2->score % 3 == 0)
    {
        p1->isPrey = !(p1->isPrey);
        p2->isPrey = !(p2->isPrey);
    }

    playerInitPos(p1, 0, start_y);
    playerInitPos(p2, WIDTH, start_y);
}