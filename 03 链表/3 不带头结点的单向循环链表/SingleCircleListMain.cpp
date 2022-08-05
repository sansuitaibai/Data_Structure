#include<iostream>
#include<string>
#include"SingleCircleList.h"
using namespace std;


int main() {

	SingleCircleList<int> s1;

	s1.push_back(5);
	s1.push_back(4);
	s1.push_back(3);
	s1.push_back(2);
	s1.push_back(1);

	s1.printSingList();
	std::cout << s1.size() << std::endl;

	s1.push_front(6);
	s1.printSingList();
	std::cout << s1.size() << std::endl;

	s1.insert(0, 7);
	s1.insert(1, 99);
	s1.insert(5, 88);
	s1.insert(s1.size(), 77);
	s1.printSingList();
	std::cout << s1.size() << std::endl;

	std::cout << "删除第一个元素：" << s1.pop_front() << std::endl;
	std::cout << "删除最后一个元素：" << s1.pop_back() << std::endl;
	s1.printSingList();
	std::cout << s1.size() << std::endl;

	std::cout << "删除第一个元素：" << s1.remove(0) << std::endl;
	std::cout << "删除最后一个元素：" << s1.remove(s1.size() - 1) << std::endl;
	std::cout << "删除index = 5 元素：" << s1.remove(5) << std::endl;
	s1.printSingList();
	std::cout << s1.size() << std::endl;

	std::cout << s1.get(0) << std::endl;
	std::cout << s1.get(3) << std::endl;
	std::cout << s1.get(s1.size() - 1) << std::endl;

	s1.set(0, 100);
	s1.set(s1.size() - 1, 99);
	s1.set(2, 88);
	s1.printSingList();
	std::cout << s1.size() << std::endl;
	return 0;
}