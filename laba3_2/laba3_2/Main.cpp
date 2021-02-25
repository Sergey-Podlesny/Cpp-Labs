#include <iostream>
#include <forward_list>
#include "ForwardList.h"
#include "ForwardListNode.h"
#include "ForwardListIterator.h"

using namespace std;

template<class T>
void ShowList(ForwardList<T> obj)
{
	cout << "\tList: ";
	while (obj.GetFirstNode())
	{
		cout << obj.GetFirstNode()->GetData() << " ";
		obj.SetFirstNode(obj.GetFirstNode()->GetNext());
	}
	cout << endl;
}

template<class T>
void Incr(ForwardListIterator<T>& iter)
{
	ForwardListNode<T> node = *iter;
	cout << node.GetData() << endl;
	iter++;

}

int main()
{

	

	ForwardList<int> myList;
	cout << "PushFront(1):\n";
	myList.PushFront(1);
	ShowList(myList);
	cout << "PushBack(2):\n";
	myList.PushBack(2);
	ShowList(myList);
	cout << "PushBack(3):\n";
	myList.PushBack(3);
	ShowList(myList);
	cout << "PushFront(4):\n";
	myList.PushFront(4);
	ShowList(myList);
	cout << "PushBack(5):\n";
	myList.PushBack(5);
	ShowList(myList);
	cout << "PushFront(6):\n";
	myList.PushFront(6);
	ShowList(myList);

	cout << "PopFront() x3:\n";
	for (int i = 0; i < 3; i++)
	{
		myList.PopFront();
	}
	ShowList(myList);
	cout << "Front():\n";
	auto node =  myList.Front();
	cout << node.GetData() << endl;
	ShowList(myList);

	cout << "Work with iterator:\n";
	ForwardListIterator<int> myIter(myList.GetFirstNode());
	ForwardListIterator<int> myIter2 = myIter;
	ForwardListIterator<int> myIter3;

	if (myIter == myIter2)
	{
		cout << "uspeh\n";
	}
	if (myIter2 != myIter3)
	{
		cout << "uspeh x2\n";
	}
	for (int i = 0; i < 5; i++)
	{
		Incr(myIter);
	}
	/*
	int choice, num;
	do
	{
		cout << "1. PushBack\n";
		cout << "2. PushFront\n";
		cout << "3. PopFront\n";
		cout << "4. Exit\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "number: ";
			cin >> num;
			myList.PushBack(num);
			break;
		case 2:
			cout << "number: ";
			cin >> num;
			myList.PushFront(num);
			break;
		case 3:
			myList.PopFront();
			break;
		}
		ShowList(myList);
	} while (choice != 4);*/


	return 0;
}