#include <iostream>

int main(int argc, char **argv)
{
    (argv)++;
    while (*argv)
    {
        while (**argv)
        {
            std::cout << (char)toupper(**argv);
            (*argv)++;
        }
        (argv)++;
    }
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
}