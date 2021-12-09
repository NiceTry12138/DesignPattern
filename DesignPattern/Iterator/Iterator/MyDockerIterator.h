#pragma once
#include "BaseIterator.h"
#include "MyBaseDocker.h"
template<typename T>
class MyDockerIterator : public BaseIterator<T>
{
public:
	MyDockerIterator(MyBaseDocker<T> *_docker, int _cur);

	virtual void next();
	T operator *();
	bool operator != (const MyDockerIterator<T> _other);
	MyDockerIterator<T>& operator ++ ();

	virtual bool isDone();

private:
	int m_cur{ 0 };
	MyBaseDocker<T>* m_Docker{ nullptr };
};

template<typename T>
inline MyDockerIterator<T>::MyDockerIterator(MyBaseDocker<T> *_docker, int _cur) : m_Docker(_docker), m_cur(_cur)
{
}

template<typename T>
inline void MyDockerIterator<T>::next()
{
	++m_cur;
}

template<typename T>
inline T MyDockerIterator<T>::operator*()
{
	return m_Docker->at(m_cur);
}

template<typename T>
inline bool MyDockerIterator<T>::operator!=(const MyDockerIterator<T> _other)
{
	return m_cur != _other.m_cur;
}

template<typename T>
inline MyDockerIterator<T>& MyDockerIterator<T>::operator++()
{
	++m_cur;
	return *this;
}

template<typename T>
inline bool MyDockerIterator<T>::isDone()
{
	return m_cur >= m_Docker->GetMaxSize();
}
