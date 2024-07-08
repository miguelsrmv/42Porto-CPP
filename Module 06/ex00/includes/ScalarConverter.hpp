#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>

class ScalarConverter
{
    public:
        static void convert(std::string& parameter);

    private:
        // Private Constructors becuase class must not be instanciable by users
        ScalarConverter();
        ScalarConverter(const ScalarConverter& copy);
        const ScalarConverter& operator=(const ScalarConverter& copy);
        ~ScalarConverter();
        
        static void print_char(const std::string& parameter);
        static void print_int(const std::string& parameter);
        static void print_float(const std::string& parameter);
        static void print_double(const std::string& parameter);
};

#endif
