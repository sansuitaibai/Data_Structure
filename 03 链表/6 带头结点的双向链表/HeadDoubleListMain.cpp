#include<iostream>
#include<string>
#include"HeadDoubleList.h"
using namespace std;

int main() {
	std::cout << "HeadDoubleList 开始测试： " << std::endl;
	HeadDoubleList<int> d1;
	d1.push_back(5);
	d1.push_back(4);
	d1.push_back(3);
	d1.push_back(2);
	d1.push_back(1);
	d1.printHeadDoubleList();
	std::cout << "长度：" << d1.size() << std::endl;

	d1.push_front(6);
	d1.insert(0, 7);
	d1.insert(d1.size(), 0);
	d1.insert( 4, 100);
	d1.printHeadDoubleList();
	std::cout << "长度：" << d1.size() << std::endl;

	d1.remove(0);
	d1.remove(d1.size() - 1);
	d1.remove(3);
	d1.printHeadDoubleList();
	std::cout << "长度：" << d1.size() << std::endl;

	return 0;
}