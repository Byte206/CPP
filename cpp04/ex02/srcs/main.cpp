#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

#define ARRAY_SIZE 10

void printCat() {
    std::cout << std::endl;
    std::cout << "         _._     _,-'\"\"\"`-._" << std::endl;
    std::cout << "        (,-.`._,'(       |\\`-/|" << std::endl;
    std::cout << "            `-.-' \\ )-`( , o o)" << std::endl;
    std::cout << "                  `-    \\`_`\"'-" << std::endl;
    std::cout << std::endl;
}

void printDog() {
    std::cout << std::endl;
    std::cout << "                             ," << std::endl;
    std::cout << "                |`-.__" << std::endl;
    std::cout << "                / ' _/" << std::endl;
    std::cout << "               ****`" << std::endl;
    std::cout << "              /    }" << std::endl;
    std::cout << "             /  \\ /" << std::endl;
    std::cout << "         \\ /`   \\\\\\" << std::endl;
    std::cout << "          `\\    /_\\\\" << std::endl;
    std::cout << "           `~~~~~``~`" << std::endl;
    std::cout << std::endl;
}

int main() {

    // =========================================================
    //                  ARRAY DE ANIMALES
    // =========================================================

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "       CREATING ARRAY OF ANIMALS" << std::endl;
    std::cout << "========================================" << std::endl;

    Animal* animals[ARRAY_SIZE];

    std::cout << std::endl;
    std::cout << "--- Creating Dogs (0 to 4) ---" << std::endl;
    for (int i = 0; i < ARRAY_SIZE / 2; i++) {
        animals[i] = new Dog();
    }

    std::cout << std::endl;
    std::cout << "--- Creating Cats (5 to 9) ---" << std::endl;
    for (int i = ARRAY_SIZE / 2; i < ARRAY_SIZE; i++) {
        animals[i] = new Cat();
    }


    // =========================================================
    //                  DEEP COPY TESTS - CAT
    // =========================================================

    printCat();
    std::cout << "========================================" << std::endl;
    std::cout << "         DEEP COPY TEST - CAT" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    std::cout << "--- Creating original Cat ---" << std::endl;
    Cat* originalCat = new Cat();
    originalCat->getBrain()->setIdea(0, "I want to sleep all day!");
    originalCat->getBrain()->setIdea(1, "Humans are my servants!");

    std::cout << std::endl;
    std::cout << "Original Cat ideas:" << std::endl;
    std::cout << "  idea[0]: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "  idea[1]: " << originalCat->getBrain()->getIdea(1) << std::endl;

    std::cout << std::endl;
    std::cout << "--- Creating copied Cat (copy constructor) ---" << std::endl;
    Cat* copiedCat = new Cat(*originalCat);

    std::cout << std::endl;
    std::cout << "Copied Cat ideas (should be same as original):" << std::endl;
    std::cout << "  idea[0]: " << copiedCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "  idea[1]: " << copiedCat->getBrain()->getIdea(1) << std::endl;

    std::cout << std::endl;
    std::cout << "--- Modifying copied Cat's idea[0] ---" << std::endl;
    copiedCat->getBrain()->setIdea(0, "I want to knock things off tables!");

    std::cout << std::endl;
    std::cout << "After modification (original should NOT change):" << std::endl;
    std::cout << "  Original Cat idea[0]: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "  Copied Cat idea[0]:   " << copiedCat->getBrain()->getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "--- Testing operator= ---" << std::endl;
    Cat assignedCat;
    assignedCat = *originalCat;
    assignedCat.getBrain()->setIdea(0, "Meow meow meow!");

    std::cout << std::endl;
    std::cout << "After operator= and modification:" << std::endl;
    std::cout << "  Original Cat idea[0]: " << originalCat->getBrain()->getIdea(0) << std::endl;
    std::cout << "  Assigned Cat idea[0]: " << assignedCat.getBrain()->getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "--- Deleting Cats ---" << std::endl;
    delete originalCat;
    delete copiedCat;


    // =========================================================
    //                  DEEP COPY TESTS - DOG
    // =========================================================

    printDog();
    std::cout << "========================================" << std::endl;
    std::cout << "         DEEP COPY TEST - DOG" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    std::cout << "--- Creating original Dog ---" << std::endl;
    Dog* originalDog = new Dog();
    originalDog->getBrain()->setIdea(0, "I want to play fetch!");
    originalDog->getBrain()->setIdea(1, "I love my owner!");

    std::cout << std::endl;
    std::cout << "Original Dog ideas:" << std::endl;
    std::cout << "  idea[0]: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "  idea[1]: " << originalDog->getBrain()->getIdea(1) << std::endl;

    std::cout << std::endl;
    std::cout << "--- Creating copied Dog (copy constructor) ---" << std::endl;
    Dog* copiedDog = new Dog(*originalDog);

    std::cout << std::endl;
    std::cout << "Copied Dog ideas (should be same as original):" << std::endl;
    std::cout << "  idea[0]: " << copiedDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "  idea[1]: " << copiedDog->getBrain()->getIdea(1) << std::endl;

    std::cout << std::endl;
    std::cout << "--- Modifying copied Dog's idea[0] ---" << std::endl;
    copiedDog->getBrain()->setIdea(0, "I want to chase squirrels!");

    std::cout << std::endl;
    std::cout << "After modification (original should NOT change):" << std::endl;
    std::cout << "  Original Dog idea[0]: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "  Copied Dog idea[0]:   " << copiedDog->getBrain()->getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "--- Testing operator= ---" << std::endl;
    Dog assignedDog;
    assignedDog = *originalDog;
    assignedDog.getBrain()->setIdea(0, "Woof woof woof!");

    std::cout << std::endl;
    std::cout << "After operator= and modification:" << std::endl;
    std::cout << "  Original Dog idea[0]: " << originalDog->getBrain()->getIdea(0) << std::endl;
    std::cout << "  Assigned Dog idea[0]: " << assignedDog.getBrain()->getIdea(0) << std::endl;

    std::cout << std::endl;
    std::cout << "--- Deleting Dogs ---" << std::endl;
    delete originalDog;
    delete copiedDog;


    // =========================================================
    //                  DELETING ARRAY OF ANIMALS
    // =========================================================

    std::cout << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << "    DELETING ARRAY AS Animal*" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << "--- Deleting animal[" << i << "] ---" << std::endl;
        delete animals[i];
        std::cout << std::endl;
    }

    std::cout << "========================================" << std::endl;
    std::cout << "           END OF TESTS!" << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    return 0;
}
