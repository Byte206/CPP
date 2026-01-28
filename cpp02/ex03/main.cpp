#include <iostream>
#include <string>
#include "Fixed.hpp"
#include "Point.hpp"

int main() {
    // Definimos los vértices de un triángulo
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(5.0f, 10.0f);

    // Casos de prueba
    Point p1(5.0f, 5.0f);   // Claramente dentro
    Point p2(15.0f, 15.0f); // Claramente fuera
    Point p3(0.0f, 0.0f);   // En un vértice (debería ser false según el enunciado)
    Point p4(5.0f, 0.0f);   // En una arista (debería ser false según el enunciado)

    std::cout << "--- BSP Test ---" << std::endl;
    
    std::cout << "P1 (5, 5)   - Inside:  " << (bsp(a, b, c, p1) ? "YES" : "NO") << std::endl;
    std::cout << "P2 (15, 15) - Inside:  " << (bsp(a, b, c, p2) ? "YES" : "NO") << std::endl;
    std::cout << "P3 (0, 0)   - Inside:  " << (bsp(a, b, c, p3) ? "YES" : "NO") << " (Vertex)" << std::endl;
    std::cout << "P4 (5, 0)   - Inside:  " << (bsp(a, b, c, p4) ? "YES" : "NO") << " (Edge)" << std::endl;

    return 0;
}