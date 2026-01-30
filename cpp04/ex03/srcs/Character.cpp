#include "../includes/Character.hpp"
#include <iostream>


//default constructor
Character::Character() : _name("default"), _floorCount(0)
{
	std::cout << "Character default constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_floor[i] = NULL;
}

//parameterized constructor
Character::Character(std::string const &name) : _name(name), _floorCount(0)
{
	std::cout << "Character parameterized constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
	for (int i = 0; i < 100; i++)
		_floor[i] = NULL;
}


//copy constructor
Character::Character(Character const &other) : _name(other._name), _floorCount(0)
{
	std::cout << "Character copy constructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	for (int i = 0; i < 100; i++)
		_floor[i] = NULL;
}

//assignment operator
Character &Character::operator=(Character const &other)
{
	std::cout << "Character assignment operator called" << std::endl;
	if (this != &other)
	{
		_name = other._name;
		// Delete current inventory
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
			{
				delete _inventory[i];
				_inventory[i] = NULL;
			}
		}
		// Deep copy new inventory
		for (int i = 0; i < 4; i++)
		{
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	return *this;
}


//destructor
Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
	// Clean up floor (unequipped materias)
	for (int i = 0; i < _floorCount; i++)
	{
		if (_floor[i])
			delete _floor[i];
	}
}

std::string const &Character::getName() const
{
	return _name;
}


//equip method
void Character::equip(AMateria *m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
		{
			_inventory[i] = m;
			return;
		}
	}
	// Inventory full, do nothing
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || _inventory[idx] == NULL)
		return;
	// Store on floor to avoid memory leak
	if (_floorCount < 100)
	{
		//look for next available spot
		_floor[_floorCount] = _inventory[idx];
		_floorCount++;
	}
	//remove from inventory
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4 || _inventory[idx] == NULL)
		return;
	//polymorphic call to use
	_inventory[idx]->use(target);
}
