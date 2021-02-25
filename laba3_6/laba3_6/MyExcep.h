#pragma once
#include <iostream>
using std::string;

class MyExcep
{
protected:
	string message;
public:
	virtual string GetMessage() = 0;
};

