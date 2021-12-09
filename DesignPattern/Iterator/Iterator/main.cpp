#include <iostream>
#include <algorithm>
#include "MyBaseDocker.h"
#include "MyDockerIterator.h"
#include "MyList.h"

using namespace std;

template<typename Iteartor, typename T>
Iteartor my_find_if(Iteartor _begin, Iteartor _end, T _val)
{
	for (auto _it = _begin; _it != _end; ++_it)
	{
		if ((*_it) == _val)
		{
			return _it;
		}
	}
}

int main() {
	MyBaseDocker<int> doc(10);
	doc.AddItem(1);
	doc.AddItem(2);
	doc.AddItem(3);
	for (int val : doc) {
		std::cout << val << std::endl;
	}

	for (auto _begin = doc.rbegin(); _begin != doc.rend(); ++_begin) {
		std::cout << *_begin << std::endl;
	}

	std::cout << "find " << *my_find_if(doc.begin(), doc.end(), 3) << std::endl;

	std::cout << "--------------------------" << std::endl;

	MyList<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);

	std::cout << "find " << *my_find_if(mylist.begin(), mylist.end(), 3) << std::endl;

	for (auto val : mylist) {
		std::cout << val << std::endl;
	}
	for (auto _begin = mylist.rbegin(); _begin != mylist.rend(); ++_begin) {
		std::cout << *_begin << std::endl;
	}
	while (mylist.Size() > 0) {
		std::cout << mylist.pop_back() << std::endl;
	}
	return 0;
}