#pragma once
#include <iostream>
using std::string;
class Car
{
	string mark;
	int id, yearOfIssue;
	double maxSpeed;
public:
	Car() {}
	Car(string _mark, int _id, int _yearOfIssue, double _maxSpeed)
	{
		mark = _mark;
		id = _id;
		yearOfIssue = _yearOfIssue;
		maxSpeed = _maxSpeed;
	}

	void Show()
	{
		std::cout << "Car: " << mark << " id: " << id << " yearOfIssue: " << yearOfIssue << " maxSpeed: " << maxSpeed << std::endl;
	}
};