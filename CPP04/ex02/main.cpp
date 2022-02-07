#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	//Animal animal;
	Cat cat;
	Dog dog;

	//animal.makeSound();
	cat.makeSound();
	dog.makeSound();

	Animal animal;
	animal.makeSound();
}