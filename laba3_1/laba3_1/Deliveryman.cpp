#include "Deliveryman.h"
#include <Windows.h>

using std::string;

Deliveryman::Deliveryman() : Employee()
{
	AddressOfDelivey = "";
}

Deliveryman::Deliveryman(string _AddressOfDelivey, string Name, bool Status, int Salary)
	: Employee(Name, Status, Salary)
{
	AddressOfDelivey = _AddressOfDelivey;
}

Deliveryman::Deliveryman(const Deliveryman& obj) : Employee(obj)
{
	FuelCosts = obj.FuelCosts;
	AddressOfDelivey = obj.AddressOfDelivey;
}

void Deliveryman::Work()
{
	if (IsFree)
	{
		std::cout << "Wait, delivery man is coming to you";
		for (int i = 0; i < 3; i++)
		{
			std::cout << '.';
			Sleep(1000);
		}
		std::cout << "\nSuccessfully!" << std::endl;
		RateTheService();
		FuelCosts += 30;
	}
	else
	{
		std::cout << "Delivery man is busy." << std::endl;
	}
}

void Deliveryman::PremiumRecalculation()
{
	Premium = 0.3 * Salary + FuelCosts;
}

ostream& operator<<(ostream& stream, Deliveryman& obj)
{
	stream << "Name: " << obj.Name << "; Status: " << (obj.IsFree ? "Free" : "Buzy");
	return stream;
}

istream& operator>>(istream& stream, Deliveryman& obj)
{
	rewind(stdin);
	cout << "Name: ";
	getline(stream, obj.Name);
	cout << "Salary: ";
	stream >> obj.Salary;
	cout << "Address of delivey: ";
	rewind(stdin);
	getline(stream, obj.AddressOfDelivey);
	return stream;

}