#pragma once

template<typename T>
class BaseIterator
{
public:
	virtual ~BaseIterator() = default;
	BaseIterator() = default;

	virtual void next() = 0;
	virtual bool isDone() = 0;

private:

};

