/*
 * CheckerMove.cpp
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#include "CheckerMove.h"
#include <stdlib.h>
#include <stdio.h>

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
	//Check if a pawn exists in pawn positon
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

	//possibleMove out of bounds
	if(possibleMove->col < 0 || possibleMove->col > 7 || possibleMove->row < 0 || possibleMove->row > 7 )
	{
		return false;
	}
	else
	{
		for(Pawn* pawns: board->Pieces)
		{
			//checks if there is a pawn in possibleMove
			if(possibleMove->col == pawns->pos->col && possibleMove->row == pawns->pos->row) {
				return false;
			}
			//checks for a pawn in pawn position
			else if(pawn->col == pawns->pos->col && pawn->row == pawns->pos->row)
			{
				//checks pawn is not a king
				if(!pawns->king)
				{
					if(pawns->color) //if black
					{
						if(pawns->pos->row > possibleMove->row)//if move is backwards
						{
							return false;
						}
					}
					else //if red
					{
						if(pawns->pos->row < possibleMove->row)//if move is backwards
						{
							return false;
						}
					}
				}
				else
				{
					int distance = abs(pawns->pos->row - possibleMove->row);
					if(distance == 1) //no pawn in the way, and the distance is one, return true
					{
						return true;
					}
					else //know that possibleMove is two away
					{
						int dy = (possibleMove->row - pawns->pos->row)/2;
						int dx = (possibleMove->col - pawns->pos->col)/2;
						Position* between = new Position();
						between->row = (possibleMove->row - dy);
						between->col = (possibleMove->col - dx);

						for(Pawn* capture: board->Pieces)
						{
							//check that there is a pawn in between possibleMove and pawn position
							if(between->col == capture->pos->col && between->row == capture->pos->row) {
								//checks that the pawns are opposite color
								if(capture->color != pawns->color)
								{
									return true;
								}
								return false;
							}

						}
					}
				}
			}
		}
	}

	return false;
}
