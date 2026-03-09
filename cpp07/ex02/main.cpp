#include <iostream>
#include "Array.hpp"

int main() {
    // empty array
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;
    
    // array with size
    Array<int> numbers(5);
    std::cout << "Numbers array size: " << numbers.size() << std::endl;
    
    // initialize and display
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
    }
    
    std::cout << "Numbers: ";
    for (unsigned int i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    
    // copy constructor
    Array<int> copy(numbers);
    copy[0] = 999;
    std::cout << "Original[0]: " << numbers[0] << std::endl;
    std::cout << "Copy[0]: " << copy[0] << std::endl;
    
    // test exception
    try {
        std::cout << numbers[10] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception: out of bounds" << std::endl;
    }
    
    return 0;
}
