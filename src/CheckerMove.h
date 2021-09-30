/*
 * CheckerMove.h
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#ifndef CHECKERMOVE_H_
#define CHECKERMOVE_H_
#include "Board.h"
#include <list>

typedef struct possibleMoveNode{
		Position* pawnLoc;
		Position* moveLoc;
	}possibleMoveNode;

class CheckerMove {

public:
	CheckerMove();
	virtual ~CheckerMove();
	bool isLegal(Board* board, Position* pawn, Position* possibleMove); // board state, start pos (struct), end pos (struct),
	void findAllLegalMoves(Board* board, bool side); //true = black move, false = red move.
	std::list<possibleMoveNode> moves;
	void printMoves();
};



#endif /* CHECKERMOVE_H_ */
