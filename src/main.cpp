#include "GameManager.h"

// global variables
int score = 0;
int boost_count = 0;
int life_count = 3;

int main()
{
    GameManager game; // handles everything (user input, rendering, etc.) with initialization

    game.Init(); //Initializes game

    return 0;
}