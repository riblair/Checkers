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
	bool ok3 = testMakeLList();
	bool ok4 = testEnqueue();
	//pedagogical bool ok5 = testRemoveFromList();
	bool ok6 = testPrintHistory();
	bool ok7 = testReturnPos();
	bool ok8 = testmakeMove();
	answer = ok1 && ok3 && ok4  && ok6 && ok7 && ok8;
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
bool Tests::testEnqueue()
{
	bool ok = true;
	if(ok)
	{
		puts("testEnqueue did pass");
	}
	else
	{
		puts("testEnqueue did not pass.");
	}
	return ok;
}
bool Tests::testGotAdjacencyMatrix()
{
	bool ok = true;
	if(ok)
	{
		puts("testGotAdjacencyMatrix did pass");
	}
	else
	{
		puts("testGotAdjacencyMatrix did not pass.");
	}
	return ok;
}

bool Tests::testMakeLList()
{
	bool ok = true;
	if(ok)
	{
		puts("testMakeLList did pass");
	}
	else
	{
		puts("testMakeLList did not pass.");
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
	King* king1 = new King();
	king1->makeMove(testPos1);
	if(king1->returnPosition()->row != testPos1->row)
		{
			ok = false;
		}
		if(king1->returnPosition()->col != testPos1->col)
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


