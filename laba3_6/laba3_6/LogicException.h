#pragma once
#include "MyExcep.h"
using std::string;

class LogicException : public MyExcep
{
public:
	LogicException()
	{
		message = "Error. LogicException";
	}
	LogicException(string msg)
	{
		message = msg;
	}
	string GetMessage()
	{
		return message;
	}
};

