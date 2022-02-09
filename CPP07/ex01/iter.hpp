#include <string>
#include <iostream>

template<typename T>
void iter(T* const tab , unsigned int const size , void (*fct)(T const &)){

	unsigned int i;

	i = 0;
	while (i < size)
	{
		fct(tab[i]);
		i++;
	}
}