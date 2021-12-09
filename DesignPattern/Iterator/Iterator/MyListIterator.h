#pragma once
#include "BaseIterator.h"
#include "ListNode.h"

template<typename T>
class MyListIterator : public BaseIterator<T>
{
public:
	void next() override;
	bool isDone() override;

	MyListIterator(ListNode<T>* _node) : m_Node(_node) {}

	T operator *();
	MyListIterator<T> operator ++();
	bool operator !=(const MyListIterator<T>& _other);

	void SetValue(const T &_val);

private:
	ListNode<T>* m_Node;

};

template<typename T>
inline void MyListIterator<T>::next()
{
	if (m_Node)
	{
		m_Node = m_Node->next;
	}
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
inline MyListIterator<T> MyListIterator<T>::operator++()
{
	next();
	return *this;
}

template<typename T>
inline bool MyListIterator<T>::operator!=(const MyListIterator<T>& _other)
{
	return this->m_Node != _other.m_Node;
}

template<typename T>
inline void MyListIterator<T>::SetValue(const T& _val)
{
	m_Node->_data = _val;
}
