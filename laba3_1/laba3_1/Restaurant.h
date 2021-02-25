#pragma once
#include <iostream>
#include <time.h>

using namespace std;

class Restaurant
{
	int CountOfTables, CountOfFreeTables;
	bool* TablesIsFree, FoodAvailability;
	string AddressOfRest, NameOfRest;
	tm StartTime, EndTime;
public:
	Restaurant Fun()
	{
		Restaurant tmp;
		return tmp;
	}

	Restaurant() {}
	Restaurant(int table, string adress, string name, int hourSt, int minuteSt, int hourEnd, int minuteEnd, bool foodAvail = true)
	{
		CountOfTables = CountOfFreeTables = table;
		AddressOfRest = adress;
		NameOfRest = name;
		StartTime.tm_hour = hourSt;
		StartTime.tm_min = minuteSt;
		EndTime.tm_hour = hourEnd;
		EndTime.tm_min = minuteEnd;
		TablesIsFree = new bool[CountOfFreeTables];
		for (int i = 0; i < CountOfTables; i++)
		{
			TablesIsFree[i] = true;
		}
	}

	Restaurant(const Restaurant &obj)
	{
		CountOfTables = obj.CountOfTables;
		CountOfFreeTables = obj.CountOfFreeTables;
		AddressOfRest = obj.AddressOfRest;
		NameOfRest = obj.NameOfRest;
		StartTime = obj.StartTime;
		EndTime = obj.EndTime;
		TablesIsFree = new bool[CountOfTables];
		for (int i = 0; i < CountOfTables; i++)
		{
			TablesIsFree[i] = obj.TablesIsFree[i];
		}
	}

	~Restaurant()
	{
		delete[] TablesIsFree;
	}

	string GetName()
	{
		return NameOfRest;
	}

	int GetCountOfFreeTables()
	{
		return CountOfFreeTables;
	}

	void SetCountOfFreeTables(int count)
	{
		CountOfFreeTables = (count >= CountOfTables) ? CountOfFreeTables : count;
	}

	Restaurant operator=(Restaurant obj)
	{
		CountOfTables = obj.CountOfTables;
		CountOfFreeTables = obj.CountOfFreeTables;
		AddressOfRest = obj.AddressOfRest;
		NameOfRest = obj.NameOfRest;
		StartTime = obj.StartTime;
		EndTime = obj.EndTime;
		TablesIsFree = new bool[CountOfTables];
		for (int i = 0; i < CountOfTables; i++)
		{
			TablesIsFree[i] = obj.TablesIsFree[i];
		}
		return *this;
	}

	Restaurant operator++()
	{
		CountOfFreeTables = (CountOfFreeTables >= CountOfTables) ? CountOfFreeTables : CountOfFreeTables + 1;
		return *this;
	}

	Restaurant operator++(int a)
	{
		Restaurant temp = *this;
		CountOfFreeTables = (CountOfFreeTables >= CountOfTables) ? CountOfFreeTables : CountOfFreeTables + 1;
		return temp;
	}

	Restaurant operator--()
	{
		CountOfFreeTables = (CountOfFreeTables > 0) ? CountOfFreeTables - 1 : CountOfFreeTables;
		return *this;
	}

	Restaurant operator--(int a)
	{
		Restaurant temp = *this;
		CountOfFreeTables = (CountOfFreeTables > 0) ? CountOfFreeTables - 1: CountOfFreeTables;
		return temp;
	}

	Restaurant operator+(Restaurant obj)
	{
		Restaurant temp;
		temp.CountOfFreeTables = CountOfFreeTables + obj.CountOfFreeTables;
		return temp;
	}

	Restaurant operator-(Restaurant obj)
	{
		Restaurant temp;
		temp.CountOfFreeTables = CountOfFreeTables - obj.CountOfFreeTables;
		temp.CountOfFreeTables = (temp.CountOfFreeTables < 0) ? 0 : temp.CountOfFreeTables;
		return temp;
	}

	bool operator>(Restaurant obj)
	{
		return CountOfTables > obj.CountOfTables;
	}

	bool operator<(Restaurant obj)
	{
		return NameOfRest < obj.NameOfRest;
	}

	bool operator==(Restaurant obj)
	{
		return (CountOfTables == obj.CountOfTables &&
			NameOfRest == obj.NameOfRest);
	}

	friend ostream& operator<<(ostream& stream, Restaurant obj);

	void ShowInfo()
	{
		cout << "Restaurant: " << NameOfRest << ".";
		cout << " Works From " << StartTime.tm_hour << ":" << StartTime.tm_min;
		cout << " to " << EndTime.tm_hour << ":" << EndTime.tm_min << endl;
	}

	int OrderOfProducts()
	{
		return FoodAvailability;
	}

	int OrderOfTable(int num)
	{
		return TablesIsFree[num];
	}

	int Delivery(string DeliveryAdress)
	{
		return ((DeliveryAdress.length() - AddressOfRest.length()) > 0) ? false : true;
	}

};

ostream& operator<<(ostream& stream, Restaurant obj)
{
	stream << "Restaurant: " << obj.NameOfRest << ".";
	stream << " Works From " << obj.StartTime.tm_hour << ":" << obj.StartTime.tm_min;
	stream << " to " << obj.EndTime.tm_hour << ":" << obj.EndTime.tm_min << endl;
	return stream;
}