#include "Employee.h"

Employee::Employee()
{
	Name = "";
	IsFree = true;
	Salary = 0;
}

Employee::Employee(string _Name, bool _IsFree, int _Salary)
{
	Name = _Name;
	IsFree = _IsFree;
	Salary = _Salary;
}

Employee::Employee(const Employee& obj)
{
	Name = obj.Name;
	IsFree = obj.IsFree;
	Salary = obj.Salary;
	Premium = obj.Premium;
	RatingList = obj.RatingList;
}

string Employee::GetName()
{
	return Name;
}

int Employee::GetSalary()
{
	return Salary;
}

int Employee::GetPremium()
{
	return Premium;
}

bool Employee::GetStatus()
{
	return IsFree;
}

bool Employee::operator>(Employee& obj)
{
	return Salary > obj.Salary;
}

bool Employee::operator<(Employee& obj)
{
	return Name < obj.Name;
}


void Employee::RateTheService()
{
	int Rate;
	std::cout << "Rate the service[1-5]: ";
	do
	{
		std::cin >> Rate;
	} while (Rate < 1 || Rate > 5);
	RatingList.push_back(Rate);
}

double Employee::GetCurrentRating()
{
	double Rate = 0;
	for (int i = 0; i < RatingList.size(); i++)
	{
		Rate += RatingList[i];
	}

	return (RatingList.size() == 0) ? -1 : Rate / RatingList.size();
}


