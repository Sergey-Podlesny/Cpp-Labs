#pragma once
#include "ArithmeticException.h"
class DivideByZeroException final : public ArithmeticException
{
public:
	DivideByZeroException() : ArithmeticException() 
	{
		message = "Error. DivideByZeroException";
	}
	DivideByZeroException(string msg) : ArithmeticException(msg) {}

	string GetMessage()
	{
		return message;
	}
};

