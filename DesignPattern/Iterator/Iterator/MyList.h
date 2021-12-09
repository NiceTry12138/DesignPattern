#pragma once

#include "ListNode.h"
#include "MyListIterator.h"
#include <assert.h>

template<typename T>
class MyList
{
public:
	MyList();
	virtual ~MyList();

	void push_back(const T &_val);
	T pop_back();

	size_t Size();

	MyListIterator<T> begin();
	MyListIterator<T> end();

protected:
	ListNode<T>* GetLastNode();

private:
	size_t m_Size{ 0 };
	ListNode<T>* m_head{ nullptr };
};

template<typename T>
inline MyList<T>::MyList()
{
	m_head = new ListNode<T>();
}

template<typename T>
inline MyList<T>::~MyList()
{
	auto LastNode = GetLastNode();
	if (LastNode == nullptr)
	{
		return;
	}
	auto BehindNode = LastNode->behind;
	while (BehindNode)
	{
		delete LastNode;
		LastNode = BehindNode;
		BehindNode = LastNode->behind;
	}
}

template<typename T>
inline void MyList<T>::push_back(const T& _val)
{
	auto node = new ListNode<T>(_val);
	auto LastNode = GetLastNode();
	node->behind = LastNode;
	LastNode->next = node;
	++m_Size;
}

template<typename T>
inline T MyList<T>::pop_back()
{
	auto LastNode = GetLastNode();
	if (LastNode == m_head)
	{
		assert(0);
		return 0;
	}
	auto NowLastNode = LastNode->behind;
	NowLastNode->next = nullptr;
	T result = LastNode->_data;
	delete LastNode;
	--m_Size;
	return result;
}

template<typename T>
inline size_t MyList<T>::Size()
{
	return m_Size;
}

template<typename T>
inline MyListIterator<T> MyList<T>::begin()
{
	return MyListIterator<T>(m_head->next);
}

template<typename T>
inline MyListIterator<T> MyList<T>::end()
{
	return MyListIterator<T>(nullptr);
}

template<typename T>
inline ListNode<T>* MyList<T>::GetLastNode()
{
	if (m_head->next == nullptr)
	{
		return m_head;
	}
	ListNode<T>* node = m_head;
	do 
	{
		node = node->next;
	} while (node && node->next);
	return node;
}
