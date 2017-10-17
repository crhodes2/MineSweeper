/*

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB #1
File:         board.h

*/

// board.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma once

#ifndef board_h
#define board_h

#define _DEBUGMODE

#include <cstdlib>
#include <windows.h>
#include <iostream>
#include <ctime>
#include <iomanip>
#include "Array2D.h"
#include "cell.h"

using namespace std;

#pragma region board class
  // ___________________//
 //     BOARD CLASS    //
//____________________//
class board
{
private:
	int selRow;
	int selCol;
	Array2D<cell> * game;
	void setTheBombs(int bombs);
	bool continues = true;
	bool checkAllBombs();
	bool winner = false;

public:
	board();								 // <-- default constructor
	~board();								//  <-- destructor
	board & operator = (const board & rhs);
	void selectDifficulty(char difficulty);
	void display();
	bool exposed();
	bool gameState();
	int getRow();
	int getCol();
	bool selectRow(int);
	bool selectCol(int);
	int GetSelectRow();
	int GetSelectCol();
	void clearSelected();

	void row2();
	void row3();
	void col2();
	void col3();

	void mark();
	bool winLoseStatus();

};
#pragma endregion

#pragma region board constructor
  //________________________//
 //     BOARD CONSTRUCTOR  //
//________________________//
/*
	Empty constructor for the board class definition.
	Nothing to be added there, but needed for compiling to work
*/
board::board()
{
	game = nullptr;
}
#pragma endregion

#pragma region board destructor
  //_______________________//
 //     BOARD DESTRUCTOR  //
//_______________________//
/*
	-Destroys the board class after program ends
*/
board::~board()
{
	delete game;
}
#pragma endregion

#pragma region operator=
  //________________//
 //     OPERATOR=  //
//________________//
/*
	-About
*/
board & board::operator=(const board & rhs)
{
	return *this;
}
#pragma endregion

#pragma region display
  //______________//
 //    DISPLAY   //
