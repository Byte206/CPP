#include <iostream>
#include <typeinfo>

template <typename T>
void swap(T &a, T &b)
{    T temp = a;
    a = b;
    b = temp;
}
template <typename T>
T min(T a, T b){
    if(typeid(a) != typeid(b))
        {
            std::cout << "Error: Types do not match." << std::endl;
            return T();
        }
    return (a < b) ? a : b;
}

template <typename T>
T max(T a, T b){
    if(typeid(a) != typeid(b))
        {
            std::cout << "Error: Types do not match." << std::endl;
            return T();
        }
    return (a > b) ? a : b;
}