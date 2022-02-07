#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Wrong number of arguments, expected 1" << std::endl;
		return (0);
	}
	double	d = std::atof(argv[1]);
	char	c = static_cast<char>(d);

	std::cout << "char: ";
	if (std::isnan(d) || std::isinf(d))
		std::cout << "impossible conversion" << std::endl;
	else if (d >= 256)
		std::cout << "overflowed char" << std::endl;
	else if (!(std::isprint(c)) || d <= 9)
		std::cout << "non displayable char" << std::endl;
	else
		std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		
	std::cout << "int: ";
	if (std::isnan(d) || std::isinf(d))
		std::cout << "impossible conversion" << std::endl;
	else if (d > INT_MAX || d < INT_MIN)
		std::cout << "overflowed int" << std::endl;
	else
		std::cout << static_cast<int>(d) << std::endl;

	float f = d;

	std::cout << "float: " << static_cast<float>(d);
	if (std::isnan(f) || std::isinf(f) || roundf(f) != f)
		std::cout << "f" << std::endl;
	else
		std::cout << ".0f" << std::endl;

	std::cout << "double: " << static_cast<double>(d) << std::endl;
}