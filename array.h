#pragma once
/*

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           HOMEWORK #2
File:         array.h

*/

// array.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#ifndef ARRAY_H
#define ARRAY_H

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include <iostream>
#include "exception.h"

using namespace std;

#pragma region array class
// ____________________ //
//     ARRAY CLASS      //
//______________________//
template<typename T>
class Array
{

#pragma region member variables
	/**__________________**/
	//  Member Variables  //
	/**___________________*/
private:

	T*  m_array;
	int m_length;
	int m_start_index;


public:

	//DEFAULT CONSTRUCTOR
	Array();

	//CONSTRUCTOR
	Array(int length, int start_index);

	//COPY CONSTRUCTOR
	Array(const Array & copy);

	//DESTRUCTOR
	~Array();

	//GET-SET!!
	void setLength(int length);
	void setStartIndex(int start_index);
	int getLength();
	int getStartIndex();

	//OPERATOR =
	Array<T> & operator=(const Array & rhs);

	//OPERATOR []
	T & operator[](int index);
#pragma endregion

};

#pragma region default constructor
//DEFAULT CONSTRUCTOR
template<typename T>
Array<T>::Array()
{
	m_array = nullptr;
	m_length = 0;
	m_start_index = 0;
}
#pragma endregion

#pragma region constructor
//CONSTRUCTOR
template<typename T>
Array<T>::Array(int length, int start_index)
{
	m_length = length;
	m_start_index = start_index;

	if (length < 0)
		throw Exception("NegativeLengthException");
	if (length>0)
		m_array = new T[length];
	else
	{
		m_array = nullptr;
	}
}
#pragma endregion

#pragma region copy constructor
//COPY CONSTRUCTOR
template<typename T>
Array<T>::Array(const Array & copy)
{
	m_length = copy.m_length;
	m_start_index = copy.m_start_index;

	if (m_length>0)
	{
		m_array = new T[m_length];
		for (int i = 0; i < m_length; i++)
		{
			m_array[i] = copy.m_array[i];
		}
	}
	else
		m_array = nullptr;
}
#pragma endregion

#pragma region destructor
//DESTRUCTOR
template<typename T>
Array<T>::~Array()
{
	delete[] m_array;
	m_array = nullptr;
}
#pragma endregion

#pragma region get-set!!
/**_________**/
//  GET-SET  //
/**__________*/

//SET LENGTH
template<typename T>
void Array<T>::setLength(int length)
{
	T* newArray = new T[length]();
	if (length > m_length)
		for (int i = 0; i < m_length; ++i)
			newArray[i] = m_array[i];
	else
		for (int i = 0; i < length; ++i)
			newArray[i] = m_array[i];

	delete[] m_array;
	m_array = newArray;


	m_length = length;
}

//GET SET START INDEX
template<typename T>
void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template <typename T>
int Array<T>::getStartIndex()
{
	return m_start_index;
}


#pragma endregion

#pragma region operator=
//OPERATOR=
template <typename T>
Array<T> & Array<T>::operator=(const Array<T> & rhs)
{
	if (this != &rhs)
	{
		delete[] m_array;
		m_array = nullptr;
		this->m_length = rhs.m_length;
		this->m_start_index = rhs.m_start_index;

		m_array = new T[m_length];
		for (int i = 0; i < m_length; i++)
		{
			m_array[i] = rhs.m_array[i];
		}
	}
	return *this;
}
#pragma endregion

#pragma region operator[]
//OPERATOR[]
template <typename T>
T & Array<T>::operator[](int index)
{
	if (index >= m_start_index + m_length || index < m_start_index)
	{
		throw(Exception("WARNING: Your index is lower than zero!"));
	}
	return m_array[index - m_start_index];
}
#pragma endregion

#endif
