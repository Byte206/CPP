#include "Span.hpp"

template <typename Iterator>
void Span::addRange(Iterator first, Iterator last)
{
	while (first != last)
	{
		addNumber(*first);
		++first;
	}
}

template void Span::addRange<std::vector<int>::iterator>(std::vector<int>::iterator first, std::vector<int>::iterator last);
template void Span::addRange<std::vector<int>::const_iterator>(std::vector<int>::const_iterator first, std::vector<int>::const_iterator last);

Span::Span(unsigned int n) : _max(n) {}

Span::Span(const Span &other) : _max(other._max), _numbers(other._numbers) {}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_max = other._max;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_numbers.size() >= _max)
		throw FullException();
	_numbers.push_back(n);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	int shortest = sorted[1] - sorted[0];
	for (size_t i = 2; i < sorted.size(); ++i)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanException();

	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return max - min;
}
