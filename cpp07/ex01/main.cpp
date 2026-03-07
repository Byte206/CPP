#include "iter.hpp"

int main(void)
{
    //int array
    int intArray[] = {1, 2, 3, 4, 5};
    std::cout << "Int array: ";
    iter(intArray, 5, print<int>);
    std::cout << std::endl;
    iter(intArray, 5, increment<int>);
    std::cout << "After increment: "; 
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    //string array
    std::string strArray[] = {"Hello", "World", "!"};
    std::cout << "String array: ";
    iter(strArray, 3, print<std::string>);
    std::cout << std::endl;

    //double array
    double doubleArray[] = {1.1, 2.2, 3.3};
    std::cout << "Double array: ";
    iter(doubleArray, 3, print<double>);
    std::cout << std::endl;

    return 0;
}
