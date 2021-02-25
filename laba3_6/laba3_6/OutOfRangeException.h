#pragma once
#include "MyExcep.h"

class OutOfRangeException : public MyExcep
{
public:
	OutOfRangeException()
	{
		message = "Error. OutOfRangeException";
	}
	OutOfRangeException(string msg) 
	{
		message = msg;
	}
	string GetMessage()
	{
		return message;
	}
};