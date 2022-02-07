#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (0);
	}
	//int intconv;
	//float floatconv;
	//char charconv;
	double doubleconv;

	doubleconv = static_cast<double>(argv[1][0]);
	doubleconv = static_cast<double>(doubleconv);
	std::cout << doubleconv << std::endl;
}