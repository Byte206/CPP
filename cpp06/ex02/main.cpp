#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

int main()
{
	std::cout << "=== Testing with known types ===" << std::endl;
	
	Base* a = new A();
	Base* b = new B();
	Base* c = new C();

	std::cout << "Pointer A: ";
	identify(a);
	std::cout << "Reference A: ";
	identify(*a);

	std::cout << "Pointer B: ";
	identify(b);
	std::cout << "Reference B: ";
	identify(*b);

	std::cout << "Pointer C: ";
	identify(c);
	std::cout << "Reference C: ";
	identify(*c);

	delete a;
	delete b;
	delete c;

	std::cout << "\n=== Testing with random generation ===" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		Base* random = generate();
		std::cout << "Random " << i + 1 << " - Pointer: ";
		identify(random);
		std::cout << "Random " << i + 1 << " - Reference: ";
		identify(*random);
		delete random;
	}

	return 0;
}
