#include <iostream>
#include <string>

struct Data {
	int nbr;
};

uintptr_t serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data data;
	uintptr_t ptr;

	data.nbr = 42;
	ptr = serialize(&data);
	data = *deserialize(ptr);
	std::cout << data.nbr << std::endl;
}