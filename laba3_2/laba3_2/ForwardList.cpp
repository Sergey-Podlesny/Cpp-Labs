#include "ForwardList.h"
#include "ForwardListNode.h"
#include "ForwardListIterator.h"

template<class T>
ForwardList<T>::ForwardList()
{
	firstNode = nullptr;
	size = 0;
}

template<class T>
void ForwardList<T>::SetFirstNode(ForwardListNode<T>* first)
{
	firstNode = first;
}

template<class T>
ForwardListNode<T>* ForwardList<T>::GetFirstNode()
{
	return firstNode;
}

template<class T>
void ForwardList<T>::PushFirst(T _data)
{
	firstNode = new ForwardListNode<T>;
	firstNode->SetData(_data);
	firstNode->SetNext(nullptr);
	size++;
}

template<class T>
void ForwardList<T>::PushFront(T _data)
{
	ForwardListNode<T>* temp;
	if(size > 0)
	{
		temp = new ForwardListNode<T>;
		temp->SetData(_data);
		temp->SetNext(firstNode);
		firstNode = temp;
		size++;
	}
	else
	{
		PushFirst(_data);
	}
	
}

template<class T>
void ForwardList<T>::PushBack(T _data)
{
	ForwardListNode<T>* temp = firstNode;
	if (size > 0)
	{
		while (temp->GetNext() != nullptr)
		{
			temp = temp->GetNext();
		}
		temp->SetNext(new ForwardListNode<T>);
		temp->GetNext()->SetData(_data);
		temp->GetNext()->SetNext(nullptr);
		size++;
	}
	else
	{
		PushFirst(_data);
	}
}

template<class T>
void ForwardList<T>::PopFront()
{
	if (firstNode != nullptr)
	{
		ForwardListNode<T>* temp = firstNode;
		firstNode = firstNode->GetNext();
		delete temp;
		size--;
	}
}

template<class T>
ForwardListNode<T> ForwardList<T>::Front()
{
	return *firstNode;
}



template<class T>
int ForwardList<T>::Size()
{
	return size;
}


