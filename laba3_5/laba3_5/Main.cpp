#include <iostream>
#include <fstream>
#include "File.h"
#include "Car.h"
#include "Flower.h"

using namespace std;




int main()
{
	Flower rose("rose", 23.1, 13), lily("lily", 15.2, 18), chamomile("chamomile", 10.9, 3);
	Car audi("audi", 19320, 1994, 150), bmw("bmw", 43221, 2001, 140), lada("lada", 11111, 2047, 666);

	File<Flower> fileFlower("flowerFile.txt");
	fileFlower.write(rose, 0);
	fileFlower.write(lily, 1);
	fileFlower.write(chamomile, 1);
	Flower bufF;
	while (fileFlower >> bufF)
	{
		bufF.Show();
	}

	File<Car> fileCar("carFile.txt");
	fileCar << audi;
	fileCar << bmw;
	fileCar << lada;
	Car bufC;
	while (fileCar >> bufC)
	{
		bufC.Show();
	}
	return 0;
}