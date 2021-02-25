#pragma once
#include <fstream>
#include "Restaurantr.h"


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


	void write(T&);
	bool read(T&);

	void operator<<(T&);
	bool operator>>(T&);
};


template class File<Restaurant>;