#pragma once
#include <iostream>
using std::string;

class Flower
{
	string name;
	double temperature;
	int cost;
public:
	Flower() {}
	Flower(string _name, double _temperature, int _cost)
	{
		name = _name;
		temperature = _temperature;
		cost = _cost;
	}

	void Show()
	{
		std::cout << "Flower: " << name << " cost: " << cost << " temperature: " << temperature << std::endl;
	}
};
