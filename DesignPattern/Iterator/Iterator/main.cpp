#include <iostream>
#include <algorithm>
#include "MyBaseDocker.h"
#include "MyDockerIterator.h"
#include "MyList.h"

using namespace std;



int main() {
	MyBaseDocker<int> doc(10);
	doc.AddItem(1);
	doc.AddItem(2);
	doc.AddItem(3);
	for (int val : doc) {
		std::cout << val << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	MyList<int> mylist;
	mylist.push_back(1);
	mylist.push_back(2);
	mylist.push_back(3);
	mylist.push_back(4);

	for (auto val : mylist) {
		std::cout << val << std::endl;
	}

	while (mylist.Size() > 0) {
		std::cout << mylist.pop_back() << std::endl;
	}
	return 0;
}