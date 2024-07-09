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
    DOUBLE_TYPE,
    PSEUDO_LITERAL_TYPE,
    INVALID_TYPE
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
        static types get_type(const std::string& parameter);
        static bool is_char(const std::string& parameter);
        static bool is_int(const std::string& parameter);
        static bool is_float(const std::string& parameter);
        static bool is_double(const std::string& parameter);
        static bool is_pseudo_literal(const std::string& parameter);

        // Converts type
        static std::string convert_invalid_input(const std::string& parameter);
        static std::string convert_char(const std::string& parameter);
        static std::string convert_int(const std::string& parameter);
        static std::string convert_float(const std::string& parameter);
        static std::string convert_double(const std::string& parameter);
        static std::string convert_pseudo_literal(const std::string& parameter);

        // Prints data 
        static void print_data(const std::string *parameter_list);
};

#endif
