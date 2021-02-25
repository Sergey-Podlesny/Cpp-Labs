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


	void write(T, int = 0); // метод для записи в текстовый файл, с выбором метода записи(0 - с нуля, 1 - дозапись)
	void writeBin(T, int = 0); // метод для записи в бинарный файл, с выбором метода записи(0 - с нуля, 1 - дозапись)
	bool read(T&);
	bool readBin(T&);

	void operator<<(T); // перегружный оператор дозаписи в файл
	bool operator>>(T&); // перегруженный оператор чтения из файла
};


template class File<Car>;
template class File<Flower>;
template class File<int>;
