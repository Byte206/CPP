#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;
	data.id = 42;
	data.name = "Test Data";
	data.value = 3.14159;

	std::cout << "=== Original Data ===" << std::endl;
	std::cout << "Address: " << &data << std::endl;
	std::cout << "id: " << data.id << std::endl;
	std::cout << "name: " << data.name << std::endl;
	std::cout << "value: " << data.value << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "\n=== Serialized ===" << std::endl;
	std::cout << "Raw value: " << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "\n=== Deserialized ===" << std::endl;
	std::cout << "Address: " << ptr << std::endl;
	std::cout << "id: " << ptr->id << std::endl;
	std::cout << "name: " << ptr->name << std::endl;
	std::cout << "value: " << ptr->value << std::endl;

	std::cout << "\n=== Comparison ===" << std::endl;
	if (ptr == &data)
		std::cout << "SUCCESS: Pointers are equal!" << std::endl;
	else
		std::cout << "FAILURE: Pointers are NOT equal!" << std::endl;

	return 0;
}
