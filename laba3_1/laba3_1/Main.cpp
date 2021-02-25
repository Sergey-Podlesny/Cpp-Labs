#include <iostream>
#include "Restaurantr.h"
using namespace std;

Restaurant& Fun()
{
	Restaurant obj;
	return obj;
}

int main()
{

	cout << sizeof(int*);

	/*Restaurant obj1(3, "Zhukovsky 5/1", "Sgushchonka Style", 9, 10, 18, 30);
	Restaurant obj2(2, "", "Test", 8, 3, 2, 2);
	Restaurant obj3(3, "", "Sgushchonka Style", 9, 2, 4, 1);
	if (obj1 > obj2)
	{
		cout << "Test1\n";
	}
	if (obj3 < obj2)
	{
		cout << "Test2\n";
	}
	if (obj1 == obj3)
	{
		cout << "Test3\n";
	}*/
	return 0;
}