#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <exception>

template <typename T> class Array
{
  private:
	T *_array;
	size_t _size;

  public:
	// default constructor: creates an empty array
	Array() : _array(NULL), _size(0)
	{
	}

	// constructor with unsigned int n: creates an array of n elements initialized by default
	Array(unsigned int n) : _array(new T[n]()), _size(n)
	{
	}

	// copy constructor
	Array(const Array &other) : _array(NULL), _size(0)
	{
		*this = other;
	}

	// assignment operator
	Array &operator=(const Array &other)
	{
		if (this != &other)
		{
			delete[] _array;
			_size = other._size;
			if (_size > 0)
			{
				_array = new T[_size];
				for (size_t i = 0; i < _size; i++)
				{
					_array[i] = other._array[i];
				}
			}
			else
			{
				_array = NULL;
			}
		}
		return (*this);
	}

	// destructor
	~Array()
	{
		delete[] _array;
	}

	// subscript operator for access
	T &operator[](size_t index)
	{
		if (index >= _size)
		{
			throw std::exception();
		}
		return (_array[index]);
	}

	// const subscript operator for access
	const T &operator[](size_t index) const
	{
		if (index >= _size)
		{
			throw std::exception();
		}
		return (_array[index]);
	}

	// member function size() that returns the number of elements
	size_t size() const
	{
		return (_size);
	}
};

#endif