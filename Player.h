/*
 * Player.h
 *
 *  Created on: Dec 14, 2017
 *      Author: sajitgurubacharya
 */
#ifndef PLAYER_H_
#define PLAYER_H_
#include "Board.h"
#include "Game.h"
#include <vector>

class Player {
protected:
	Board playerBoard;
public:
	virtual void getMove(Board b,int& x, int& y);
	void updateBoard(Board b);
	int getType(int);
	virtual ~Player() {}
	char getPlayerName(int);
};

char Player::getPlayerName(int index){
	if (index==0){
		return 'H';
	}
	else if (index==1){
		return 'M';
	}
	else{
		return 'R';
	}
}
void Player::getMove(Board b,int& x, int& y) {
}
int Player::getType(int index) {
	return index;
}

void Player::updateBoard(Board b) {
	playerBoard = b;
}

#endif
