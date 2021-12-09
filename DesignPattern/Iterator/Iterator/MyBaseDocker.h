#pragma once
#include <assert.h>

template<typename Item>
class MyDockerIterator;

template<typename T>
class MyBaseDocker
{
public:
	MyBaseDocker(size_t size);
	virtual ~MyBaseDocker();
	MyDockerIterator<T> begin();
	MyDockerIterator<T> end();
	
	int GetCurrentSize();
	int GetMaxSize();

	void AddItem(T _val);
	void Clear();
	T at(int _index);

private:
	T* m_Items{ nullptr };
	int m_MaxSize{ 0 };
	int m_CurrentSize{ 0 };

};

template<typename T>
inline MyBaseDocker<T>::MyBaseDocker(size_t size) : m_MaxSize(size)
{
	m_Items = new T[m_MaxSize];
}

template<typename T>
inline MyBaseDocker<T>::~MyBaseDocker()
{
	delete m_Items;
}

template<typename T>
inline MyDockerIterator<T> MyBaseDocker<T>::begin()
{
	return MyDockerIterator<T>(this, 0);
}

template<typename T>
inline MyDockerIterator<T> MyBaseDocker<T>::end()
{
	return MyDockerIterator<T>(this, m_CurrentSize);
}

template<typename T>
inline int MyBaseDocker<T>::GetCurrentSize()
{
	return m_CurrentSize;
}

template<typename T>
inline int MyBaseDocker<T>::GetMaxSize()
{
	return m_MaxSize;
}

template<typename T>
inline void MyBaseDocker<T>::AddItem(T _val)
{
	if (m_CurrentSize < m_MaxSize)
	{
		m_Items[m_CurrentSize] = _val;
		++m_CurrentSize;
	}
	else {
		assert(0);
	}
}

template<typename T>
inline void MyBaseDocker<T>::Clear()
{
	m_CurrentSize = 0;
}

template<typename T>
inline T MyBaseDocker<T>::at(int _index)
{
	if (_index >= m_CurrentSize)
	{
		assert(0);
		return NULL;
	}
	return m_Items[_index];
}
