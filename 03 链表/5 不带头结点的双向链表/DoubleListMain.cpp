#include<iostream>
#include<string>
#include"DoubleList.h"
using namespace std;

int main() {

	DoubleList<int> d1;
	d1.push_back(5);
	d1.push_back(4);
	d1.push_back(3);
	d1.push_back(2);
	d1.push_back(1);
	d1.printDoubleList();
	std::cout << "长度：" << d1.size() << std::endl;

	d1.push_front(6);
	d1.printDoubleList();
	std::cout << "长度：" << d1.size() << std::endl;

	d1.remove(0);
	d1.remove(d1.size() - 1);
	d1.remove(3);
	d1.printDoubleList();
	std::cout << "长度：" << d1.size() << std::endl;

	return 0;
}