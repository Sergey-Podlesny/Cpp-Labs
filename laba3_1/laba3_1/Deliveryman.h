#pragma once
#include "Employee.h"
using std::string;

class Deliveryman : public Employee
{
	int FuelCosts = 0;
	string AddressOfDelivey;
public:
	Deliveryman();
	Deliveryman(string, string, bool, int);
	Deliveryman(const Deliveryman&);

	void Work();
	void PremiumRecalculation();

	friend ostream& operator<<(ostream&, Deliveryman&);
	friend istream& operator>>(istream&, Deliveryman&);
};