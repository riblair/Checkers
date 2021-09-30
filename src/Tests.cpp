/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include <stdbool.h>
#include "Pawn.h"


Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool answer = true;

	bool ok1 = testReadFile();
	bool ok2 = testFileOutput();
	bool ok3 = testPrintHistory();
	bool ok4 = testReturnPos();
	bool ok5 = testmakeMove();
	bool ok6 = testdisplayBoard();
	bool ok7 = testprintToFile();
	bool ok8 = testCheckIsWin();
	bool ok9 = testisLegal();
	answer = ok1 && ok2 && ok3  && ok4 && ok5 && ok6 && ok7 && ok8 && ok9;
	return answer;
}

bool Tests::testReadFile()
{
	puts("starting testReadFile"); fflush(stdout);
	bool ok = true;
	//the file tells how many rooms there are
	int answer = -1;
	int rightAnswer = 8;


	Board* theBoard = new Board();

	Production* pP = new Production();

	ok = pP->readFile("gameState.txt", theBoard); //read the file
	theBoard->displayBoard();
	ok = pP->getYesNo("Does the board look right?");
	if(ok)
	{
		puts("testReadfile did pass");
	}
	else
	{
		puts("testReadfile did not pass.");
	}

	return ok;
}

bool Tests::testPrintHistory()
{
	bool ok = true;
	if(ok)
	{
		puts("testPrintHistory did pass");
	}
	else
	{
		puts("testPrintHistory did not pass.");
	}
	return ok;
}
bool Tests::testFileOutput()
{
	bool ok = true;

	FILE* fd = fopen("boardPlay.txt", "w");
	fprintf(fd, "Here goes nothing\n"); fflush(fd);


	fclose(fd);
	if(ok)
	{
		puts("testFileOutput did pass");
	}
	else
	{
		puts("testFileOutput did not pass.");
	}
	return ok;
}


bool Tests::testReturnPos()
{
	bool ok = true;
	Pawn* pawn1 = new Pawn(); //Intilizes row and col as 0,0
	Position* testPosition = new Position();
	testPosition->col = 0;
	testPosition->row = 0;
	if(pawn1->returnPosition()->col != testPosition->col)
	{
		ok = false;
	}
	if(pawn1->returnPosition()->row != testPosition->row)
	{
		ok = false;
	}


	if(ok)
	{
		puts("testReturnPos did pass");
	}
	else
	{
		puts("testReturnPos did not pass.");
	}
	return ok;
}


bool Tests::testmakeMove()
{
	bool ok = true;
	Pawn* pawn1 = new Pawn();
	Position* testPos1;
	testPos1->col = 2;
	testPos1->row = 2;
	pawn1->makeMove(testPos1);
	if(pawn1->returnPosition()->row != testPos1->row)
	{
		ok = false;
	}
	if(pawn1->returnPosition()->col != testPos1->col)
	{
		ok = false;
	}
	if(ok)
	{
		puts("testMakeMove did pass");
	}
	else
	{
		puts("testMakeMove did not pass.");
	}
	return ok;
}

bool Tests::testdisplayBoard() {
	bool ok = false;
	Production* pP = new Production();
	Board* board = new Board();
	Pawn* Pieces[24];
	Pieces[0] = new Pawn(false, 0, 1);
	Pieces[1] = new Pawn(false, 0, 3);
	Pieces[2] = new Pawn(false, 0, 5);
	Pieces[3] = new Pawn(false, 0, 7);
	Pieces[4] = new Pawn(true, 7, 0);
	Pieces[5] = new Pawn(true, 7, 2);
	Pieces[6] = new Pawn(true, 7, 4);
	Pieces[7] = new Pawn(true, 7, 6);
	Pieces[8] = new Pawn(true, -1, -1);
	Pieces[9] = new Pawn(true, -1, -1);
	Pieces[10] = new Pawn(true, -1, -1);
	Pieces[11] = new Pawn(true, -1, -1);
	Pieces[12] = new Pawn(true, -1, -1);
	Pieces[13] = new Pawn(true, -1, -1);
	Pieces[14] = new Pawn(true, -1, -1);
	Pieces[15] = new Pawn(true, -1, -1);
	Pieces[16] = new Pawn(true, -1, -1);
	Pieces[17] = new Pawn(true, -1, -1);
	Pieces[18] = new Pawn(true, -1, -1);
	Pieces[19] = new Pawn(true, -1, -1);
	Pieces[20] = new Pawn(true, -1, -1);
	Pieces[21] = new Pawn(true, -1, -1);
	Pieces[22] = new Pawn(true, -1, -1);
	Pieces[23] = new Pawn(true, -1, -1);
	board->initBoard(Pieces);
	puts(" the board should only have the first and last rows of checkers filled.");
	board->displayBoard();
	ok = pP->getYesNo("Does the board look right?");
	if(ok)
	{
		puts("testdisplayBoard passed");
	}
	else
	{
		puts("testdisplayBoard did not pass.");
	}

	return ok;
}

