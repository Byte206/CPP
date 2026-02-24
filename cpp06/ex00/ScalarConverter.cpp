#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <cerrno>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&) {}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter&)
{
    return *this;
}

bool isPseudoLiteral(const std::string& literal)
{
    return (literal == "nan" || literal == "nanf" || 
            literal == "inf" || literal == "inff" || 
            literal == "+inf" || literal == "+inff" ||
            literal == "-inf" || literal == "-inff");
}

bool isValidNumber(const std::string& literal)
{
    if (literal.empty())
        return false;
    
    if (isPseudoLiteral(literal))
        return true;
    
    size_t i = 0;
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    
    bool hasDigit = false;
    bool hasDot = false;
    
    while (i < literal.length() && literal[i] != 'f')
    {
        if (std::isdigit(literal[i]))
            hasDigit = true;
        else if (literal[i] == '.')
        {
            if (hasDot)
                return false;
            hasDot = true;
        }
        else
            return false;
        i++;
    }
    
    if (i < literal.length() && literal[i] == 'f')
        i++;
    
    return hasDigit && i == literal.length();
}

int getType(const std::string& literal)
{
    if (isPseudoLiteral(literal))
    {
        if (literal == "nanf" || literal == "inff" || literal == "+inff" || literal == "-inff")
            return 3;
        else
            return 4;
    }
    
    if (literal.length() == 1 && !std::isdigit(literal[0]))
        return 1;
    else if (literal.find('.') == std::string::npos && literal.find('f') == std::string::npos)
        return 2;
    else if (literal.find('f') != std::string::npos)
        return 3;
    else
        return 4;
}

void convertChar(const std::string& literal)
{
    char c = literal[0];
    
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void convertNumber(const std::string& literal)
{
    char* end;
    errno = 0;
    long l = std::strtol(literal.c_str(), &end, 10);
    
    if (errno == ERANGE || *end != '\0')
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    
    if (l < std::numeric_limits<int>::min() || l > std::numeric_limits<int>::max())
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << static_cast<float>(l) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(l) << std::endl;
        return;
    }
    
    int i = static_cast<int>(l);
    
    if (i < 0 || i > 127 || !std::isprint(static_cast<char>(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void convertFloat(const std::string& literal)
{
    char* end;
    errno = 0;
    float f = std::strtof(literal.c_str(), &end);
    
    if (errno == ERANGE && !std::isinf(f))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    
    if (std::isnan(f) || std::isinf(f))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int intVal = static_cast<int>(f);
        if (f < 0 || f > 127 || f != intVal || !std::isprint(static_cast<char>(intVal)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        
        if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
    }
    
    std::cout << "float: " << f;
    if (!std::isnan(f) && !std::isinf(f) && f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    
    std::cout << "double: " << static_cast<double>(f);
    if (!std::isnan(f) && !std::isinf(f) && f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << std::endl;
}

void convertDouble(const std::string& literal)
{
    char* end;
    errno = 0;
    double d = std::strtod(literal.c_str(), &end);
    
    if (errno == ERANGE && !std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    
    if (std::isnan(d) || std::isinf(d))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int intVal = static_cast<int>(d);
        if (d < 0 || d > 127 || d != intVal || !std::isprint(static_cast<char>(intVal)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        
        if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(d) << std::endl;
    }
    
    std::cout << "float: " << static_cast<float>(d);
    if (!std::isnan(d) && !std::isinf(d) && d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << "f" << std::endl;
    
    std::cout << "double: " << d;
    if (!std::isnan(d) && !std::isinf(d) && d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& literal)
{
    if (literal.empty())
    {
        std::cout << "Error: empty literal" << std::endl;
        return;
    }
    
    int type = getType(literal);
    
    if (type != 1 && !isValidNumber(literal))
    {
        std::cout << "Error: invalid literal" << std::endl;
        return;
    }
    
    try
    {
        switch (type)
        {        
            case 1:
                convertChar(literal);
                break;
            case 2:
                convertNumber(literal);
                break;
            case 3:
                convertFloat(literal);
                break;
            case 4:
                convertDouble(literal);
                break;
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: conversion failed - " << e.what() << std::endl;
    }
}