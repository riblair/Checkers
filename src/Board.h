/*
 * Board.h
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "Board.h"
#include "Pawn.h"
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8



class Board {
public:
	Board();
	virtual ~Board();
	void displayBoard();
	void printToFile(char* filename);
	void Board::initBoard();
	void Board::initBoard(Pawn* pawnArray[]);
	Pawn* Pieces[];
	void Board::movePiece(Pawn* p, Position* newPos);
	bool Board::checkIsWin();


};

#endif /* BOARD_H_ */
