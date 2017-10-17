/*

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB #1
File:         minesweeper.h

*/

// minesweeper.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#pragma once

#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_SPACE 0x020
#define KEY_M 109

#include "board.h"
#include <string>
#include <conio.h>

using namespace std;

#pragma region minesweeper class
  // _________________________ //
 //     MINESWEEPER CLASS     //
//___________________________//
class minesweeper
{
public:
	minesweeper(char lvl);
	~minesweeper();
	void UI();
	minesweeper & operator = (minesweeper & rhs);

private:
	char difficulty;
	board myBoard;
	std::string ui;
	bool gameover;
};
#pragma endregion

#pragma region minesweeper constructor

  //_____________________________//
 //     MINESWEEPER CONSTRUCTOR //
//_____________________________//
/*
	Empty constructor for the minesweeper game class definition.
	This constructor generates the minesweeper game based on
	the difficulty chosen by the user.
*/
minesweeper::minesweeper(char lvl)
{
	difficulty = lvl;
	gameover = false;

}
#pragma endregion

#pragma region minesweeper destructor
  //______________________________//
 //     MINESWEEPER DESTRUCTOR   //
//______________________________//
/*
	Destructor for the minesweeper class definition.
*/
minesweeper::~minesweeper()
{

}
#pragma endregion

#pragma region minesweeper operator=
  //___________________//
 //     OPERATOR =    //
//___________________//
/*
	-About.
*/

minesweeper & minesweeper::operator=(minesweeper & rhs)
{
	if (this != &rhs)
	{
		difficulty = rhs.difficulty;
		ui = rhs.ui;
		myBoard = rhs.myBoard;
		
	}
	return *this;
}
#pragma endregion

#pragma region minesweeper ui
  //______________________//
 //     MINESWEEPER UI   //
//______________________//
/*
	-The game interface
*/
void minesweeper::UI()
{
	myBoard.selectDifficulty(difficulty);

	string row; 
	string col;
	string user;
	int a = 0;

	// default place to put the cursor when starting game
	int rowNumber = 5;
	int colNumber = 5;
	myBoard.selectRow(rowNumber);
	myBoard.selectCol(colNumber);
	
	while (!gameover)
	{
		myBoard.display();
		cout << "[" << myBoard.GetSelectRow() << "][" << myBoard.GetSelectCol() << "]" << endl;
		cout << "_________________HOW TO PLAY_________________" << endl;
		cout << "Don't step on the bombs. Step on every square possible without activating the bomb hiding in a square." << endl;
		cout << "[arrow key] Move" << endl;
		cout << "[space] Reveal a Square" << endl;
		cout << "[M] Mark a Square" << endl;
		cout << "" << endl;

		switch ((a = _getch())) //get keryboard input one key at a time
		{		
		case KEY_UP:
			myBoard.row2();
			break;
		case KEY_DOWN:
			myBoard.row3();
			break;
		case KEY_LEFT:
			myBoard.col2();
			break;
		case KEY_RIGHT:
			myBoard.col3();
			break;
		case KEY_SPACE:
			if (myBoard.exposed())
				gameover = true;
			break;
		case KEY_M:
			myBoard.mark();
			break;
		default:
			break;
		}
		
	}
	myBoard.clearSelected();
	myBoard.display();

	HANDLE highlight = GetStdHandle(STD_OUTPUT_HANDLE);
	if (myBoard.winLoseStatus())
	{
		system("cls");
		cout << "You've cleared the game!" << endl;
		SetConsoleTextAttribute(highlight, 0x6F);
		cout << "!!!  C O N G R A T U L A T I O N S  !!!" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}
	else
	{
		SetConsoleTextAttribute(highlight, FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout << "G A M E   O V E R" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
	}

	system("pause");

	SetConsoleTextAttribute(highlight, 7);
}
#pragma endregion

#endif