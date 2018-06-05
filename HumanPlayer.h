/*
 * HumanPlayer.h
 *
 *  Created on: Dec 15, 2017
 *      Author: sajitgurubacharya
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_
#include "Player.h"
using namespace std;

class humanPlayer: public Player {
	void getMove(Board b,int& x, int& y);
};

void humanPlayer::getMove(Board b,int& x, int& y) {

	while (true) {
		cout << "Y and X positions\nX:";
		cin >> y;
		cout << "\nY: ";
		cin >> x;
		if (playerBoard.validInput(x, y)) {
			break;
		}
		cout << "\nInvalid Move! Please re-enter!\n";
	}

}

#endif /* HUMANPLAYER_H_ */
