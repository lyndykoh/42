/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 20:52:15 by lkoh              #+#    #+#             */
/*   Updated: 2025/09/15 13:21:22 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
    
}

ScalarConverter::ScalarConverter(ScalarConverter const &other) {
    (void) other;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter &other) {
    (void) other;
    return (*this);
}

ScalarConverter::~ScalarConverter() {
    
}

static bool isChar(const std::string &string) {
    return (string.length() == 1 && !std::isdigit(string[0]));
}

static bool isInt(const std::string &string) {
    int i = 0;
    if (string[i] == '-' || string[i] == '+')
        i++;
    while (string[i]) {
        if (!std::isdigit(string[i]))
            return (false);
        i++;
    }
    return (true);
}

static bool isFloat(const std::string &string) {
    int i = 0;
    int len = string.length();
    bool dec = false;
    
    if (string.back() != 'f' && string.back() != 'F')
        return (false);
    if (string[i] == '-' || string[i] == '+')
        i++;
    while (i < len - 1) {
        if (string[i] == '.') {
            if (dec)
                return false;
            dec = true;
        }
        else if (!std::isdigit(string[i]))
            return (false);
        
        i++;
    }
    return (dec);
}

static bool isDouble(const std::string &string) {
    int i = 0;
    bool dec = false;
    
    if (string[i] == '-' || string[i] == '+')
        i++;
    while (string[i]) {
        if (string[i] == '.') {
            if (dec)
                return false;
            dec = true;
        }
        else if (!std::isdigit(string[i]))
            return (false);
        
        i++;
    }
    return (dec);
}

static bool isSpecialFloat(const std::string &string) {
    return (string == "nanf" || string == "-inff" || string == "+inff");
}

static bool isSpecialDouble(const std::string &string) {
    return (string == "nan" || string == "-inf" || string == "+inf");
}

void ScalarConverter::convert(const std::string &string) {
    char    c;
    int     i;
    float   f;
    double  d;

    std::cout << std::fixed << std::setprecision(1);

    if (isChar(string))
    {
        c = string[0];
        i = static_cast<int>(string[0]);
        f = static_cast<float>(string[0]);
        d = static_cast<double>(string[0]);
        std::cout << "is Char" << std::endl;
    }
    else if (isInt(string))
    {
        long l = std::strtol(string.c_str(), NULL, 10);
        if (l > INT_MAX || l < INT_MIN || errno == ERANGE)
        {
            std::cerr << "Error: invalid / out of range" << std::endl;
            return;
        }
        c = static_cast<char>(l);
        i = static_cast<int>(l);
        f = static_cast<float>(l);
        d = static_cast<double>(l);
        std::cout << "is Int" << std::endl;
    }
    else if (isFloat(string))
    {
        errno = 0;
        char* end;
        std::string core = string.substr(0, string.length() - 1);
        f = std::strtof(core.c_str(), &end);
        if (errno == ERANGE || *end != '\0')
        {
            std::cerr << "Error: invalid / out of range" << std::endl;
            return;
        }
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
        std::cout << "is Float" << std::endl;
    }
    else if (isDouble(string))
    {
        errno = 0;
        char* end;
        d = std::strtod(string.c_str(), &end);
        if (errno == ERANGE || *end != '\0')
        {
            std::cerr << "Error: invalid / out of range" << std::endl;
            return;
        }
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
        std::cout << "is Double" << std::endl;
    }
    else if (isSpecialFloat(string))
    {
        c = 0;
        i = 0;
        f = std::strtof(string.c_str(), NULL);
        d = static_cast<double>(f);
    }
    else if (isSpecialDouble(string))
    {
        c = 0;
        i = 0;
        d = std::strtod(string.c_str(), NULL);
        f = static_cast<float>(d);
    }
    else 
    {
        std::cerr << "idk what u did.." << std::endl;
        return;
    }
    

    std::cout << "Char:    ";
    if (isSpecialDouble(string) || isSpecialFloat(string))
        std::cout << "Impossible" << std::endl;
    else if (std::isprint(c))
        std::cout << c << std::endl;
    else 
        std::cout << "Non displayable" << std::endl;
        
    std::cout << "Int:     ";
    if (isSpecialDouble(string) || isSpecialFloat(string))
        std::cout << "Impossible" << std::endl;
    else
        std::cout << i << std::endl;
    std::cout << "Float:   " << f << "f" << std::endl;
    std::cout << "Double:  " << d << std::endl;
}
