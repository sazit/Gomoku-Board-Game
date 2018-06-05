/*
 * monteCarlo.h
 *
 *  Created on: Jan 2, 2018
 *      Author: sajitgrubacharya
 */

#ifndef MONTECARLO_H_
#define MONTECARLO_H_

#include "Player.h"
#include <ctime>
#include <vector>
using namespace std;

class monteCarlo: public Player {
	void getMove(Board b, int& x, int& y);
	int simulationPoints(Board);
	int sims;
public:
	monteCarlo();
	monteCarlo(int x);
};

monteCarlo::monteCarlo() {
	sims = 500;
}
monteCarlo::monteCarlo(int s) {
	sims = s;
}

void monteCarlo::getMove(Board b, int& x, int& y) {
	Board monteBoard = b;
	int point[BOARDSIZE][BOARDSIZE];
	vector<int> emptySpots;
	emptySpots.clear();
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			point[i][j] = 0;
			if (monteBoard.grid[i][j] == ' ') {
				emptySpots.push_back(i * BOARDSIZE + j);
			}
		}
	}
	int currentCapacity = emptySpots.size();
	for (int i = 0; i < currentCapacity; i++) {
		Board tempBoard = monteBoard;
		tempBoard.addMove(1, emptySpots[emptySpots.size() - 1] / BOARDSIZE,
				emptySpots[emptySpots.size() - 1] % BOARDSIZE);
		point[emptySpots[emptySpots.size() - 1] / BOARDSIZE][emptySpots[emptySpots.size()
				- 1] % BOARDSIZE] = simulationPoints(tempBoard);
		if (emptySpots.size() != 0) {
			emptySpots.pop_back();
		}
	}
	int tempMax = 0;
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			if (point[i][j] > tempMax) {
				tempMax = point[i][j];
				cout << "\nCurrent MAX: " << tempMax << "\n";
				x = i;
				y = j;
			}
		}
	}
}


int monteCarlo::simulationPoints(Board b) {
	int currentPoints = 0;
	int currentRandom = 0;
	for (int mat = 0; mat < sims; mat++) {
		Board simBoard = b;
		vector<int> simEmptySpots;
		simEmptySpots.clear();
		for (int i = 0; i < BOARDSIZE; i++) {
			for (int j = 0; j < BOARDSIZE; j++) {
				if (simBoard.grid[i][j] == ' ') {
					simEmptySpots.push_back(i * BOARDSIZE + j);
				}
			}
		}
		int currentCapacity = simEmptySpots.size();
		for (int i = 0; i < currentCapacity; i++) {
			int iMOD2 = 1;
			if (i % 2 == 0) {
				iMOD2 = 0;
			}
			currentRandom = rand() % simEmptySpots.size();
			simBoard.addMove(iMOD2, simEmptySpots[currentRandom] / BOARDSIZE,
					simEmptySpots[currentRandom] % BOARDSIZE);
			simEmptySpots.erase(simEmptySpots.begin() + currentRandom);
			if (simBoard.checkWin_v3(iMOD2, 5)) {
				currentPoints++;
				break;
			}
		}
	}
	return currentPoints;
}
#endif /* MONTECARLO_H_ */
