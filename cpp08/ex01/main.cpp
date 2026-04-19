#include <iostream>
#include <vector>
#include <cstdlib>
#include "Span.hpp"

int main()
{
	// subject test
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "-- Subject test --" << std::endl;
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest:  " << sp.longestSpan()  << std::endl;
	}

	// exceptions
	{
		std::cout << "\n-- Exceptions --" << std::endl;
		Span sp(1);
		sp.addNumber(42);
		try { sp.addNumber(99); }
		catch (const std::exception &e) { std::cout << "Full:    " << e.what() << std::endl; }
		try { sp.shortestSpan(); }
		catch (const std::exception &e) { std::cout << "NoSpan:  " << e.what() << std::endl; }
	}

	// addRange + large test
	{
		std::cout << "\n-- Large test (10,000 numbers) with addRange --" << std::endl;
		srand(42);
		std::vector<int> big(10000);
		for (int i = 0; i < 10000; ++i)
			big[i] = rand();

		Span sp(10000);
		sp.addRange(big.begin(), big.end());
		std::cout << "Shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest:  " << sp.longestSpan()  << std::endl;
	}

	return 0;
}
