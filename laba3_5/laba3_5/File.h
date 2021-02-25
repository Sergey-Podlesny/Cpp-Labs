#pragma once
#include <fstream>
#include "Car.h"
#include "Flower.h"

using std::ofstream;
using std::ifstream;
using std::string;

template<class T>
class File
{
	string fileName = "myOwnFile.txt";
	ofstream fout; 
	ifstream fin;
public:
	File() {};
	File(string);


	void write(T, int = 0); // ����� ��� ������ � ��������� ����, � ������� ������ ������(0 - � ����, 1 - ��������)
	void writeBin(T, int = 0); // ����� ��� ������ � �������� ����, � ������� ������ ������(0 - � ����, 1 - ��������)
	bool read(T&);
	bool readBin(T&);

	void operator<<(T); // ����������� �������� �������� � ����
	bool operator>>(T&); // ������������� �������� ������ �� �����
};


template class File<Car>;
template class File<Flower>;
template class File<int>;
