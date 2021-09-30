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
	moves.clear();
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
	Pawn* thePawn;
	for(Pawn* pawns: board->Pieces)
	{
		if(pawn->col == pawns->pos->col && pawn->row == pawns->pos->row)
		{
			thePawn = pawns;
		}
	}
	for(Pawn* pawns: board->Pieces)
	{
		if(possibleMove->col == pawns->pos->col && possibleMove->row == pawns->pos->row) {
			return false;
		}
	}
	//possibleMove out of bounds
	if(possibleMove->col < 0 || possibleMove->col > 7 || possibleMove->row < 0 || possibleMove->row > 7 )
	{
		return false;
	}
	else
	{

		//checks if there is a pawn in possibleMove
		if(possibleMove->col == thePawn->pos->col && possibleMove->row == thePawn->pos->row) {
			return false;
		}
		//checks for a pawn in pawn position
		else if(pawn->col == thePawn->pos->col && pawn->row == thePawn->pos->row)
		{
			//checks pawn is not a king
			if(!thePawn->king)
			{
				if(thePawn->color) //if black
				{
					if(thePawn->pos->row <= possibleMove->row)//if move is backwards
					{

						return false;
					}
				}
				else //if red
				{
					if(thePawn->pos->row >= possibleMove->row)//if move is backwards
					{
						return false;
					}
				}
			}
			int distance = abs(thePawn->pos->row - possibleMove->row);
			if(distance == 1) //no pawn in the way, and the distance is one, return true
			{
				return true;
			}
			else //know that possibleMove is two away
			{
				int dy = (possibleMove->row - thePawn->pos->row)/2;
				int dx = (possibleMove->col - thePawn->pos->col)/2;
				Position* between = new Position();
				between->row = (possibleMove->row - dy);
				between->col = (possibleMove->col - dx);

				for(Pawn* capture: board->Pieces)
				{
					//check that there is a pawn in between possibleMove and pawn position
					if(between->col == capture->pos->col && between->row == capture->pos->row) {
						//checks that the pawns are opposite color
						if(capture->color != thePawn->color)
						{
							return true;
						}
						return false;
					}

				}
			}

		}
	}

	return false;
}


void CheckerMove::findAllLegalMoves(Board* board, bool side) {

	moves.clear();


	//for each pawn
	// check if the color matches the side
	// for each of thier positions, +1,+2,-1,-2
	//if move is legal
	// record it to moves List.
	for(Pawn* pawn: board->Pieces)
	{
		if(pawn->color == side)
		{
			for(int x = -2; x<3; x++)
			{
				if(x != 0)
				{
					Position* possibleMove = new Position;
					possibleMove->row = pawn->pos->row + x;
					possibleMove->col = pawn->pos->col + x;
					if(isLegal(board,pawn->pos,possibleMove))
					{
						possibleMoveNode made;
						made.pawnLoc = pawn->pos;
						made.moveLoc = possibleMove;
						moves.push_back(made);
					}
					Position* possibleMove2 = new Position;
					possibleMove2->row = pawn->pos->row - x;
					possibleMove2->col = pawn->pos->col + x;
					if(isLegal(board,pawn->pos,possibleMove2))
					{
						possibleMoveNode made;
						made.pawnLoc = pawn->pos;
						made.moveLoc = possibleMove2;
						moves.push_back(made);

					}
				}

			}
		}
	}
}

void CheckerMove::printMoves()
{
	for(possibleMoveNode theMove : moves) {
		printf("WE ARE MOVING PAWN AT (%d,%d), TO (%d,%d) \n", theMove.pawnLoc->row,theMove.pawnLoc->col,theMove.moveLoc->row,theMove.moveLoc->col);
	}
}
