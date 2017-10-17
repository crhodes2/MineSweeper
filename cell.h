/*

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           LAB #1
File:         cell.h

*/

//
// cell.h :  Header file for class cell.
//
#pragma once

#ifndef cell_h
#define cell_h

#include <stdio.h>
#include "Array2D.h"

using namespace std;

#pragma region cell class
  // __________________//
 //     CELL CLASS    //
//___________________//
class cell
{
	     /**__________________**/
        //  Member Variables  //
       /**___________________*/

private:
	bool hasBombs;
	char proximity;
	bool marked;
	int m_row;
	int m_col;
	Array2D<cell> * cells;

public:
	//DEFAULT CONSTRUCTOR
	cell();

	//CONSTRUCTOR
	cell(Array2D<cell> * grid, int row, int col);
	
	//DESTRUCTOR
	~cell();

	//OPERATOR =
	cell & operator = (cell & rhs);

	//OPERATOR ++
	char operator ++ (int);

	//PROXIMITY OF CELL (GET-SET)
	char getProximity();
	void setProximity(char prox);

	//GET THE STATUS OF THE CELL
	bool getCellStatus();

	//DOES THE CELL HAVE BOMBS?
	void bomb();
	
	//IS THE CELL A MARKED CELL?
	void mark();

	//STATUS OF A MARKED CELL
	bool markStatus();

	//HAS THE CELL BEEN REVEALED?
	bool exposed();

};
#pragma endregion

#pragma region cell default constructor
  //____________________________//
 //  CELL DEFAULT CONSTRUCTOR  //
//____________________________//
/*
	Empty constructor for the cell class definition.
	have each cell be initiated with no bombs,
	no marks, and a default P for proximity.
	Proximity is how close each cell are to each other.

*/
cell::cell()
{
	cells = nullptr;
	marked = false;
	proximity = 'P';

}
#pragma endregion

#pragma region cell constructor
  //____________________//
 //  CELL CONSTRUCTOR  //
//____________________//
/*
	Constructor for the cell class definition.
	Uses 2D array as instantiation of the game's cell.
*/
cell::cell(Array2D<cell> * grid, int row, int col)
{
	hasBombs = false; 
	proximity = '0';
	cells = grid;
	m_row = row;
	m_col= col;
	marked = false;

}
#pragma endregion

#pragma region cell destructor
  //_______________________//
 //     CELL DESTRUCTOR   //
//_______________________//
/*
	Destructor for the cell class definition.
*/
cell::~cell() {}
#pragma endregion

#pragma region operator=
  //_________________//
 //     OPERATOR=   //
//_________________//
/*
	Operator=
*/
cell & cell::operator=(cell & rhs)
{
	if (&rhs != this)
	{
		proximity = rhs.proximity;
		hasBombs = rhs.hasBombs;
		m_row = rhs.m_row;
		m_col = rhs.m_col;
		cells = rhs.cells;
	}
	return *this;
}
#pragma endregion

#pragma region operator++
  //__________________//
 //     OPERATOR++   //
//__________________//
/*
	Operator++ incrementing cells row by row.
*/
char cell::operator++(int)
{
	char pro = proximity;
	if (proximity != 'P' && proximity != 'X')
	{
		proximity++;
	}
	return pro;
}
#pragma endregion

#pragma region bomb
  //____________//
 //     BOMB   //
//____________//
/*
	Bomb function.
*/
void cell::bomb()
{
	proximity = 'X';
	// up
	(*cells)[m_row - 1][m_col]++;
	// down
	(*cells)[m_row + 1][m_col]++;
	// left
	(*cells)[m_row][m_col - 1]++;
	// right
	(*cells)[m_row][m_col + 1]++;
	//n.east and n.west
	(*cells)[m_row - 1][m_col + 1]++;
	(*cells)[m_row - 1][m_col - 1]++;
	// s.east and s.west
	(*cells)[m_row + 1][m_col + 1]++;
	(*cells)[m_row + 1][m_col - 1]++;
}

#pragma endregion

#pragma region set proximity
  //_____________________//
 //     SET PROXIMITY   //
//_____________________//
/*
	set proximity of the cells.
*/
void cell::setProximity(char prox)
{

	proximity = prox;
}
#pragma endregion

#pragma region get proximity
  //_____________________//
 //     GET PROXIMITY   //
//_____________________//
/*
	return the proximity of the cells.
*/
char cell::getProximity()
{
	return proximity;
}
#pragma endregion

#pragma region exposed
  //_______________//
 //     EXPOSED   //
//_______________//
/*
	Exposed function. Shows a cell that has already been uncovered
	by the player.
*/
bool cell::exposed()
{
	bool foo = false;
	if (hasBombs == false && marked == false)
	{
		hasBombs = true;
		if (proximity == '0')
		{
			// up
			(*cells)[m_row - 1][m_col].exposed();

			// down
			(*cells)[m_row + 1][m_col].exposed();

			// left
			(*cells)[m_row][m_col - 1].exposed();

			// right
			(*cells)[m_row][m_col + 1].exposed();

			//n.east and n.west
			(*cells)[m_row - 1][m_col + 1].exposed();
			(*cells)[m_row - 1][m_col - 1].exposed();

			// s.east and s.west
			(*cells)[m_row + 1][m_col + 1].exposed();
			(*cells)[m_row + 1][m_col - 1].exposed();

		}
		else if (proximity == 'X')
		{
			foo = true;
		}

	}
	return foo;
}
#pragma endregion

#pragma region get cell status
  //______________________//
 //     GET CELL STATUS  //
//______________________//
/*
	Shows that each specific cell has a bomb buried.
*/
bool cell::getCellStatus()
{
	return hasBombs;
}

#pragma endregion

#pragma region mark
  //____________//
 //     MARK   //
//____________//
/*
	Mark function. Shows a cell that has been marked.
*/
void cell::mark()
{
	if (!hasBombs)
	{
		marked == true ? marked = false : marked = true;
	}
}
#pragma endregion

#pragma region mark status
  //___________________//
 //     MARK STATUS   //
//___________________//
/*
	Mark status function.
*/
bool cell::markStatus()
{
	return marked;
}
#pragma endregion

#endif