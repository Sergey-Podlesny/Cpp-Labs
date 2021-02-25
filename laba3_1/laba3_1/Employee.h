#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Employee
{
protected:
	string Name;
	bool IsFree;
	int Salary, Premium = 0;
	std::vector<int> RatingList;
public:
	Employee();
	Employee(string, bool, int);
	Employee(const Employee&);

	string GetName();
	int GetSalary();
	int GetPremium();
	bool GetStatus();

	bool operator>(Employee&);
	bool operator<(Employee&);

	void RateTheService();
	double GetCurrentRating();
	void virtual Work() = 0;
	void virtual PremiumRecalculation() = 0;
};