bool Tests::testprintToFile() {
	// reset's file to an 'incorrect' state'
	FILE* fp = fopen("testPrint.txt", "w");
	fprintf(fp, "THIS IS INCORRECT");
	fclose(fp);

	bool ok = false;

	Production* pP = new Production();
	Board* board = new Board();
	Pawn* Pieces[24];
	Pieces[0] = new Pawn(true, 0, 1);
	Pieces[1] = new Pawn(false, 0, 3);
	Pieces[2] = new Pawn(true, 0, 5);
	Pieces[3] = new Pawn(false, 0, 7);
	Pieces[4] = new Pawn(true, 1, 0);
	Pieces[5] = new Pawn(false, 1, 2);
	Pieces[6] = new Pawn(true, 1, 4);
	Pieces[7] = new Pawn(false, 1, 6);
	Pieces[8] = new Pawn(true, 2, 1);
	Pieces[9] = new Pawn(false, 2, 3);
	Pieces[10] = new Pawn(true, 2, 5);
	Pieces[11] = new Pawn(false, 2, 7);
	Pieces[12] = new Pawn(true, 5, 0);
	Pieces[13] = new Pawn(false, 5, 2);
	Pieces[14] = new Pawn(true, 5, 4);
	Pieces[15] = new Pawn(false, 5, 6);
	Pieces[16] = new Pawn(true, 6, 1);
	Pieces[17] = new Pawn(false, 6, 3);
	Pieces[18] = new Pawn(true, 6, 5);
	Pieces[19] = new Pawn(false, 6, 7);
	Pieces[20] = new Pawn(true, 7, 0);
	Pieces[21] = new Pawn(false, 7, 2);
	Pieces[22] = new Pawn(true, 7, 4);
	Pieces[23] = new Pawn(false, 7, 6);
	board->initBoard(Pieces);
	board->printToFile("testPrint.txt");

	ok = pP->getYesNo("Does the file testPrint look right?");
	if(ok)
	{
		puts("testprintToFile passed");
	}
	else
	{
		puts("testprintToFile did not pass.");
	}

	return ok;
}

bool Tests::testCheckIsWin()
{
	bool ok = true;

	Board* theBoard = new Board();
	Production* pP = new Production();
	pP->readFile("testCheckIsWin.txt", theBoard); //read the file
	ok = theBoard->checkIsWin();

	if(ok)
	{
		puts("testCheckIsWin did pass");
	}
	else
	{
		puts("testCheckIsWin did not pass.");
	}

	return ok;
}

bool Tests::testisLegal()
{
	bool ok = true;
	Board* testLegal = new Board();
	CheckerMove* check = new CheckerMove();
	testLegal->initBoard();
	Position* pawn1 = new Position();
	pawn1->row = 2;
	pawn1->col = 1;
	Position* move1 = new Position();
	move1->row = 3;
	move1->col = 2;
	if(!check->isLegal(testLegal, pawn1, move1))
	{
		ok = false;
	}
	move1->col = 0;
	if(!check->isLegal(testLegal, pawn1, move1))
	{
		ok = false;
	}
	if(check->isLegal(testLegal, pawn1, pawn1))
	{
		ok = false;
	}
	Position* pawn2 = new Position();
	Position* move2 = new Position();
	pawn2->row = 5;
	pawn2->col = 6;
	move2->row = 4;
	move2->col = 7;
	if(!check->isLegal(testLegal, pawn2, move2))
	{
		ok = false;
	}
	move2->col = 5;
	if(!check->isLegal(testLegal, pawn2, move2))
	{
		ok = false;
	}
	if(check->isLegal(testLegal, pawn2, pawn2))
	{
		ok = false;
	}
	Production* pP = new Production();
	pP->readFile("gameState.txt",testLegal);
	pawn2->row = 3;
	pawn2->col = 2;
	move2->row = 1;
	move2->col = 0;
	if(!check->isLegal(testLegal, pawn2, move2))
	{
		ok = false;
	}
	move2->row = 1;
	move2->col = 4;
	if(!check->isLegal(testLegal, pawn2, move2))
	{
		ok = false;
	}
	move2->row = 5;
	move2->col = 0;
	if(!check->isLegal(testLegal, pawn2, move2))
	{
		ok = false;
	}
	move2->row = 5;
	move2->col = 4;
	if(!check->isLegal(testLegal, pawn2, move2))
	{
		ok = false;
	}
	if(ok)
	{
		puts("testisLegal did pass");
	}
	else
	{
		puts("testisLegal did not pass.");
	}
	return ok;
}
