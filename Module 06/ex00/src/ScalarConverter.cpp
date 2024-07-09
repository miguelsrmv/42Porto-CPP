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
    {
        std::cout << "ERROR ON GET_TYPE!!!" << std::endl;
        return INVALID_TYPE;
    }
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
    if (!std::isdigit(parameter[0]))
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

    // Step #3: Checks for overflows
    long double number_buffer;
    std::istringstream number_stream(parameter);
    number_stream >> number_buffer;
    if (number_stream.fail() || number_buffer > std::numeric_limits<int>::max() || number_buffer < std::numeric_limits<int>::min())
        return (false);

    return (true);
}

bool ScalarConverter::is_float(const std::string &parameter)
{
    // Step #0 Check pseudo literals (immediately end check if true)
    if (parameter == "-inff" || parameter == "+inff" || parameter == "nanf")
        return (true);

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

    /// Step #3 Check overflows
    long double number_buffer;
    std::istringstream number_stream(parameter);
    number_stream >> number_buffer;
    if (number_stream.fail() || number_buffer > std::numeric_limits<float>::max() || number_buffer < -std::numeric_limits<float>::max())
        return (false);

    return (true);
}

bool ScalarConverter::is_double(const std::string &parameter)
{
    // Step #0 Check pseudo literals (immediately end check if true)
    if (parameter == "-inf" || parameter == "+inf" || parameter == "nan")
        return (true);

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

    /// Step #3 Check overflows
    long double number_buffer;
    std::istringstream number_stream(parameter);
    number_stream >> number_buffer;
    if (number_stream.fail() || number_buffer > std::numeric_limits<double>::max() || number_buffer < -std::numeric_limits<double>::max())
        return (false);

    return (true);
}

bool ScalarConverter::is_pseudo_literal(const std::string &parameter)
{
    /// Checks for the valid pseudo literals
    return (parameter == "-inff" || parameter == "+inff" || parameter == "nanf" || parameter == "-inf" || parameter == "+inf" || parameter == "nan");
}

void ScalarConverter::convert(std::string &parameter)
{
    std::cout << "You typed in: " << parameter << std::endl;

    types input_type = get_type(parameter);

    (void)input_type;

}

std::string ScalarConverter::convert_invalid_input(const std::string& parameter)
{
    return parameter;
}

std::string ScalarConverter::convert_char(const std::string& parameter)
{
    return parameter;
}

std::string ScalarConverter::convert_int(const std::string& parameter)
{
    return parameter;
}

std::string ScalarConverter::convert_float(const std::string& parameter)
{
    return parameter;
}

std::string ScalarConverter::convert_double(const std::string& parameter)
{
    return parameter;
}

std::string ScalarConverter::convert_pseudo_literal(const std::string& parameter)
{
    return parameter;
}

void ScalarConverter::print_data(const std::string *parameter_list)
{
    std::cout << "char: " << parameter_list[CHAR_TYPE] << "" << std::endl;
    std::cout << "int: " << parameter_list[INT_TYPE]<< std::endl;
    std::cout << "float: " << parameter_list[FLOAT_TYPE] << std::endl;
    std::cout << "double: " << parameter_list[DOUBLE_TYPE] << std::endl;
}
