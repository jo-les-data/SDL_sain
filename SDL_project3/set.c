#include "player.h"


#define HEIGHT 800
#define SIZE 100
#define WIDTH 1200


// Reset des positions

void setGame(Player* p1, Player* p2)
{
    int start = HEIGHT - SIZE;

    


    playerInit(p1, 0, start);
    playerInit(p2, WIDTH, start);

}