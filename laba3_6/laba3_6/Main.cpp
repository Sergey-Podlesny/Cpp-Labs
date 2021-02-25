#include <iostream>
#include <time.h>
#include <exception>
#include "MyExcep.h"
#include "InputException.h"
#include "DivideByZeroException.h"
#include "LogicException.h"
#include "OutOfRangeException.h"


using std::cout;
using std::cin;
using std::endl;
using std::exception;

int Input()
{
	int num;
	cin >> num;
	if (cin.fail())
	{
		throw InputException();
	}
	return num;
}



int main()
{
	srand(time(NULL));
	int a, b, c;
	int* arr;
	int index, size;
	

	try
	{
		cout << "a = ";
		a = Input();
		cout << "b = ";
		b = Input();
		cout << "c = a / b = ";
		if (b == 0)
		{
			throw DivideByZeroException();
		}
		cout << (double)a / b << endl;
		
		cout << "size = ";
		size = Input();
		if (size < 1)
		{
			throw LogicException("Size cannot be less than 1");
		}
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 25;
			cout << "#" << i << " " << arr[i] << endl;
		}
		cout << "index = ";
		index = Input();
		if (index < 0 || index >= size)
		{
			throw OutOfRangeException();
		}
		cout << "#" << index << " = " << arr[index] << endl;
		cout << "random number: ";
		a = Input();
		if (a == 1)
		{
			throw exception("You WIN!");
		}
	}
	catch (MyExcep& e)
	{
		cout << e.GetMessage();
	}
	catch (exception e)
	{
		cout << e.what();
	}

	return 0;
}