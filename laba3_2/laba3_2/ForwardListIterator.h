#pragma once
#include "ForwardListNode.h"

template<class T>
class ForwardListIterator
{
	ForwardListNode<T>* node;
public:
	ForwardListIterator();
	ForwardListIterator(ForwardListNode<T>*);
	
	ForwardListIterator<T> operator++();
	ForwardListIterator<T> operator++(int);
	ForwardListNode<T> operator*();
	bool operator==(ForwardListIterator<T>);
	bool operator!=(ForwardListIterator<T>);
};	


template class ForwardListIterator<int>;