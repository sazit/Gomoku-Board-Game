/*
 * RandomPlayer.h
 *
 *  Created on: Dec 15, 2017
 *      Author: sajitgurubacharya
 */

#ifndef RANDOMPLAYER_H_
#define RANDOMPLAYER_H_

#include "Player.h"
#include <vector>
using namespace std;

class randomPlayer: public Player {
	vector<int> emptySpots;
public:
	void getMove(Board b, int& x, int& y);
	void emptyCellsArray(Board, vector<int>&);
};

void randomPlayer::emptyCellsArray(Board b, vector<int>& Xs) {
	Xs.clear();
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			if (b.grid[i][j] == ' ') {
				Xs.push_back(i * BOARDSIZE + j);
			}
		}
	}
}

void randomPlayer::getMove(Board b, int& x, int& y) {
	emptyCellsArray(b, emptySpots);
	int currentRandom = rand() % emptySpots.size();
	x = emptySpots[currentRandom] / BOARDSIZE;
	y = emptySpots[currentRandom] % BOARDSIZE;
}

#endif /* RANDOMPLAYER_H_ */
