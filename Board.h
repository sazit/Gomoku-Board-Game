/*
 * Board.h
 *
 *  Created on: Dec 14, 2017
 *      Author: sajitgurubacharya
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <iomanip>

#include "Game.h"

class Board {
	int moveCounter;
	int wins[4];
public:
	int* getWins();
	int getMoveCounter();
	bool addMove(int player, int x, int y);
	bool validInput(int, int);
	void printBoard();
	Board();
	bool checkWin_v3(int, int);
	void reset();
	char grid[BOARDSIZE][BOARDSIZE];
};

int* Board::getWins(){
	return wins;
}
int Board::getMoveCounter() {
	return moveCounter;
}

void Board::reset() {
	moveCounter = 0;
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			grid[i][j] = ' ';
		}
	}
}
bool Board::checkWin_v3(int player, int length) {
	char playerPiece = ' ';
	if (player == 0) {
		playerPiece = 'X';
	} else if (player == 1) {
		playerPiece = 'O';
	}

	// rows
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j <= BOARDSIZE - length; j++) {
			bool win = true;
			for (int inner = 0; inner < length; inner++) {
				if (win) {
					win = (grid[i][j + inner] == playerPiece);
				}
			}
			if (win) {
				wins[0]++;
				//cout << playerPiece << " ROW (" << i << ")\n";
				return true;
			}
		}
	}

	//columns
	for (int i = 0; i <= BOARDSIZE - length; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			bool win = true;
			for (int inner = 0; inner < length; inner++) {
				if (win) {
					win = (grid[i + inner][j] == playerPiece);
				}
			}
			if (win) {
				wins[1]++;
				//cout << playerPiece << " COULMN (" << j << ")\n";
				return true;
			}
		}
	}

	//backward diagonal
	for (int i = 0; i <= BOARDSIZE - length; i++) {
		for (int j = BOARDSIZE - 1; j >= length - 1; j--) {
			bool win = true;
			for (int inner = 0; inner < length; inner++) {
				if (win) {
					win = (grid[i + inner][j - inner] == playerPiece);
				}
			}
			if (win) {
				//cout << playerPiece << " BDIAGONAL!\n";
				wins[2]++;
				return true;
			}

		}
	}

	//forward diagonal
	for (int i = 0; i <= BOARDSIZE - length; i++) {
		for (int j = 0; j <= BOARDSIZE - length; j++) {
			bool win = true;
			for (int inner = 0; inner < length; inner++) {
				if (win) {
					win = (grid[i + inner][j + inner] == playerPiece);
				}
			}
			if (win) {
				//cout << playerPiece << " FDIAGONAL!\n";
				wins[3]++;
				return true;
			}
		}
	}
	return false;

}

bool Board::addMove(int player, int x, int y) {
	if (player == 0) {
		grid[x][y] = 'X';
		return true;
	} else if (player == 1) {
		grid[x][y] = 'O';
		return true;
	} else {
		cout << "\nInvalid Player Piece!\n";
		return false;
	}
}

bool Board::validInput(int x_coord, int y_coord) {
	if (x_coord < BOARDSIZE && y_coord < BOARDSIZE
			&& grid[x_coord][y_coord] == ' ') {
		return true;
	} else {
		return false;
	}
}

void Board::printBoard() {
	moveCounter++;
	cout << endl << endl;
	for (int row = BOARDSIZE - 1; row >= 0; row--) {
		cout << row;
		for (int col = 0; col < BOARDSIZE; col++) {
			cout << setw(3) << grid[row][col];
			if (col != BOARDSIZE)
				cout << " |";
		}
		cout << endl;
		cout << "  ";
		if (row != 0)
			cout << endl;
	}
	for (int i = 0; i < BOARDSIZE; i++) {
		cout << " " << i << "   ";
	}
	cout << endl;
}

Board::Board() {
	for (int i=0;i<4;i++){
		wins[i]=0;
	}
	moveCounter = 0;
	for (int i = 0; i < BOARDSIZE; i++) {
		for (int j = 0; j < BOARDSIZE; j++) {
			grid[i][j] = ' ';
		}
	}
}

#endif /* BOARD_H_ */
