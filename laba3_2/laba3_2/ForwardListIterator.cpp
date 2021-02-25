#include "ForwardListIterator.h"

template<class T>
ForwardListIterator<T>::ForwardListIterator()
{
	node = nullptr;
}

template<class T>
ForwardListIterator<T>::ForwardListIterator(ForwardListNode<T>* _node)
{
	node = _node;
}

template<class T>
ForwardListIterator<T> ForwardListIterator<T>::operator++()
{
	if (node != nullptr)
	{
		node = node->GetNext();
	}
	return *this;
}

template<class T>
ForwardListIterator<T> ForwardListIterator<T>::operator++(int)
{
	ForwardListIterator<T> temp = *this;
	if (node != nullptr)
	{
		node = node->GetNext();
	}
	return temp;
}

template<class T>
ForwardListNode<T> ForwardListIterator<T>::operator*()
{
	return *node;
}

template<class T>
bool ForwardListIterator<T>::operator==(ForwardListIterator<T> iter)
{
	return node == iter.node;
}



template<class T>
bool ForwardListIterator<T>::operator!=(ForwardListIterator<T> iter)
{
	return node != iter.node;
}

