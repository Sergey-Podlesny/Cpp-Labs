#pragma once
#include "ForwardListNode.h"
#include "ForwardListIterator.h"

template<class T>
class ForwardList
{
	ForwardListNode<T> *firstNode;
	int size;
public:
	ForwardList();

	void SetFirstNode(ForwardListNode<T>*);
	ForwardListNode<T>* GetFirstNode();

	void PushFirst(T);
	void PushFront(T);
	void PopFront();
	ForwardListNode<T> Front();

	void PushBack(T);
	int Size();
};

template class ForwardList<int>;