/*
 * classes.h
 *
 *  Created on: Dec 13, 2017
 *      Author: sajitgurubacharya
 */

#ifndef GAME_H_
#define GAME_H_
using namespace std;
const int BOARDSIZE = 8;
#include "Board.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "RandomPlayer.h"
#include "monteCarlo.h"
#include <vector>

class Game {
	int winning;
	Player** player;
	int initPlayers[2];
	int wins[2];
	int total;
public:
	Board board;
	int draw_;
	void play(int);
	Game();
	~Game();
	void resetBoard();
};
Game::Game() {
	total = 0;
	for (int i = 0; i < 2; i++) {
		wins[i] = 0;
	}
	player = new Player*[2];
	winning = 5;
	draw_ = 0;

	cout
			<< "Please input player type (0 for human,1 for monteCarlo 2 for random) to play against monteCarlo!\n";
	cout << "Player 1: ";
	cin >> initPlayers[0];
	cout << "Player 2: ";
	cin >> initPlayers[1];

	for (int i = 0; i < 2; i++) {
		if (initPlayers[i] == 0) {
			player[i] = new humanPlayer;
		} else if (initPlayers[i] == 1) {
			int simul = 0;
			cout << "How many simulations for monteCarlo player " << i
					<< "? \nEnter 0 for default: ";
			cin >> simul;
			if (simul == 0) {
				player[i] = new monteCarlo;
			} else {
				player[i] = new monteCarlo(simul);
			}

		} else if (initPlayers[i] == 2) {
			player[i] = new randomPlayer;
		}

	}
}
Game::~Game() {
	delete player;
}

void Game::resetBoard() {
	board.reset();
}
void Game::play(int totals) {
	for (int i = 0; i < totals; i++) {
		resetBoard();
		int index = 0;
		int counter = 0;
		while (true && counter < BOARDSIZE * BOARDSIZE) {
			counter++;
			if (counter == BOARDSIZE * BOARDSIZE + 1) {
				cout << "DRAW!\n\n";
				draw_ = 1;
				break;
			}
			int x, y;
			player[index]->updateBoard(board);
			player[index]->getMove(board, x, y);
			board.addMove(player[index]->getType(index), x, y);
			board.printBoard();
			if (board.checkWin_v3(player[index]->getType(index), winning)) {
				cout << "GAME WON BY PLAYER "
						<< player[index]->getType(index) + 1 << "!\n";
				wins[index]++;
				break;
			}
			index = (index + 1) % 2;
		}
	}
	cout << "\nFirst player wins: " << wins[0];
	cout << "\nSecond player wins: " << wins[1];
	cout << "\nWins: " << wins[0] + wins[1];
	cout << " \nRow: " << *board.getWins() << " Col: " << *(board.getWins() + 1)
			<< " BDiag: " << *(board.getWins() + 2) << " FDiag:"
			<< *(board.getWins() + 3);
}

#endif /* GAME_H_ */
