/*
 * CheckerMove.h
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#ifndef CHECKERMOVE_H_
#define CHECKERMOVE_H_

class CheckerMove {
public:
	CheckerMove();
	virtual ~CheckerMove();
	bool isLegal(); // board state, start pos (struct), end pos (struct),
	//mybe more office hours
};



#endif /* CHECKERMOVE_H_ */
