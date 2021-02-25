#pragma once
#include "MyExcep.h"

class InputException : public MyExcep
{
public:
	InputException()
	{
		message = "Error. InputException";
	}
	InputException(string msg)
	{
		message = msg;
	}
	string GetMessage()
	{
		return message;
	}
};