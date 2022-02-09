#include "iter.hpp"

template<typename T>
void chat(T const & str){
	std::cout << str << std::endl;
}

int main( void ) {

	std::string tab[] = {"bonjour", "aurevoir"};

	iter(tab, 2, chat);
}