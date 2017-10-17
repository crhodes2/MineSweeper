/*

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           HOMEWORK #2
File:         row.h

*/

// row.h : include file for the set up of rows and columns
// in a 2D or multi-D array
//

#pragma once
#ifndef ROW_H
#define ROW_H

#include "exception.h"
#include "array.h"
#include "Array2D.h"

template <typename T>
class Array2D;

#pragma region row class
  //____________________//
 //       ROW CLASS    //
//____________________//
template <typename T>
class Row
{
	#pragma region member variables
         /**__________________**/
        //  Member Variables  //
       /**___________________*/
private:
	Array2D<T> & m_array2D;
	int m_row; 

public:
	Row(Array2D<T> & array, int row);
	T & operator[] (int column);
	const T & operator [] (int column) const;

#pragma endregion

};
#pragma endregion

#pragma region Row constructor
//ROW CONSTRUCTOR
template<typename T>
Row<T>::Row(Array2D<T> & array, int row) : m_array2D(const_cast<Array2D<T> &>(array)), m_row(row)
{
}
#pragma endregion 

#pragma region operator[]
//OPERATOR[]
template <typename T>
T & Row<T>::operator[](int column)
{
	int index = (m_array2D.m_col) * m_row + column;
	return m_array2D.m_array[index];
}
#pragma endregion

#pragma region operator[]
//OPERATOR[]
template <typename T>
const T & Row<T>::operator[](int column) const
{
	int index = (m_array2D.m_col) * m_row + column;
	return m_array2D.m_array[index];
}
#pragma endregion

#endif