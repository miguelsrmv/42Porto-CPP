#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) 
{
    (void)copy;
}

const ScalarConverter&
ScalarConverter::operator=(const ScalarConverter& copy)
{
    (void)copy;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

void 
ScalarConverter::convert(std::string& parameter)
{
    std::cout << "You typed in: " << parameter << std::endl ;

    print_char(parameter);
    print_int(parameter);
    print_float(parameter);
    print_double(parameter);
    return ;
}

void
ScalarConverter::print_char(const std::string& parameter)
{
    std::cout << "char: ";
    
    std::cout << parameter << std::endl;
}

void
ScalarConverter::print_int(const std::string& parameter)
{
    std::cout << "int: ";

    std::cout << parameter << std::endl;
}

void
ScalarConverter::print_float(const std::string& parameter)
{
    std::cout << "float: ";

    std::cout << parameter << std::endl;    
}

void
ScalarConverter::print_double(const std::string& parameter)
{
    std::cout << "double: ";

    std::cout << parameter << std::endl;    
}
