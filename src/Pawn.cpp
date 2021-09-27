/*
 * Pawn.cpp
 *
 *  Created on: Sep 25, 2021
 *      Author: paulg
 */

#include "Pawn.h"
#include <stdio.h>
#include <stdbool.h>
Pawn::Pawn(bool _color, int _row, int _col) {
	 color = _color;
	 king = false;
	 taken = false;
	 pos = new Position();
	 pos->col = _col;
	 pos->row = _row;
}

Pawn::Pawn() {
	 color = false;
	 king = false;
	 taken = false;
	 pos = new Position();
	 pos->col = 0;
	 pos->row = 0;
}

Pawn::~Pawn() {
	// TODO Auto-generated destructor stub
}

void Pawn::makeMove(Position* pos1)
{
	pos->col = pos1->col;
	pos->row = pos1->row;
}

Position* Pawn::returnPosition()
{
		 return pos;
}

void Pawn::makeKing(){
	king = true;
}

void Pawn::takePawn(){
	taken = true;
	pos->col = -1;
	pos->row = -1;

}
