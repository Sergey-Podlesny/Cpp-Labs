#include "Restaurantr.h"
#include "Employee.h"
#include "Waiter.h"
#include <string>
#include <algorithm>
#include <Windows.h>


// конструктор по умолчанию
Restaurant::Restaurant()
{
	CountOfTables = CountOfFreeTables = 10;
	TablesIsFree = new bool[CountOfTables];
	CourierIsFree = WaiterIsFree = true;
	StartTime.tm_hour = 9;
	StartTime.tm_min = 0;
	EndTime.tm_hour = 20;
	EndTime.tm_min = 0;
}

// перегруженный конструктор с параметрами
// поля CourierIsFree и WaiterIsFree имеют значения по умолчанию
Restaurant::Restaurant(vector<Waiter> _Waiters, vector<Deliveryman> _Deliverymen, int table, string adress, string name, int hourSt, int minuteSt, int hourEnd, int minuteEnd, bool courier, bool waiter)
{
	Waiters = _Waiters;
	Deliverymen = _Deliverymen;
	CountOfTables = CountOfFreeTables = table;
	AddressOfRest = adress;
	NameOfRest = name;
	StartTime.tm_hour = (hourSt > 23 || hourSt < 0) ? 9 : hourSt;
	StartTime.tm_min = (minuteSt > 60 || minuteSt < 0) ? 10 : minuteSt;
	EndTime.tm_hour = (hourEnd > 23 || hourEnd < 0) ? 19 : hourEnd;
	EndTime.tm_min = (minuteEnd > 60 || minuteEnd < 0) ? 10 : minuteEnd;
	CourierIsFree = courier;
	WaiterIsFree = waiter;
	TablesIsFree = new bool[CountOfTables];
	for (int i = 0; i < CountOfTables; i++)
	{
		TablesIsFree[i] = true;
	}
}

// конструктор копирования
Restaurant::Restaurant(const Restaurant& obj)
{
	Waiters = obj.Waiters;
	Deliverymen = obj.Deliverymen;
	CountOfTables = obj.CountOfTables;
	CountOfFreeTables = obj.CountOfFreeTables;
	AddressOfRest = obj.AddressOfRest;
	NameOfRest = obj.NameOfRest;
	StartTime = obj.StartTime;
	EndTime = obj.EndTime;
	CourierIsFree = obj.CourierIsFree;
	WaiterIsFree = obj.WaiterIsFree;
	TablesIsFree = new bool[CountOfTables];
	for (int i = 0; i < CountOfTables; i++)
	{
		TablesIsFree[i] = obj.TablesIsFree[i];
	}
}

// деструктор
Restaurant::~Restaurant()
{
	delete[] TablesIsFree;
}




//дальше идут сетеры и гетеры к privat полям класса

void Restaurant::SetCountOfTables(int count)
{
	CountOfTables = count;
}

int Restaurant::GetCountOfTables()
{
	return CountOfTables;
}

int Restaurant::GetCountOfFreeTables()
{
	return CountOfFreeTables;
}

void Restaurant::SetStatusCourier(bool status)
{
	CourierIsFree = status;
}

bool Restaurant::GetStatusCourier()
{
	return CourierIsFree;
}

void Restaurant::SetStatusWaiter(bool status)
{
	WaiterIsFree = status;
}

bool Restaurant::GetStatusWaiter()
{
	return WaiterIsFree;
}

void Restaurant::SetAddress(string address)
{
	AddressOfRest = address;
}

string Restaurant::GetAddress()
{
	return AddressOfRest;
}

void Restaurant::SetName(string name)
{
	NameOfRest = name;
}

string Restaurant::GetName()
{
	return NameOfRest;
}

// перегрузка основных операторов
ostream& operator<<(ostream& stream, Restaurant& obj)
{
	stream << "Name of restaurant: " << obj.NameOfRest << ".";
	stream << " Common count of tables: " << obj.CountOfTables;
	stream << ". Works From " << obj.StartTime.tm_hour << ":" << obj.StartTime.tm_min;
	stream << " to " << obj.EndTime.tm_hour << ":" << obj.EndTime.tm_min << endl;

	return stream;
}

istream& operator>>(istream& stream, Restaurant& obj)
{
	rewind(stdin);
	cout << "Name of rest: ";
	getline(stream, obj.NameOfRest);
	cout << "Address of rest: ";
	getline(stream, obj.AddressOfRest);
	cout << "Count of tables: ";
	stream >> obj.CountOfTables;
	cout << "Timt of work: ";
	stream >> obj.StartTime.tm_hour >> obj.StartTime.tm_min;
	stream >> obj.EndTime.tm_hour >> obj.EndTime.tm_min;
	delete[] obj.TablesIsFree;
	obj.TablesIsFree = new bool[obj.CountOfTables];
	for (int i = 0; i < obj.CountOfTables; i++)
	{
		obj.TablesIsFree[i] = true;
	}
	return stream;
}

Restaurant Restaurant::operator=(Restaurant obj)
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

// перегрузка пре-инкремента для поля CountOfFreeTables
Restaurant Restaurant::operator++()
{
	CountOfFreeTables = (CountOfFreeTables >= CountOfTables) ? CountOfFreeTables : CountOfFreeTables + 1;
	return *this;
}

// перегрузка пост-инкремента для поля CountOfTables
Restaurant Restaurant::operator++(int a)
{
	Restaurant temp = *this;
	CountOfTables++;
	return temp;
}

