/*
 * Board.h
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <stdio.h>

#define BOARD_SIZE 8



class Board {
public:
	Board();
	virtual ~Board();
	void displayBoard();
	void printToFile(char* filename);
	void Board::initBoard();


};

#endif /* BOARD_H_ */
