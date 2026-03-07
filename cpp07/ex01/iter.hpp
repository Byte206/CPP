#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T, typename N, typename F>
void iter(T *array, const N length, F func)
{
    for (N i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T>
void print(T &element)
{
    std::cout << element << " ";
}

template <typename T>
void increment(T &element)
{
    element++;
}

#endif