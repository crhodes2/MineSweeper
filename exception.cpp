/*

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           HOMEWORK #2
File:         exception.cpp

*/

/* exception.cpp : 
	definition of class header exception, 
	including exception handling of array
	and lower and upper bounds specification. 
*/

#include "exception.h"
#include <cstring>

using namespace std;

#pragma region null terminator
  //________________________//
 //		NULL TERMINATOR	   //
//________________________//
/* 
	Adds an extra character in a null terminator. 
*/
const int NULL_TERMINATOR = 1;
#pragma endregion

#pragma region exception constructor
  //_____________________________//
 //     EXCEPTION CONSTRUCTOR   //
//_____________________________//
/*
	Empty constructor for the exception class definition.
	Nothing to be added there, but needed for compiling to work
*/
Exception::Exception()
{
	cout << "ERROR! OUT OF BOUNDS!" << endl;
}
#pragma endregion

#pragma region exception message
  //_____________________________//
 //     EXCEPTION CONSTRUCTOR   //
//_____________________________//
/*
	Used to create/set a specific message 
	for the exception error to be displayed.
*/
Exception::Exception(char *msg)
{
	m_msg = new char[strlen(msg) + 1];
	m_msg = msg;
}
#pragma endregion

#pragma region exception copy constructor
  //__________________________________//
 //     EXCEPTION COPY CONSTRUCTOR   //
//__________________________________//
/*
	A copy constructor for the Exception class.
*/
Exception::Exception(const Exception & copy)
{
	m_msg = new char[strlen(copy.m_msg) + 1];
	m_msg = copy.m_msg;

}
#pragma endregion

#pragma region exception destructor
  //____________________________//
 //     EXCEPTION DESTRUCTOR   //
//____________________________//

/*
	Destructor for the exception class definition.
	Used to delete any data stored in the exception
	object and free up memory
*/
Exception::~Exception()
{
	delete[] m_msg;
}
#pragma endregion

#pragma region exception operator=
  //___________________________//
 //     EXCEPTION OPERATOR=   //
//___________________________//
/*
	Assign Exception's message data to this object.
	rhs is the Exception containing the data needed to copy.
	and it'll copy the message from rhs to this.
*/
Exception & Exception::operator=(const Exception & rhs)
{
	//m_msg = new char[strlen(rhs.m_msg) + 1];
	//m_msg = rhs.m_msg;

	if (this != &rhs)
	{
		delete[] m_msg;
		m_msg = new char[strlen(rhs.m_msg) + 1];
		m_msg = rhs.m_msg;
	}
	return *this;
}
#pragma endregion 

#pragma region exception operator <<
  //____________________________//
 //     EXCEPTION OPERATOR<<   //
//____________________________//

/*
Purpose:
This overloaded stream insertion operator outputs the Exception's error message, provided it
exists.
*/

std::ostream & operator<< (std::ostream & stream, const Exception & except)
{
	stream << except.m_msg;
	return stream;
}
#pragma endregion

#pragma region set message
  //___________________//
 //     SET MESSAGE   //
//___________________//
/*
	Set the message
*/
void Exception::setMessage(char * msg)
{
	delete[] m_msg;
	m_msg = new char[strlen(msg) + 1];
	m_msg = msg;
}
#pragma endregion 

#pragma region get message
  //___________________//
 //     GET MESSAGE   //
//___________________//
/*
	Get the error message by returning a constant pointer 
	to the Exception message.
*/
const char * Exception::getMessage()
{
	return m_msg;
}
#pragma endregion

