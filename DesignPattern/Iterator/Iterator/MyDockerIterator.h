#pragma once
#include "BaseIterator.h"
#include "MyBaseDocker.h"
template<typename T>
class MyDockerIterator : public BaseIterator<T>
{
public:
	MyDockerIterator(MyBaseDocker<T> *_docker, int _cur, bool reverse = false);

	virtual void next() override;
	virtual void behind() override;
	T operator *();
	bool operator != (const MyDockerIterator<T> _other);
	MyDockerIterator<T>& operator ++ ();

	virtual bool isDone();

	void SetVal(const T& _val) override;

private:
	int m_startIndex;
	int m_cur{ 0 };
	MyBaseDocker<T>* m_Docker{ nullptr };
};

template<typename T>
inline MyDockerIterator<T>::MyDockerIterator(MyBaseDocker<T> *_docker, int _cur, bool reverse) : m_Docker(_docker), m_cur(_cur), m_startIndex(_cur), BaseIterator<T>(reverse)
{
}

template<typename T>
inline void MyDockerIterator<T>::next()
{
	++m_cur;
}

template<typename T>
inline void MyDockerIterator<T>::behind()
{
	--m_cur;
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
inline bool MyDockerIterator<T>::isDone()
{
	if (BaseIterator<T>::ISReverse())
	{
		return m_cur == -1;
	}
	else {
		return m_cur >= m_Docker->GetMaxSize();
	}	
}

template<typename T>
inline void MyDockerIterator<T>::SetVal(const T& _val)
{
	m_Docker->SetVal(m_cur, _val);
}
