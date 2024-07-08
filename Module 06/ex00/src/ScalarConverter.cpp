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

bool
ScalarConverter::is_char(const std::string& parameter)
{
    // Checks for a string of length 1, with a printable non-digit character
    return (parameter.size() == 1 && std::isprint(parameter[0]) && !std::isdigit(parameter[0]));
}

bool
ScalarConverter::is_int(const std::string& parameter)
{
    // Step #1: Allows for signed numbers
    int i = 0;
    if (parameter[i] == '+' || parameter[i] == '-')
        i++;


    // Step #2: Checks if it's all digits
    while (parameter[i])
    {
        if (!std::isdigit(parameter[i++]))
            return (false);
    }


    // Step #3: Checks for overflows
    /// Step #3.1 Longest possible length of INT is 11 (-2147483648)
    if (i > 11)
        return (false);

    /// Step #3.2 INT_MAX and INT_MIN check
    long number_placeholder;
    std::istringstream number_stream(parameter);
    number_stream >> number_placeholder;
    if (number_stream.fail() || number_placeholder > std::numeric_limits<int>::max()
        || number_placeholder < std::numeric_limits<int>::min())
        return (false);

    return (true);
}

bool
ScalarConverter::is_float(const std::string& parameter)
{
    // Step #0 Check pseudo literals, immediately end check if true
    if (parameter == "-inff" || parameter == "+inff" || parameter == "nanf")
        return (true);

    // Step #1: Allows for signed numbers
    int i = 0;
    if (parameter[i] == '+' || parameter[i] == '-')
        i++;

    // Step #2: Checks if it finds a float in the correct format
    /// Step #2.1 Unit part
    while (parameter[i])
    {
        if (!std::isdigit(parameter[i++]))
            break ;
    }
    /// Step #2.2 The dot
    if (parameter[i] == '.')
        i++;
    /// Step #2.3 Decimal part
    while (parameter[i])
    {
        if (!std::isdigit(parameter[i++]))
            break ;
    }
    /// Step #2.4 float indicator
    if (parameter[i] == 'f')
        i++;
    /// Step #2.5 Check for having gone through the entire length
    if ((static_cast<long unsigned int>(i)) != parameter.length())
        return (false);

        ////////////////////////////////// IT'S WRONG FROM HERE ON!!!! //////////////////////////
    // Step #3: Checks for overflows
    /// Step #3.1 Longest possible length of FLOAT is '+/-' + unit digits + '.' + decimal digist + 'f'
    if (i > 1 + std::numeric_limits<float>::digits10 + 1 + std::numeric_limits<float>::digits10 + 1)
        return (false);

    /// Step #3.2 FLOAT_MAX and FLOAT_MIN check
    float number_placeholder;
    std::istringstream number_stream(parameter);
    number_stream >> number_placeholder;
    if (number_stream.fail() || number_placeholder > std::numeric_limits<float>::max()
        || number_placeholder < std::numeric_limits<float>::min())
        return (false);

    return (true);
}

bool
ScalarConverter::is_double(const std::string& parameter)
{
    (void)parameter;
    return (false);
}

types
ScalarConverter::get_type(const std::string& parameter)
{
    if (is_char(parameter))
        return CHAR_TYPE;
    else if (is_int(parameter))
        return INT_TYPE;
    else if (is_float(parameter))
        return FLOAT_TYPE;
    else if (is_double(parameter))
        return DOUBLE_TYPE;
    else
    {
        std::cout << "ERROR ON GET_TYPE!!!" << std::endl;
        return CHAR_TYPE;
    }
}

void 
ScalarConverter::convert(std::string& parameter)
{
    std::cout << "You typed in: " << parameter << std::endl ;

    // 1st, get what the input was
    switch(get_type(parameter))
    {
        // Depending on the input type, convert
        case CHAR_TYPE:
            std::cout << "Got a char!" << std::endl;
            break ;
        case INT_TYPE:
            std::cout << "Got a int!" << std::endl;
            break ;
        case FLOAT_TYPE:
            std::cout << "Got a float!" << std::endl;
            break ;
        case DOUBLE_TYPE:
            std::cout << "Got a double!" << std::endl;
            break ;
        default:
            std::cout << "ERROR: IMPOSSIBLE CONVERSION!!" << std::endl ;
            // If not a char, int, float or double or special case: exception ?
    }
}

void
ScalarConverter::print_char(const std::string& parameter)
{
    std::string result;

    if (!std::isprint(parameter[0]))
        result = "impossible";
    else
       // result = static_cast<int>(parameter[0]);
       return ;

    std::cout << "char: '" << parameter << "'" << std::endl;
}

void
ScalarConverter::print_int(const std::string& parameter)
{
    std::cout << "int: " << parameter << std::endl;
}

void
ScalarConverter::print_float(const std::string& parameter)
{
    std::cout << "float: " << parameter << std::endl;    
}

void
ScalarConverter::print_double(const std::string& parameter)
{
    std::cout << "double: " << parameter << std::endl;    
}
