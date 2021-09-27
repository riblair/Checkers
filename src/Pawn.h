/*
 * Pawn.h
 *
 *  Created on: Sep 25, 2021
 *      Author: paulg
 */

#ifndef SRC_PAWN_H_
#define SRC_PAWN_H_
#include <stdio.h>
#include <stdbool.h>
//reminder that (0,0) starts in the topleft
typedef struct Position
{
	int row;
	int col;
}Position;


class Pawn {
public:
	Pawn::Pawn(bool _color, int _col, int _row);
	Pawn();
	virtual ~Pawn();
	void makeMove(Position* pos);
	Position* returnPosition();
	bool color; //true for black, false for red?
	bool king;
private:
	Position* pos;
};

#endif /* SRC_PAWN_H_ */
