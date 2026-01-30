#include "includes/AMateria.hpp"
#include "includes/Character.hpp"
#include "includes/Ice.hpp"
#include "includes/Cure.hpp"
#include "includes/MateriaSource.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Subject Test ===" << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << "=== Additional Tests ===" << std::endl;

	
	std::cout << std::endl << "--- Deep Copy Test ---" << std::endl;
	Character* original = new Character("original");
	MateriaSource* src2 = new MateriaSource();
	src2->learnMateria(new Ice());
	src2->learnMateria(new Cure());
	
	original->equip(src2->createMateria("ice"));
	original->equip(src2->createMateria("cure"));
	
	Character* copy = new Character(*original);
	
	ICharacter* target = new Character("target");
	std::cout << "Original uses materias:" << std::endl;
	original->use(0, *target);
	original->use(1, *target);
	std::cout << "Copy uses materias:" << std::endl;
	copy->use(0, *target);
	copy->use(1, *target);

	delete target;
	delete copy;
	delete original;
	delete src2;

	
	std::cout << std::endl << "--- Unequip Test ---" << std::endl;
	Character* player = new Character("player");
	MateriaSource* src3 = new MateriaSource();
	src3->learnMateria(new Ice());
	
	AMateria* ice = src3->createMateria("ice");
	player->equip(ice);
	
	ICharacter* enemy = new Character("enemy");
	player->use(0, *enemy);
	player->unequip(0);
	player->use(0, *enemy);  // Should do nothing
	
	delete enemy;
	delete player;
	delete src3;

	// Test full inventory
	std::cout << std::endl << "--- Full Inventory Test ---" << std::endl;
	Character* fullChar = new Character("fullChar");
	MateriaSource* src4 = new MateriaSource();
	src4->learnMateria(new Ice());
	src4->learnMateria(new Cure());
	
	fullChar->equip(src4->createMateria("ice"));
	fullChar->equip(src4->createMateria("cure"));
	fullChar->equip(src4->createMateria("ice"));
	fullChar->equip(src4->createMateria("cure"));
	
	// does nothing because inventory is full
	AMateria* extra = src4->createMateria("ice");
	fullChar->equip(extra);
	
	ICharacter* testTarget = new Character("testTarget");
	for (int i = 0; i < 4; i++)
		fullChar->use(i, *testTarget);
	
	delete extra;  // Need to delete manually since it is not equipped
	delete testTarget;
	delete fullChar;
	delete src4;

	// test unknown materia type
	std::cout << std::endl << "--- Unknown Materia Test ---" << std::endl;
	MateriaSource* src5 = new MateriaSource();
	src5->learnMateria(new Ice());
	AMateria* unknown = src5->createMateria("fire");  // return null
	if (unknown == 0)
		std::cout << "Unknown materia type correctly returns NULL" << std::endl;
	delete src5;

	std::cout << std::endl << "=== All Tests Complete ===" << std::endl;
	return 0;
}
