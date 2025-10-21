#include <iostream>
#include <string_view>

enum class Animal
{
	pig,
	chicken,
	goat,
	cat,
	dog,
	duck,
};
constexpr std::string_view getAnimalName(Animal animal)
{
	switch (animal)
	{
	case Animal::pig:
		return "pig";
	case Animal::chicken:
		return "chicken";
	case Animal::goat:
		return "goat";
	case Animal::cat:
		return "cat";
	case Animal::dog:
		return "dog";
	case Animal::duck:
		return "duck";
	default:
		return "unknown";
	}
}
constexpr void printNumberOfLegs(Animal animal)
{
	switch (animal)
	{
	case Animal::pig:
	case Animal::goat:
		std::cout << "A " << getAnimalName(animal) << " has 4 legs.\n";
		break;
	case Animal::chicken:
	case Animal::duck:
		std::cout << "A " << getAnimalName(animal) << " has 2 legs.\n";
		break;
	case Animal::cat:
	case Animal::dog:
		std::cout << "A " << getAnimalName(animal) << " has 4 legs and a tail.\n";
		break;
	default:
		std::cout << "Unknown animal!\n";
		break;
	}
}

int main()
{
	printNumberOfLegs(Animal::pig);
	printNumberOfLegs(Animal::chicken);
	printNumberOfLegs(Animal::goat);
	printNumberOfLegs(Animal::cat);
	printNumberOfLegs(Animal::dog);
	printNumberOfLegs(Animal::duck);
	return 0;
}