// перегрузка пре-декремента для поля CountOfFreeTables
Restaurant Restaurant::operator--()
{
	CountOfFreeTables = (CountOfFreeTables > 0) ? CountOfFreeTables - 1 : CountOfFreeTables;
	return *this;
}

// перегрузка пост-денкремента для поля CountOfTables
Restaurant Restaurant::operator--(int a)
{
	Restaurant temp = *this;
	CountOfTables = (CountOfTables > 0) ? CountOfTables - 1 : CountOfTables;
	return temp;
}

// перегрузка оператора ">" для поля CountOfTables
bool Restaurant::operator>(Restaurant obj)
{
	return CountOfTables > obj.CountOfTables;
}

// перегрузка оператора "<" для поля NameOfRest
bool Restaurant::operator<(Restaurant obj)
{
	return NameOfRest < obj.NameOfRest;
}

bool Restaurant::operator==(Restaurant obj)
{
	return (CountOfTables == obj.CountOfTables &&
		NameOfRest == obj.NameOfRest);
}

void Restaurant::SortWaitersByName()
{
	sort(Waiters.begin(), Waiters.end(), [](Waiter obj1, Waiter obj2)
		{
			return obj1 < obj2;
		}
	);
}

void Restaurant::SortWaitersBySalary()
{
	sort(Waiters.begin(), Waiters.end(), [](Waiter obj1, Waiter obj2)
		{
			return obj2 > obj1;
		}
	);
}

void Restaurant::SortDeliverymenByName()
{
	sort(Deliverymen.begin(), Deliverymen.end(), [](Deliveryman obj1, Deliveryman obj2)
		{
			return obj1 < obj2;
		}
	);
}

void Restaurant::SortDeliverymenBySalary()
{
	sort(Deliverymen.begin(), Deliverymen.end(), [](Deliveryman obj1, Deliveryman obj2)
		{
			return obj2 > obj1;
		}
	);
}


void Restaurant::MakeAnOrder1()
{
	if (Waiters.size() == 0)
	{
		cout << "No waiters" << endl;
		return;
	}
	int choice;
	cout << "Choose a waiter:\n";
	for (int i = 0; i < Waiters.size(); i++)
	{
		cout << i + 1 << ": " << Waiters[i] << endl;
	}
	do
	{
		cin >> choice;
	} while (choice < 1 || choice > Waiters.size());
	Waiters[choice - 1].Work();

}

// метод, имитирующий заказ стола
void Restaurant::OrderOfTable()
{
	int n;
	cout << "Free teables are:\n";
	for (int i = 0; i < CountOfTables; i++)
	{
		cout << "Table #" << i + 1<< ((TablesIsFree[i]) ? " free" : " not free") << endl;
	}
	cout << "Your choice is: ";
	do
	{
		cin >> n;
	} while (n <= 0 || n > CountOfTables);
	if (TablesIsFree[n - 1])
	{
		cout << "Table booked successfully.\n\n";
		TablesIsFree[n - 1] = false;
	}
	else
	{
		cout << "This table is already booked.\n\n";
	}
}


void Restaurant::Delivery1()
{
	if (Deliverymen.size() == 0)
	{
		cout << "No deliverymen" << endl;
		return;
	}
	int choice;
	cout << "Choose a deliveryman:\n";
	for (int i = 0; i < Deliverymen.size(); i++)
	{
		cout << i + 1 << ": " << Deliverymen[i] << endl;
	}
	do
	{
		cin >> choice;
	} while (choice < 1 || choice > Deliverymen.size());
	Deliverymen[choice - 1].Work();
}

void Restaurant::FireAnWaiter()
{
	if (Waiters.size() == 0)
	{
		cout << "No waiters\n";
		return;
	}
	for (int i = 0; i < Waiters.size(); i++)
	{
		Waiters[i].PremiumRecalculation();
		cout << Waiters[i].GetPremium() << endl;
	}
	int ch;
	cout << "Waiters:\n";

	for (int i = 0; i < Waiters.size(); i++)
	{
		cout << i + 1 << ". " << Waiters[i] << "; Salary: " << Waiters[i].GetSalary() << "; Premium: " << Waiters[i].GetPremium() << "; Rating: " << Waiters[i].GetCurrentRating() << endl;
	}
	cout << Waiters.size() + 1 << ". Exit\n";

	do
	{
		cin >> ch;
	} while (ch < 1 || ch > Waiters.size() + 1);
	if (ch == Waiters.size() + 1)
	{
		return;
	}
	else
	{
		Waiters.erase(Waiters.begin() + ch - 1);
	}
}

void Restaurant::FireAnDeliveryman()
{
	if (Deliverymen.size() == 0)
	{
		cout << "No deliverymen\n";
		return;
	}
	for (int i = 0; i < Deliverymen.size(); i++)
	{
		Deliverymen[i].PremiumRecalculation();
		cout << Deliverymen[i].GetPremium() << endl;
	}
	int ch;
	cout << "Deliverymen:\n";

	for (int i = 0; i < Deliverymen.size(); i++)
	{
		cout << i + 1 << ". " << Deliverymen[i] << "; Salary: " << Deliverymen[i].GetSalary() << "; Premium: " << Deliverymen[i].GetPremium() << "; Rating: " << Deliverymen[i].GetCurrentRating() << endl;
	}
	cout << Deliverymen.size() + 1 << ". Exit\n";
	do
	{
		cin >> ch;
	} while (ch < 1 || ch > Deliverymen.size() + 1);
	if (ch == Deliverymen.size() + 1)
	{
		return;
	}
	else
	{
		Deliverymen.erase(Deliverymen.begin() + ch - 1);
	}
}