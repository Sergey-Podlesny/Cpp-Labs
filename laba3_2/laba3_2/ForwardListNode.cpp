#include "ForwardListNode.h"

template<class T>
ForwardListNode<T>::ForwardListNode()
{
	data = -1;
	next = nullptr;
}

template<class T>
void ForwardListNode<T>::SetData(T _data)
{
	data = _data;
}

template<class T>
T ForwardListNode<T>::GetData()
{
	return data;
}

template<class T>
void ForwardListNode<T>::SetNext(ForwardListNode<T>* _next)
{
	next = _next;
}

template<class T>
ForwardListNode<T>* ForwardListNode<T>::GetNext()
{
	return next;
}
