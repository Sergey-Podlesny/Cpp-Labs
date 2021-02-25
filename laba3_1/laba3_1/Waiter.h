#pragma once
#include "Employee.h"

class Waiter : public Employee
{
	int Tip = 0, CountOfActiveOrders;
public:
	Waiter();
	Waiter(int, string, bool, int);
	Waiter(const Waiter&);

	void Work();
	void PremiumRecalculation();

	friend ostream& operator<<(ostream&, Waiter&);
	friend istream& operator>>(istream&, Waiter&);
};