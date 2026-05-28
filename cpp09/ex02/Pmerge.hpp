#ifndef PMERGE_HPP
#define PMERGE_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>

class Pmerge {
public:
	Pmerge(const std::vector<int>& vec, const std::deque<int>& deq);
	void sort();

private:
	std::vector<int> _vec;
	std::deque<int> _deq;

	static std::string containerToString(const std::vector<int>& c);
	static std::string containerToString(const std::deque<int>& c);
};

#endif // PMERGE_HPP
