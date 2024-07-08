#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <iostream>
#include <cctype>
#include <limits>
#include <sstream>

typedef enum types {
    CHAR_TYPE,
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE
} types;

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
        
        // Gets type that was inputed
        static bool is_char(const std::string& parameter);
        static bool is_int(const std::string& parameter);
        static bool is_float(const std::string& parameter);
        static bool is_double(const std::string& parameter);
        static types get_type(const std::string& parameter);

        // Converts type 
        static void print_char(const std::string& parameter);
        static void print_int(const std::string& parameter);
        static void print_float(const std::string& parameter);
        static void print_double(const std::string& parameter);
};

#endif
