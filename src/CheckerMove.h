/*
 * CheckerMove.h
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#ifndef CHECKERMOVE_H_
#define CHECKERMOVE_H_
#include "Board.h"


class CheckerMove {
public:
	CheckerMove();
	virtual ~CheckerMove();
	bool isLegal(Board* board, Position* pawn, Position* possibleMove); // board state, start pos (struct), end pos (struct),
	//mybe more office hours
private:

};



#endif /* CHECKERMOVE_H_ */
