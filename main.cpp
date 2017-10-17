/*

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB #1
File:         main.cpp

*/

#pragma once
#define _CRTDBG_MAP_ALLOC

#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include <thread>
using std::string;
using std::cout;
using std::endl;
#include "minesweeper.h"


using namespace std;

#pragma region minesweeper constructor
  //__________________//
 //     MAIN FILE    //
//__________________//
/*
	The main program
*/

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	bool gameover2 = false;

	while (!gameover2)
	{
		// while the game is not over...
		system("cls");
		string user;
		cout << "____ WELCOME TO MINESWEEPER ____" << endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(3000));
		cout << "Please Select Difficulty: " << endl;
		cout << "1 - Soothing | 2 - Normal | 3 - Lunatic | e - Exit Game " << endl;
		std::getline(std::cin, user);
		char select1 = tolower(user.c_str()[0]);
		if (select1 == 'e')
		{
			gameover2 = true;
		}
		else
		{
			minesweeper newGame(select1);
			newGame.UI();
		}
	}
	system("pause");
}
#pragma endregion


							//			E	N	D			O	F			F	I	L	E			//
