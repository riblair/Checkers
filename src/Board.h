/*
 * Board.h
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "Pawn.h"
//#include "CheckerMove.h"
#include <stdio.h>
#include <stdbool.h>


#define BOARD_SIZE 8



class Board {
public:
	Board();
	virtual ~Board();
	void displayBoard();
	void printToFile(char* filename);
	void initBoard();
	void initBoard(Pawn* pawnArray[]);
	Pawn* Pieces[24];
	bool checkIsWin(CheckerMove* moveToCheck, bool side);
	void takePawnAtPosition(Position* pos);


};

#endif /* BOARD_H_ */
