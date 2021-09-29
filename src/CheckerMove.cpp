/*
 * CheckerMove.cpp
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#include "CheckerMove.h"

CheckerMove::CheckerMove() {
	// TODO Auto-generated constructor stub

}

CheckerMove::~CheckerMove() {
	// TODO Auto-generated destructor stub
}

bool CheckerMove::isLegal(Board* board, Position* pawn, Position* possibleMove) { //need to fix Stub once Board is updated
	// TODO Make method after peices classes r created and Board is done

	//Check if possibleMove pos is out of bounds,
	//Check if a pawn is in possibleMove pos,
		// if true, return false;
	//Check if pawn is king
		// if false
			//if pawn is red && move is backwards
				// return false
			//if pawn is black && move is backwards
				// return false

	// if move is 1 space away, return true.
	// else (if 2 move away)
		// check if pawn exists in between pawn pos and possibleMove pos
			// if a pawn exists && is of the opposite color,
				// return true
			// else return false


	return false;
}
