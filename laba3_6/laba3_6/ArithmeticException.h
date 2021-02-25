#pragma once
#include "MyExcep.h"

class ArithmeticException : public MyExcep 
{
public:
	ArithmeticException()
	{
		message = "Error. ArithmeticException.";
	}
	ArithmeticException(string msg)
	{
		message = msg;
	}
	string GetMessage()
	{
		return message;
	}
};

