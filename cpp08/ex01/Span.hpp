#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>
# include <algorithm>

class Span
{
public:
	Span(unsigned int n);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span();

	void			addNumber(int n);

	// Add a range of numbers via iterators
	template <typename Iterator>
	void			addRange(Iterator first, Iterator last)
	{
		while (first != last)
		{
			addNumber(*first);
			++first;
		}
	}

	int				shortestSpan() const;
	int				longestSpan() const;

	class FullException : public std::exception {
		public: const char *what() const throw() { return "Span is full"; }
	};
	class NoSpanException : public std::exception {
		public: const char *what() const throw() { return "Not enough numbers to find a span"; }
	};

private:
	unsigned int		_max;
	std::vector<int>	_numbers;
};

#endif
