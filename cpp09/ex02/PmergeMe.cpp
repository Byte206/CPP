#include "Pmerge.hpp"

#include <ctime>
#include <sstream>

namespace
{
template <typename Container>
std::string containerToStringImpl(const Container& c)
{
	std::ostringstream oss;
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
	{
		if (it != c.begin())
			oss << ' ';
		oss << *it;
	}
	return oss.str();
}

void mergeSortVector(std::vector<int>& container, int start, int mid, int end)
{
	int leftSize = mid - start + 1;
	int rightSize = end - mid;
	std::vector<int> left(leftSize);
	std::vector<int> right(rightSize);

	for (int i = 0; i < leftSize; ++i)
		left[i] = container[start + i];
	for (int j = 0; j < rightSize; ++j)
		right[j] = container[mid + 1 + j];

	int i = 0;
	int j = 0;
	int k = start;
	while (i < leftSize && j < rightSize)
	{
		if (left[i] <= right[j])
			container[k++] = left[i++];
		else
			container[k++] = right[j++];
	}
	while (i < leftSize)
		container[k++] = left[i++];
	while (j < rightSize)
		container[k++] = right[j++];
}

void insertSortVector(std::vector<int>& container, int start, int end)
{
	for (int index = start + 1; index <= end; ++index)
	{
		int value = container[index];
		int j = index - 1;
		while (j >= start && container[j] > value)
		{
			container[j + 1] = container[j];
			--j;
		}
		container[j + 1] = value;
	}
}

void mergeInsertSortVector(std::vector<int>& container, int start, int end)
{
	if (start >= end)
		return;
	if ((end - start) < 10)
	{
		insertSortVector(container, start, end);
		return;
	}
	int mid = start + (end - start) / 2;
	mergeInsertSortVector(container, start, mid);
	mergeInsertSortVector(container, mid + 1, end);
	mergeSortVector(container, start, mid, end);
}

void mergeSortDeque(std::deque<int>& container, int start, int mid, int end)
{
	int leftSize = mid - start + 1;
	int rightSize = end - mid;
	std::deque<int> left(leftSize);
	std::deque<int> right(rightSize);

	for (int i = 0; i < leftSize; ++i)
		left[i] = container[start + i];
	for (int j = 0; j < rightSize; ++j)
		right[j] = container[mid + 1 + j];

	int i = 0;
	int j = 0;
	int k = start;
	while (i < leftSize && j < rightSize)
	{
		if (left[i] <= right[j])
			container[k++] = left[i++];
		else
			container[k++] = right[j++];
	}
	while (i < leftSize)
		container[k++] = left[i++];
	while (j < rightSize)
		container[k++] = right[j++];
}

void insertSortDeque(std::deque<int>& container, int start, int end)
{
	for (int index = start + 1; index <= end; ++index)
	{
		int value = container[index];
		int j = index - 1;
		while (j >= start && container[j] > value)
		{
			container[j + 1] = container[j];
			--j;
		}
		container[j + 1] = value;
	}
}

void mergeInsertSortDeque(std::deque<int>& container, int start, int end)
{
	if (start >= end)
		return;
	if ((end - start) < 10)
	{
		insertSortDeque(container, start, end);
		return;
	}
	int mid = start + (end - start) / 2;
	mergeInsertSortDeque(container, start, mid);
	mergeInsertSortDeque(container, mid + 1, end);
	mergeSortDeque(container, start, mid, end);
}

} // namespace

Pmerge::Pmerge(const std::vector<int>& vec, const std::deque<int>& deq)
	: _vec(vec), _deq(deq)
{
}

std::string Pmerge::containerToString(const std::vector<int>& c)
{
	return containerToStringImpl(c);
}

std::string Pmerge::containerToString(const std::deque<int>& c)
{
	return containerToStringImpl(c);
}

void Pmerge::sort()
{
	std::cout << "Before: " << containerToString(_vec) << std::endl;

	std::vector<int> vecCopy = _vec;
	std::deque<int> deqCopy = _deq;

	std::clock_t vecStart = std::clock();
	if (!vecCopy.empty())
		mergeInsertSortVector(vecCopy, 0, static_cast<int>(vecCopy.size()) - 1);
	std::clock_t vecEnd = std::clock();
	double vecTime = static_cast<double>(vecEnd - vecStart) / (CLOCKS_PER_SEC / 1000000.0);

	std::clock_t deqStart = std::clock();
	if (!deqCopy.empty())
		mergeInsertSortDeque(deqCopy, 0, static_cast<int>(deqCopy.size()) - 1);
	std::clock_t deqEnd = std::clock();
	double deqTime = static_cast<double>(deqEnd - deqStart) / (CLOCKS_PER_SEC / 1000000.0);

	std::cout << "After:  " << containerToString(vecCopy) << std::endl;
	std::cout << "Time to process a range of " << vecCopy.size()
			<< " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << deqCopy.size()
			<< " elements with std::deque : " << deqTime << " us" << std::endl;
}
