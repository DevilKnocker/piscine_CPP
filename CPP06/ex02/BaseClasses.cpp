#include "BaseClasses.hpp"

Base::~Base(){

}

Base * generate(void){

	Base* base;
	srand (time(NULL));
	int i = rand() % 3;
	if (i == 0)
	{
		base = new A;
		std::cout << "Class type A created" << std::endl;
	}
	else if (i == 1)
	{
		base = new B;
		std::cout << "Class type B created" << std::endl;
	}
	else
	{
		base = new C;
		std::cout << "Class type C created" << std::endl;
	}
	return (base);
}

void identify(Base* p){

	if (dynamic_cast<A*>(p))
		std::cout << "Je pense que c'est la classe A !" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Je pense que c'est la classe B !" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Je pense que c'est la classe C !" << std::endl;
	else
		std::cout << "Je ne connais pas cette classe :'(" << std::endl;

}

void identify(Base& p){

	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Je pense que c'est la classe A !" << std::endl;
		return ;
	}
	catch(std::bad_cast &bc)
	{
		std::cout << "Est-ce que votre classe contient une consonne ?" << std::endl;
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Je pense que c'est la classe B !" << std::endl;
		return ;
	}
	catch(std::bad_cast &bc)
	{
		std::cout << "Le nom de la classe est-il present dans le mot \"Cervelle\" ?" << std::endl;
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Je pense que c'est la classe C !" << std::endl;
		return ;
	}
	catch(std::bad_cast &bc)
	{
		std::cout << "Je ne connais pas cette classe :'(" << std::endl;
	}
}