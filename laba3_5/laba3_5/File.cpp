#include "File.h"
#include <iostream>

using std::string;
using std::cin;
using std::cout;

template<class T>
File<T>::File(string fileName)
{
	this->fileName = fileName;
}



template<class T>
void File<T>::write(T obj, int mode)
{
	(mode == 0) ? fout.open(fileName) : fout.open(fileName, ofstream::app);
	fout.write((char*)&obj, sizeof(T));
	fout.close();
}

template<class T>
void File<T>::writeBin(T obj, int mode)
{
	(mode == 0) ? fout.open(fileName, ofstream::binary) : fout.open(fileName, ofstream::app, ofstream::binary);
	fout.write((char*)&obj, sizeof(T));
	fout.close();
}

template<class T>
bool File<T>::read(T& obj)
{
	bool isNotEmpty = true;
	if (!fin.is_open())
	{
		fin.open(fileName);
	}
	if (!fin.read((char*)&obj, sizeof(T)))
	{
		isNotEmpty = false;
		fin.close();
	}
	return isNotEmpty;
}

template<class T>
bool File<T>::readBin(T& obj)
{
	bool isNotEmpty = true;
	if (!fin.is_open())
	{
		fin.open(fileName, ifstream::binary);
	}
	if (!fin.read((char*)&obj, sizeof(T)))
	{
		isNotEmpty = false;
		fin.close();
	}
	return isNotEmpty;
}



template<class T>
void File<T>::operator<<(T obj)
{
	fout.open(fileName, ofstream::app);
	fout.write((char*)&obj, sizeof(T));
	fout.close();
}

template<class T>
bool File<T>::operator>>(T& obj)
{
	
	bool isNotEmpty = true;
	if (!fin.is_open())
	{
		fin.open(fileName);
	}
	if (!fin.read((char*)&obj, sizeof(T)))
	{
		isNotEmpty = false;
		fin.close();
	}
	return isNotEmpty;
}
