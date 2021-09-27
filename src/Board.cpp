/*
 * Board.cpp
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#include "Board.h"
#include "Pawn.h"
#include <stdio.h>
#include <stdbool.h>

Board::Board() {
	// TODO Auto-generated constructor stub
	this->initBoard();
	this->displayBoard();

}

Board::~Board() {
	// TODO Auto-generated destructor stub
}

// "r" = red pawn
// "R" = red king
// "b" = black pawn
// "B" = black king
// "-" = empty space
void Board::displayBoard()
{
	for(int i = 0; i < BOARD_SIZE; i++) {
		for(int j = 0; j < BOARD_SIZE; j++) {
			if( ( i + j) % 2 == 0) { // white spaces on even board places
				printf("-");
			}
			else {
				bool found = false;
				for(Pawn* p: Pieces) {
					if(p->returnPosition()->col == j && p->returnPosition()->row == i && !p->taken) {
						//there is a pawn there
						if(p->color) { //true = black, false = red
							if(p->king) {
								printf("B");
								found = true;
								break;
							}
							else {
								printf("b");
								found = true;
								break;
							}
						}
						else {
							if(p->king) {
								printf("R");
								found = true;
								break;
							}
							else {
								printf("r");
								found = true;
								break;
							}
						}
					}
				}
				if(!found) {
					printf("-");
				}

			}
		}
		puts("");
	}
}
void Board::printToFile(char* filename)
{
	//TODO
}

void Board::initBoard(){

	Pieces[0] = new Pawn(false, 0, 1);
	Pieces[1] = new Pawn(false, 0, 3);
	Pieces[2] = new Pawn(false, 0, 5);
	Pieces[3] = new Pawn(false, 0, 7);
	Pieces[4] = new Pawn(false, 1, 0);
	Pieces[5] = new Pawn(false, 1, 2);
	Pieces[6] = new Pawn(false, 1, 4);
	Pieces[7] = new Pawn(false, 1, 6);
	Pieces[8] = new Pawn(false, 2, 1);
	Pieces[9] = new Pawn(false, 2, 3);
	Pieces[10] = new Pawn(false, 2, 5);
	Pieces[11] = new Pawn(false, 2, 7);
	Pieces[12] = new Pawn(true, 5, 0);
	Pieces[13] = new Pawn(true, 5, 2);
	Pieces[14] = new Pawn(true, 5, 4);
	Pieces[15] = new Pawn(true, 5, 6);
	Pieces[16] = new Pawn(true, 6, 1);
	Pieces[17] = new Pawn(true, 6, 3);
	Pieces[18] = new Pawn(true, 6, 5);
	Pieces[19] = new Pawn(true, 6, 7);
	Pieces[20] = new Pawn(true, 7, 0);
	Pieces[21] = new Pawn(true, 7, 2);
	Pieces[22] = new Pawn(true, 7, 4);
	Pieces[23] = new Pawn(true, 7, 6);
}

void Board::initBoard(Pawn* pawnArray[]){

	for(int i = 0; i < 24; i++){
			Pieces[i] = pawnArray[i];
		}


}

void Board::movePiece(Pawn* p, Position* newPos){

	//p->pos->col = newPos->col;
	//p->pos->row = newPos->row;


}

bool Board::checkIsWin(){
	bool winState = false;
	bool blackWin = false;
	bool redTakenStreak = true;
	bool blackTakenStreak = true;
	for(int i = 0; i < 12; i++){	//check if reds were taken
		if (!Pieces[i]->taken){
			redTakenStreak = false;
		}
	}
	if (redTakenStreak){
		//all reds have been taken, black wins
		puts("Black Won!");
		winState = true;
	}
	for(int i = 12; i < 24; i++){
		if (!Pieces[i]->taken){
			blackTakenStreak = false;
		}
	}
	if (blackTakenStreak){
		puts("Red Won!");
		winState = true;
	}

	return winState;

}








