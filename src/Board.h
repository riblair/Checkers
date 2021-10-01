/*
 * Board.h
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "Pawn.h"

#include <stdio.h>
#include <stdbool.h>
#include <string>
#include <cstring>
using namespace std;


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
	bool checkIsWin();
	void takePawnAtPosition(Position* pos);
	char* winner = "none";


};

#endif /* BOARD_H_ */
