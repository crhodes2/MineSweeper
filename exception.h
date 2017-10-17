/*

Name:         CHRISTIAN RHODES
Class:        CST 211 - DATA STRUCTURES
HW:           HOMEWORK #2
File:         exception.h

*/

// exception.h : file for exception header,
// Includes code for specifying index smaller than lower bounds
// and index larger than upper bounds
//

#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
using namespace std;

#pragma region exception
//_________________________//
//     EXCEPTION CLASS     //
//_________________________//
class Exception
{
#pragma region member variables
	/**__________________**/
	//  Member Variables  //
	/**___________________*/
private:
	char* m_msg;

public:
	//DEFAULT CONSTRUCTOR
	Exception();

	//CONSTRUCTOR
	Exception(char * msg);

	//COPY CONSTRUCTOR
	Exception(const Exception & copy);

	//DESTRUCTOR
	~Exception();

	//OPERATOR=
	Exception & operator=(const Exception & rhs);

	//ERROR MSG SET AND GET
	void setMessage(char * msg);
	const char * getMessage();

	//OPERATOR<<
	friend std::ostream & operator<<(std::ostream & stream, const Exception & except);
#pragma endregion
};
#pragma endregion

#endif