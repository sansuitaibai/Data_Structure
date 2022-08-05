#include<iostream>
#include<string>
#include"HeadDoubleCircleList.h"
using namespace std;

int main() {

	HeadDoubleCircleList<int> dc1;
	dc1.push_back(5);
	dc1.push_back(4);
	dc1.push_back(3);
	dc1.push_back(2);
	dc1.push_back(1);
	dc1.push_front(6);
	dc1.printHeadDoubleCircleList();
	std::cout << "DoubleCircleList of size is: " << dc1.size() << std::endl;

	dc1.insert(0, 7);
	dc1.insert(dc1.size(), 0);
	dc1.insert(4, 99);
	dc1.printHeadDoubleCircleList();
	std::cout << "DoubleCircleList of size is: " << dc1.size() << std::endl;

	std::cout << "dc1.pop_back():  " << dc1.pop_back() << "   dc1.pop_front():  " << dc1.pop_front() << std::endl;
	dc1.remove(0);
	dc1.remove(dc1.size() - 1);

	dc1.printHeadDoubleCircleList();
	std::cout << "DoubleCircleList of size is: " << dc1.size() << std::endl;
	return 0;
}