#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    (void)copy;
}

const ScalarConverter &
ScalarConverter::operator=(const ScalarConverter &copy)
{
    (void)copy;
    return (*this);
}

ScalarConverter::~ScalarConverter() {}

types ScalarConverter::get_type(const std::string &parameter)
{
    if (is_char(parameter))
        return CHAR_TYPE;
    else if (is_int(parameter))
        return INT_TYPE;
    else if (is_float(parameter))
        return FLOAT_TYPE;
    else if (is_double(parameter))
        return DOUBLE_TYPE;
    else if (is_pseudo_literal(parameter))
        return PSEUDO_LITERAL_TYPE;
    else
        return INVALID_TYPE;
}

bool ScalarConverter::is_char(const std::string &parameter)
{
    // Step #1: Checks for a string of length 1
    if (parameter.size() != 1)
        return (false);

    // #Step #2: Checks if character is printable
    if (!std::isprint(parameter[0]))
        return (false);

    // Step #3: Check if character is a digit
    if (std::isdigit(parameter[0]))
        return (false);

    return (true);
}

bool ScalarConverter::is_int(const std::string &parameter)
{
    // Step #1: Allows for signed numbers
    size_t i = 0;
    if (parameter[i] == '+' || parameter[i] == '-')
        i++;

    // Step #2: Checks if it's all digits
    while (parameter[i])
    {
        if (!std::isdigit(parameter[i++]))
            return (false);
    }

    return (true);
}

bool ScalarConverter::is_float(const std::string &parameter)
{
    // Step #1: Allows for signed numbers
    size_t i = 0;
    if (parameter[i] == '+' || parameter[i] == '-')
        i++;

    // Step #2: Checks if it finds a float in the correct format
    /// Step #2.1 Find dot and f in the end
    size_t dot_index = parameter.find('.');
    size_t f_index = parameter.find('f');
    if (dot_index == std::string::npos || f_index == std::string::npos || f_index != parameter.length() - 1)
        return (false);

    /// Step #2.2 Find decimal and floating parts
    std::string integral_part = parameter.substr(i, dot_index - i);
    std::string fractional_part = parameter.substr(dot_index + 1, f_index - dot_index - 1);
    if (integral_part.empty() || fractional_part.empty())
        return (false);

    /// Step #2.3 Check that borth decimal and floating parts are made of digits
    for (size_t index = 0; index < integral_part.length(); index++)
    {
        if (!std::isdigit(integral_part[index]))
            return (false);
    }

    for (size_t index = 0; index < fractional_part.length(); index++)
    {
        if (!std::isdigit(fractional_part[index]))
            return (false);
    }

    return (true);
}

bool ScalarConverter::is_double(const std::string &parameter)
{
    // Step #1: Allows for signed numbers
    size_t i = 0;
    if (parameter[i] == '+' || parameter[i] == '-')
        i++;

    // Step #2: Checks if it finds a float in the correct format
    /// Step #2.1 Find dot and f in the end
    size_t dot_index = parameter.find('.');
    if (dot_index == std::string::npos)
        return (false);

    /// Step #2.2 Find decimal and floating parts
    std::string integral_part = parameter.substr(i, dot_index - i);
    std::string fractional_part = parameter.substr(dot_index + 1, parameter.length() - dot_index - 1);
    if (integral_part.empty() || fractional_part.empty())
        return (false);

    /// Step #2.3 Check that borth decimal and floating parts are made of digits
    for (size_t index = 0; index < integral_part.length(); index++)
    {
        if (!std::isdigit(integral_part[index]))
            return (false);
    }

    for (size_t index = 0; index < fractional_part.length(); index++)
    {
        if (!std::isdigit(fractional_part[index]))
            return (false);
    }

    return (true);
}

bool ScalarConverter::is_pseudo_literal(const std::string &parameter)
{
    /// Checks for the valid pseudo literals
    return (parameter == "-inff" || parameter == "+inff" || parameter == "nanf" || parameter == "-inf" || parameter == "+inf" || parameter == "nan");
}

void ScalarConverter::convert(std::string &parameter)
{
    switch (get_type(parameter))
    {
    case CHAR_TYPE:
        return convert_data(parameter, parameter[0]);
    case INT_TYPE:
        return convert_data(parameter, std::atoi(parameter.c_str()));
    case FLOAT_TYPE:
        return convert_data(parameter, std::strtof(parameter.c_str(), NULL));
    case DOUBLE_TYPE:
        return convert_data(parameter, std::strtod(parameter.c_str(), NULL));
    case PSEUDO_LITERAL_TYPE:
        return print_pseudoliterals(parameter);
    case INVALID_TYPE:
        return print_invalid_input(parameter);
    }
}

void ScalarConverter::convert_data(const std::string &parameter, long double number)
{
    convert_char(static_cast<char>(number), parameter);
    convert_int(static_cast<int>(number), parameter);
    convert_float(static_cast<float>(number), parameter);
    convert_double(static_cast<double>(number), parameter);
}

bool ScalarConverter::overflow_check(const char *parameter, types parameter_type)
{
    long double number = std::strtold(parameter, NULL);

    switch (parameter_type)
    {
    case CHAR_TYPE:
        return (number < std::numeric_limits<char>::min() || number > std::numeric_limits<char>::max());
    case INT_TYPE:
        return (number < std::numeric_limits<int>::min() || number > std::numeric_limits<int>::max());
    case FLOAT_TYPE:
        return (number < -std::numeric_limits<float>::max() || number > std::numeric_limits<float>::max());
    case DOUBLE_TYPE:
        return (number < -std::numeric_limits<double>::max() || number > std::numeric_limits<double>::max());
    default:
        return false;
    }
}

void ScalarConverter::convert_char(char c, const std::string &parameter)
{
    std::cout << "char: ";

    if (overflow_check(parameter.c_str(), CHAR_TYPE))
        std::cout << "impossible" << std::endl;
    else if (!isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
}

void ScalarConverter::convert_int(int integer, const std::string &parameter)
{
    std::cout << "int: ";

    if (overflow_check(parameter.c_str(), INT_TYPE))
        std::cout << "impossible" << std::endl;
    else
        std::cout << integer << std::endl;
}

void ScalarConverter::convert_float(float floating_point, const std::string &parameter)
{
    std::cout << "float: ";

    std::string appendix;
    if (floating_point == static_cast<int>(floating_point))
        appendix = ".0f";
    else
        appendix = "f";

    if (overflow_check(parameter.c_str(), FLOAT_TYPE))
        std::cout << "impossible" << std::endl;
    else
        std::cout << floating_point << appendix << std::endl;
}

void ScalarConverter::convert_double(double doubling_point, const std::string &parameter)
{
    std::cout << "double: ";

    std::string appendix;
    if (doubling_point == static_cast<int>(doubling_point))
        appendix = ".0";
    else
        appendix = "";

    if (overflow_check(parameter.c_str(), DOUBLE_TYPE))
        std::cout << "impossible" << std::endl;
    else
        std::cout << doubling_point << appendix << std::endl;
}

void ScalarConverter::print_pseudoliterals(const std::string &parameter)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;

    if (parameter.find("nan") != std::string::npos)
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else
    {
        std::cout << "float: " << parameter[0] << "nanf" << std::endl;
        std::cout << "double: " << parameter[0] << "nan" << std::endl;
    }
}

void ScalarConverter::print_invalid_input(const std::string &parameter)
{
    std::cout << "Invalid input: " << parameter << std::endl;
}
