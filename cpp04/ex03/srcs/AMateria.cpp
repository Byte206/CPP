#include "../includes/AMateria.hpp"
#include "../includes/Character.hpp"
#include <iostream>

AMateria::AMateria() : _type("default")
{
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria parameterized constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &other) : _type(other._type)
{
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const &other)
{
	std::cout << "AMateria assignment operator called" << std::endl;
	if (this != &other)
	{
		// Note: type is not copied as per subject requirement
		// "While assigning a Materia to another, copying the type doesn't make sense."
	}
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout << "AMateria use called" << std::endl;
}
