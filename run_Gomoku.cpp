#include <iostream>
using namespace std;
#include "Game.h"
#include "Board.h"
#include "Player.h"
int main() {
	/*
	 * Implement 2D vectors
	 * Implement better random move algorithm.
	 */
	srand(time(0));
	clock_t begin = clock();
	double elapsed_secs = 0;
	Game game;
	game.play(1);
	clock_t end = clock();
	elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "\nTOTAL TIME: " << elapsed_secs;
	return 0;

}

