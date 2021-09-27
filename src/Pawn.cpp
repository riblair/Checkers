/*
 * Pawn.cpp
 *
 *  Created on: Sep 25, 2021
 *      Author: paulg
 */

#include "Pawn.h"
#include <stdio.h>
#include <stdbool.h>
Pawn::Pawn() {
	 color = false;
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
