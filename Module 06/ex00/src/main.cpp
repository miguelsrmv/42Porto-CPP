#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2 || !argv[1][0])
    {
        std::cout << "Error: incorrect usage: ./convert [argument_to_convert]" << std::endl ;
        return (1);
    }

    std::string parameter(argv[1]);

    ScalarConverter::convert(parameter);
}
