/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"
#include "CheckerMove.h"
#include "Board.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <stdbool.h>
#include <cstring>
using namespace std;

Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[])
{
	printf("Starting Production\n");
	bool answer = false;
	int maxMoves = -1;
	bool turnBool = false;
	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);


		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string

			switch(i)
			{
			case 1:
				//this is the bool for turn order (true = black has first move)
				if((strcmp(argv[i], "false") == 0)||(strcmp(argv[i], "False") == 0)){
					turnBool = false;
				}
				else if((strcmp(argv[i], "true") == 0)||(strcmp(argv[i], "True") == 0)){
					turnBool = true;
				}
				else{
					puts("Unexpected argument.");
					fflush(stdout);
				}
				if (turnBool)
					puts("Black goes first");
				else
					puts("Red goes first");
				fflush(stdout);
				break;
			case 2:
				//this is int for maximum number of moves
				maxMoves = atoi(argv[i]);
				printf("The maximum number of moves is %d", maxMoves);
				fflush(stdout);
				break;
			default:
				puts("Unexpected argument count.");
				fflush(stdout);
				answer = false;
				break;

			}
		}

	}
	//Prob need to make the game run here
	Board* theBoard = new Board();
	theBoard->initBoard();
	CheckerMove* gameCheck = new CheckerMove();


	for(int j = 0; j < maxMoves; j++){

		bool gameFinished = theBoard->checkIsWin()

		while (!gameFinished){

			readFile("gameState", theBoard);
			gameCheck->findAllLegalMoves(theBoard, turnBool);
			turnBool = !turnBool;
			int movesSize = (int)gameCheck->moves.size();
			int move = rand() % movesSize;



		}


			//read file
	//find legal moves
	//choose random legal move
	//make move
	//update board (update pawn array
	//output updated board



		}


	}







	return answer;

}

bool Production::readFile(char* filename, Board* theBoard)
{
	bool ok = true;
	char tempo = '-';
	FILE* fp = fopen(filename, "r"); //read the file

	if (fp == NULL)
	{
		puts("Error! opening file");

	}
	else
	{
		Pawn* newBoard[24];
		int pos = 0;
		//TODO read the board from the file,
		for(int row = 0; row < 8; row++)
		{

			for(int col = 0; col < 8; col++)
			{
				fscanf(fp,"%c", &tempo);

				if(tempo == 'r')
				{
					//TODO Create new red pawn, add it to board?
					Pawn* temp = new Pawn(false,row,col);
					newBoard[pos] = temp;
					pos++;
				}
				else if(tempo == 'R')
				{
					//TODO Create new red king, add it to board?
					Pawn* temp = new Pawn(false,row,col);
					temp->makeKing();
					newBoard[pos] = temp;
					pos++;
				}
				else if (tempo == 'b')
				{
					//TODO Create new black pawn, add it to board?
					Pawn* temp = new Pawn(true,row,col);
					newBoard[pos] = temp;
					pos++;

				}
				else if (tempo == 'B')
				{
					//TODO Create new black king, add it to board?
					Pawn* temp = new Pawn(true,row,col);
					temp->makeKing();
					newBoard[pos] = temp;
					pos++;
				}
			}

			fscanf(fp,"%c", &tempo);

		}
		for(int x = pos; x<24; x++)
				{
					Pawn* faulty = new Pawn(true,-1,-1);
					faulty->takePawn();
					newBoard[x] = faulty;
				}

		theBoard->initBoard(newBoard);

		//discover checkers
		//make instances of class checker as needed
		//board needs to keep track of instances of checkers
		//checkers might also know where they are...
		//fscanf(fp,"%c", &temp); //red checker, black, none?
		//red checker, black, none?
		//notice, this reads only one character, and <CR> is a character
		//notice, this reads only one character, and <CR> is a character

	}
	fclose(fp);

	return ok;
}

bool Production::getYesNo(char* query)
{
	bool answer = true; //so far
	char said = 'x';
	do
	{
		printf("%s (y/n):",query);
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&said);
	}while((said!= 'y')&&(said!='n'));
	if(said=='n')
	{
		answer=false;
	}


	return answer;
}

