#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

template <typename T>
void testFind(T &container, int value, const std::string &containerName)
{
	std::cout << "[" << containerName << "] Searching for " << value << ": ";
	try
	{
		typename T::iterator it = easyfind(container, value);
		std::cout << "Found " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	// -test with vector
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(3);
	vec.push_back(9);
	vec.push_back(7);

	testFind(vec, 3,   "vector");  // found
	testFind(vec, 9,   "vector");  // found
	testFind(vec, 42,  "vector");  // not found

	// test with list
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	testFind(lst, 20,  "list");    // found
	testFind(lst, 99,  "list");    // not found

	return 0;
}
