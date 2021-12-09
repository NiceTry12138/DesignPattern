#pragma once
#include "BaseIterator.h"
#include "ListNode.h"

template<typename T>
class MyListIterator : public BaseIterator<T>
{
public:
	void next() override;
	void behind() override;
	bool isDone() override;

	MyListIterator(ListNode<T>* _node, ListNode<T>* _head, bool reverse = false) : m_Node(_node), m_Head(_head), BaseIterator<T>(reverse) {}

	T operator *();
	MyListIterator<T>& operator ++();
	MyListIterator<T>& operator --();
	bool operator !=(const MyListIterator<T>& _other);

	void SetVal(const T &_val) override;

private:
	ListNode<T>* m_Node;
	ListNode<T>* m_Head;

};

template<typename T>
inline void MyListIterator<T>::next()
{
	m_Node = m_Node->next;
}

template<typename T>
inline void MyListIterator<T>::behind()
{
	m_Node = m_Node->behind;
}

template<typename T>
inline bool MyListIterator<T>::isDone()
{
	return m_Node == nullptr;
}

template<typename T>
inline T MyListIterator<T>::operator*()
{
	return m_Node->_data;
}

template<typename T>
inline MyListIterator<T>& MyListIterator<T>::operator++()
{
	if (BaseIterator<T>::ISReverse())
	{
		behind();
	}
	else {
		next();
	}
	return *this;
}

template<typename T>
inline MyListIterator<T>& MyListIterator<T>::operator--()
{
	if (BaseIterator<T>::ISReverse())
	{
		next();
	}
	else {
		behind();
	}
	return *this;
}

template<typename T>
inline bool MyListIterator<T>::operator!=(const MyListIterator<T>& _other)
{
	return this->m_Node != _other.m_Node;
}

template<typename T>
inline void MyListIterator<T>::SetVal(const T& _val)
{
	m_Node->_data = _val;
}
