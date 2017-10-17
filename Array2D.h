/*

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           HOMEWORK #2
File:         Array2D.h

*/

// Array2D.h : The setup and definition of the class Array 2D
//				which is a multidimensional array
//

#pragma once 
#ifndef ARRAY2D_H
#define ARRAY2D_H

#include "array.h"
#include "row.h"
#include "exception.h"
#include <iostream>
#include <string>
#include <random>

#pragma region class array 2D
//______________________//
//     ARRAY CLASS      //
//______________________//
template <typename T>
class Array2D

#pragma region member variables
	/**__________________**/
	//  Member Variables  //
	/**___________________*/
{

private:
	Array<T> m_array;
	int m_row;
	int m_col;

public:
	friend class Row<T>;
	Array2D();
	~Array2D();
	Array2D(int row, int col);
	Array2D(const Array2D<T> & copy);
	Array2D & operator=(const Array2D & rhs);
	Row<T> Array2D<T>::operator[](int index);

	int getRow() const;
	void setRow(int rows);
	int getColumn() const;
	void setColumn(int column);
	T & Select(int row, int column);

	void other(int rows, int cols);
};
#pragma endregion

#pragma endregion

#pragma region default constructor
//DEFAULT CONSTRUCTOR
template <typename T>
Array2D<T>::Array2D() : m_col(0), m_row(0)
{
	m_array.setLength(0);
	m_row = 0;
	m_col = 0;
}
#pragma endregion

#pragma region constructor
//CONSTRUCTOR
template <typename T>
Array2D<T>::Array2D(int row, int col)
{
	m_col = col;
	m_row = row;
	m_array.setLength(row*col);

}

#pragma endregion

#pragma region copy constructor
//COPY CONSTRUCTOR
template <typename T>
Array2D<T>::Array2D(const Array2D<T> & copy)
{
	m_array = copy.m_array;
	m_col = copy.m_col;
	m_row = copy.m_row;
}

#pragma endregion

#pragma region destructor
//DESTRUCTOR
template <typename T>
Array2D <T>::~Array2D()
{

}
#pragma endregion

#pragma region operator=
//OPERATOR=
template <typename T>
Array2D<T> & Array2D<T>::operator=(const Array2D<T> & in_rhs)
{
	if (this != &in_rhs)
	{
		m_row = in_rhs.m_row;
		m_col = in_rhs.m_col;
		m_array = in_rhs.m_array;
	}
	return *this;
}
#pragma endregion

#pragma region operator[]
//OPERATOR[]
template <typename T>
Row<T> Array2D<T>::operator[](int index)
{
	if (index < 0 || index > m_row)
	{
		if (index < 0)
		{
			throw Exception("Index can not be less than.");
		}

		else
		{
			throw Exception("Index exceeds column bounds");
		}
	}

	else
		return Row<T>(*this, index);
}


#pragma region getRow
//GET ROW
template <typename T>
int Array2D<T>::getRow() const
{
	return m_row;
}
#pragma endregion

#pragma region setRow
//SET ROW
template <typename T>
void Array2D<T>::setRow(int rows)
{
	if (rows == m_row)
	{

	}
	else if (rows > 0)
	{
		other(rows, m_col);
	}
	else {
		throw Exception("Invalid Row Number!");
	}
}
#pragma endregion

#pragma region getColumn
//GET COLUMN
template <typename T>
int Array2D<T>::getColumn() const
{
	return m_col;
}
#pragma endregion


#pragma region setColumn
//SET COLUMN
template <typename T>
void Array2D<T>::setColumn(int column)
{
	if (column == m_col) {}
	else if (column > 0)
	{
		other(m_row, column);
	}
	else
	{
		throw Exception("Invalid Column Number!");
	}
}

#pragma endregion

#pragma region Select
template <typename T>
T & Array2D<T>::Select(int row, int col)
{
	return m_array[row*m_col + col];
}
#pragma endregion

#pragma region other
//OTHER
template <typename T>
void Array2D<T>::other(int rows, int cols)
{
	int lm_rows = rows;
	int lm_cols = cols;

	if (rows > m_row)
		lm_rows = m_row;
	if (cols > m_col)
		lm_cols = m_col;

	Array2D<T> newArray(rows, cols);
	for (int row = 0; row<lm_rows; row++)
	{
		for (int col = 0; col<lm_cols; col++)
		{
			newArray[row][col] = (*this)[row][col];
		}
	}
	m_array = newArray.m_array;
	m_row = newArray.m_row;
	m_col = newArray.m_col;
}

#pragma endregion


#endif