#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	int size = 50;
	const Animal* meta[size];
	int i;

	i = 0;
	while (i < size)
	{
		if (i % 2 == 0)
			meta[i] = new Dog();
		else
			meta[i] = new Cat();
		i++;
	}
	i = 0;
	while (i < size)
	{
		meta[i]->makeSound();
		i++;
	}
	i = 0;
	while (i < size)
	{
		delete (meta[i]);
		i++;
	}

	std::cout << "-----------------------" << std::endl;

	Dog dog1;
	dog1.getbrain()->setidea(0, "manger");
	std::cout << dog1.getbrain()->getidea(0) << std::endl; //manger
	Dog dog2(dog1);
	std::cout << dog1.getbrain()->getidea(0) << std::endl; //toujours manger
	std::cout << dog2.getbrain()->getidea(0) << std::endl; //copie de manger
	dog2.getbrain()->setidea(0, "dormir");
	std::cout << dog1.getbrain()->getidea(0) << std::endl; //toujours manger
	std::cout << dog2.getbrain()->getidea(0) << std::endl; //dormir
	return 0;
}