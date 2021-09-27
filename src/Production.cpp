/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"


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
		char filename[FILENAMELENGTHALLOWANCE];
		char* eptr=(char*) malloc(sizeof(char*));

		//we'll want to read the file
		Board* theBoard = new Board();

		puts("Before read file"); fflush(stdout);
		answer = readFile(filename, theBoard); //read the file
		puts("Back from read file"); fflush(stdout);

		//Prob need to make the game run here

	}
	return answer;
}

bool Production::readFile(char* filename, Board* theBoard)
{
	bool ok = true;
	char temp = '-';
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
						fscanf(fp,"%c", &temp);
						if(temp == 'r')
						{
							//TODO Create new red pawn, add it to board?
							Pawn* temp = new Pawn(false,row,col);
							newBoard[pos] = temp;
							pos++;
						}
						else if(temp == 'R')
						{
							//TODO Create new red king, add it to board?
							Pawn* temp = new Pawn(false,row,col);
							temp->makeKing();
							newBoard[pos] = temp;
							pos++;
						}
						else if (temp == 'b')
						{
							//TODO Create new black pawn, add it to board?
							Pawn* temp = new Pawn(true,row,col);
							newBoard[pos] = temp;
							pos++;
						}
						else if (temp == 'B')
						{
							//TODO Create new black king, add it to board?
							Pawn* temp = new Pawn(true,row,col);
							temp->makeKing();
							newBoard[pos] = temp;
							pos++;
						}
					}
					for(int x = pos+1; x<24; x++)
					{
						Pawn* faulty = new Pawn(true,-1,-1);
						faulty->takePawn();
						newBoard[pos] = faulty;
					}
				}

				//discover checkers
				//make instances of class checker as needed
				//board needs to keep track of instances of checkers
				//checkers might also know where they are...
				fscanf(fp,"%c", &temp); //red checker, black, none?
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

