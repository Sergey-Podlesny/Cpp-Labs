#pragma once

template<class T>
class ForwardListNode
{
	T data;
	ForwardListNode<T>* next;

public:
	ForwardListNode();

	void SetData(T);
	T GetData();

	void SetNext(ForwardListNode<T>*);
	ForwardListNode<T>* GetNext();
};

template class ForwardListNode<int>;