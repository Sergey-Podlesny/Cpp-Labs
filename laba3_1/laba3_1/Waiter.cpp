#include "Waiter.h"
#include <Windows.h>
using std::string;

Waiter::Waiter() : Employee()
{
	CountOfActiveOrders = 0;
}

Waiter::Waiter(int _CountOfActiveOrders, string Name, bool Status, int Salary)
	: Employee(Name, Status, Salary)
{
	CountOfActiveOrders = _CountOfActiveOrders;
}

Waiter::Waiter(const Waiter& obj) : Employee(obj)
{
	Tip = obj.Tip;
	CountOfActiveOrders = obj.CountOfActiveOrders;
}

void Waiter::Work()
{
	if (IsFree)
	{
		int _Tip;
		std::cout << "Wait, your order will be ready soon";
		for (int i = 0; i < CountOfActiveOrders; i++)
		{
			std::cout << '.';
			Sleep(1000);
		}
		std::cout << "\nSuccessfully!" << std::endl;
		RateTheService();
		std::cout << "Tip for the waiter: ";
		do
		{
			std::cin >> _Tip;
		} while (_Tip < 0);
		Tip += _Tip;
	}
	else
	{
		std::cout << "Waiter is busy." << std::endl;
	}

}

void Waiter::PremiumRecalculation()
{
	Premium =  0.5 * (Tip + Salary);
}

ostream& operator<<(ostream& stream, Waiter& obj)
{
	stream << "Name: " << obj.Name << "; Status: " << (obj.IsFree ? "Free" :  "Buzy") << "; Count of active orders: " << obj.CountOfActiveOrders;
	return stream;
}

istream& operator>>(istream& stream, Waiter& obj)
{
	cout << "Name: ";
	rewind(stdin);
	getline(stream, obj.Name);
	cout << "Salary: ";
	stream >> obj.Salary;
	cout << "Count Of active orders: ";
	stream >> obj.CountOfActiveOrders;
	return stream;
}