//______________//
/*
	-The GUI (Graphical User Interface) of the
	Minesweeper game. 
*/
void board::display()
{
	system("cls");
	HANDLE highlight = 0;
	highlight = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << "  ";
	for (int i = 1; i< game->getColumn(); i++)	
	{
		if (i % 2 == 0)
		{
			cout << setw(2) << i;
		}
		else
		{
			cout << setw(2) << " ";
		}
	}
	cout << endl;	
	for (int row = 1; row<game->getRow() - 1; row++)		//for every row
	{

		if (row % 2 == 0)							//same every 2 row number output
			cout << setw(2) << row;
		else
			cout << setw(2) << " ";
		for (int col = 1; col<game->getColumn() - 1; col++)
		{
#ifdef DEBUGMODE
			cout << setw(2) << (*game)[row][col].getProximity();			//debugmode, show all tiles uncovered
#else
			if (col == selCol && row == selRow)
			{
				SetConsoleTextAttribute(highlight, FOREGROUND_GREEN | FOREGROUND_INTENSITY);		//GREEN CURSOR
			}

			// WHEN A CELL IS EXPOSED...
			if ((*game)[row][col].getCellStatus())
			{
				// ... output proximity, pinpointing the location of a bomb.
				char output = (*game)[row][col].getProximity();
				if (col == selCol && row == selRow)
				{
					cout << setw(2) << "?";
				}
				else if (output != '0')
				{
					switch (output)
					{
					case '1':	//YELLOW
						SetConsoleTextAttribute(highlight, 0xE5);
						break;

					case '2':	//GREEN
						SetConsoleTextAttribute(highlight, 0xA1);
						break;

					case '3':	//BLUE
						SetConsoleTextAttribute(highlight, 0xB2);
						break;

					case '4':	//PINK
						SetConsoleTextAttribute(highlight, 0xD4);
						break;

					case '5':
						SetConsoleTextAttribute(highlight, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
						break;

					case '6':
						SetConsoleTextAttribute(highlight, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						break;

					case '7':
						SetConsoleTextAttribute(highlight, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
						break;

					case '8':
						SetConsoleTextAttribute(highlight, 0xF6);
						break;

					case 'X': //SET COLOR BLOOD RED
						SetConsoleTextAttribute(highlight, 0xC3);
						break;
					}
					cout << setw(2) << output;
					SetConsoleTextAttribute(highlight, 7);	// RETURN COLOR TO NORMAL
				}

				else
				{
					cout << setw(2) << " ";
				}
			}
			else
			{
				if ((*game)[row][col].markStatus())
					cout << setw(2) << "*";
				else
					cout << setw(2) << char(254);
			}
			SetConsoleTextAttribute(highlight, 7);


#endif
		}
		cout << endl;
		SetConsoleTextAttribute(highlight, 7);
	}

	cout << setw(2) << endl << "   ";


}
#pragma endregion
     
#pragma region select difficulty
  //________________________//
 //     SELECT DIFFICULTY  //
//________________________//
/*
	-Set the game's difficulty. Have the user make their choice
	first thing to do before playing
*/
void board::selectDifficulty(char difficulty)
{
	int row;
	int col; 
	int bombs;

	switch (difficulty)		//pick game difficulty
	{
	case '1':	//EASY MODE
		row = 10;
		col = 10;
		bombs = 10;
		break;

	case '2':	//INTERMEDIATE MODE
		row = 16;
		col = 16;
		bombs = 40;
		break;

	case '3':	//HARD MODE
		row = 16;
		col = 30;
		bombs = 100;
		break;

	default: //INTERMEDIATE MODE AS DEFAULT
		row = 16;
		col = 16;
		bombs = 40;
	}

	game = new Array2D<cell>(row + 2, col + 2);		//make new board 2 wider than displayed size
	for (int row = 0; row<game->getRow(); row++)
	{
		for (int col = 0; col<game->getColumn(); col++)
		{
			cell init(game, row, col);
			(*game)[row][col] = init;

			if (row == 0 || row == game->getColumn() - 1 || col == 0 || col == game->getColumn() - 1)
			{
				(*game)[row][col].setProximity('P');
			}
		}

	}
	setTheBombs(bombs);
}
#pragma endregion

#pragma region set the bombs
  //____________________//
 //    SET THE BOMBS   //
//____________________//
/*
	-Code to randomly set the bombs around the game field.
*/
void board::setTheBombs(int bombs)
{
	int row = 0;
	int col = 0;

	for (int i = 0; i<bombs; i++)
	{
		srand(time(0) + i*(col + 1)*(row + 1));
		col = rand() % (game->getColumn() - 2) + 1;
		srand(time(0) + i*(row + 1));
		row = rand() % (game->getRow() - 2) + 1;
		if ((*game)[row][col].getProximity() != 'X')
			(*game)[row][col].bomb();
		else
			i--;
	}

}
#pragma endregion

bool board::gameState()
{
	return continues;
}

bool board::exposed()
{

	bool endgame = false;
	if ((*game)[selRow][selCol].exposed())
	{
		continues = false;
		endgame = true;
	}
	if (checkAllBombs())
	{
		winner = true;
		endgame = true;
	}

	return endgame;
}

int board::getRow()
{
	return game->getRow() - 2;
}

int board::getCol()
{
	return game->getColumn();
}

bool board::selectRow(int row)
{
	bool rval = true;
	if (row > 0 && row < game->getRow() - 1)
		selRow = row;
	else
		rval = false;
	return rval;
}

bool board::selectCol(int col)
{
	bool rval = true;
	if (col > 0 && col < game->getColumn() - 1)
		selCol = col;
	else
		rval = false;
	return rval;
}

int board::GetSelectRow()
{
	return selRow;
}

int board::GetSelectCol()
{
	return selCol;
}

void board::clearSelected()
{
	selCol = 0;
	selRow = 0;
}

void board::row2()
{
	if (selRow > 1)
	{
		selRow--;
	}
}


void board::row3()
{
	if (selRow < game->getRow() - 2)
	{
		selRow++;
	}
}

void board::col2()
{
	if (selCol > 1)
	{
		selCol--;
	}
}


void board::col3()
{
	if (selCol < game->getColumn() - 2)
	{
		selCol++;
	}
}


void board::mark()
{

	(*game)[selRow][selCol].mark();
}


bool board::checkAllBombs()
{
	bool AllClear = true;
	for (int row = 1; row<game->getRow() - 1 && AllClear; row++)
	{

		for (int col = 1; col<game->getColumn() - 1 && AllClear; col++)
		{

			if (!(*game)[row][col].getCellStatus())
			{
				if ((*game)[row][col].getProximity() != 'X')
					AllClear = false;
			}

		}

	}
	return AllClear;
}


bool board::winLoseStatus()
{
	return winner;
}


#endif