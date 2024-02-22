/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:02:37 by gduchesn          #+#    #+#             */
/*   Updated: 2024/01/31 11:23:08 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}


ScalarConverter::ScalarConverter(ScalarConverter const & ScalarConverter) {
    (void) ScalarConverter;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & rhs) {
    (void) rhs;
    return (*this);
}

void    ScalarConverter::convert(std::string toConvert) {
    int type = ScalarConverter::setType(toConvert);
    ScalarConverter::castToFinal(toConvert, type);
}

bool    ScalarConverter::ischar(std::string str) {
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return true;
    return false;
}

bool    ScalarConverter::isint(std::string str) {
    int i = 0;
    if (str[0] == '-' || str[0] == '+')
        ++i;
    for (int j(i); j < (int)str.length(); ++j)
        if (!std::isdigit(str[j]))
            return false;
    return true;
}

bool    ScalarConverter::isfloat(std::string str) {
    if (str.find(".") == std::string::npos || ((int)str.find("f") != -1 && str.find("f") != str.length() - 1) || str.find("f") == std::string::npos){
        return (false);
    }
    int i = 0;
    bool dot = false;
    if (str[0] == '-' || str[0] == '+')
        ++i;
    for (int j(i); j < (int)str.length(); ++j && ++i) {
        if ((!std::isdigit(str[j]) && str[j] != '.') || (str[j] == '.' && dot)) {
            if (j == (int)str.length() - 1 && str[j] == 'f')
                continue;
            return false;
        }
        if (str[j] == '.')
            dot = true;
    }
    return true;
}

bool    ScalarConverter::isdouble(std::string str) {
    if (str.find(".") == std::string::npos)
        return (false);
    int i = 0;
    bool dot = false;
    if (str[0] == '-' || str[0] == '+')
        ++i;
    for (int j(i); j < (int)str.length(); ++j && ++i) {
        if ((!std::isdigit(str[j]) && str[j] != '.') || (str[j] == '.' && dot)) {
            return false;
        }
        if (str[j] == '.')
            dot = true;
    }
    return true;
}

bool ScalarConverter::isliterals(std::string str) {
    if (str.compare("-inff") == 0 || str.compare("+inff") == 0
    || str.compare("-inf") == 0 || str.compare("+inf") == 0
    || str.compare("nan") == 0 || str.compare("nanf") == 0)
        return true;
    return false;
}

void    ScalarConverter::castToFinal(std::string str, int type) {
    char    c;
    int     i;
    float   f;
    double  d;
    
    if (type == FLOAT && str.find("f") != std::string::npos)
        str.erase(str.find("f"));
    std::istringstream iss(str);
    switch (type) {
        case CHAR:
            c = str[0];
            i = static_cast<int>(c);
            f = static_cast<float>(c);
            d = static_cast<double>(c);
            break;
        case INT:
            if (!(iss >> i))
                throw ConvertionFailed();
            c = static_cast<char>(i);
            f = static_cast<float>(i);
            d = static_cast<double>(i);
            break;
        case FLOAT:
            if (!(iss >> f))
                throw ConvertionFailed();
            c = static_cast<char>(f);
            i = static_cast<int>(f);
            d = static_cast<double>(f);
            break;
        case DOUBLE:
            if (!(iss >> d))
                throw ConvertionFailed();
            c = static_cast<char>(d);
            i = static_cast<int>(d);
            f = static_cast<float>(d);
            break;
    }
    printchar(c, i, type);
    printint(i, str);
    printfloat(f, str);
    printdouble(d, str);
}

//      ***************       print fonction        ***************

void    ScalarConverter::printchar(char c, int i, int type) {
    std::cout << "char: ";
    if ((!isprint(c) && c >= 127) || type == LITERAL || i > 127)
        std::cout << "Impossible" << std::endl;
    else if (!isprint(c))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << c << "'" << std::endl;
}

void    ScalarConverter::printint(int i, std::string str) {
    std::cout << "int: ";
    if (isliterals(str))
        std::cout << "Impossible";
    else
        std::cout << i;
    std::cout << std::endl;
}

void    ScalarConverter::printfloat(float f, std::string str) {
    std::cout << "float: ";
    if (str.compare("-inf") == 0 || str.compare("-inff") == 0)
        std::cout << "-inff";
    else if (str.compare("+inf") == 0 || str.compare("+inff") == 0)
        std::cout << "+inff";
    else if (str.compare("nan") == 0 || str.compare("nanf") == 0)
        std::cout << "nanf";
    else {
        if (f - static_cast<int>(f) == 0) {
            std::cout << f << ".0f";
        }
        else
            std::cout << f << "f";
    }
    std::cout << std::endl;
}

void    ScalarConverter::printdouble(double d, std::string str) {
    std::cout << "double: ";
    if (str.compare("-inf") == 0 || str.compare("-inff") == 0)
        std::cout << "-inf";
    else if (str.compare("+inf") == 0 || str.compare("+inff") == 0)
        std::cout << "+inf";
    else if (str.compare("nan") == 0 || str.compare("nanf") == 0)
        std::cout << "nan";
    else {
        if (d - static_cast<int>(d) == 0) {
            std::cout << d << ".0";
        }
        else
            std::cout << d;
    }
    std::cout << std::endl;
}

//      ***************       setter & getter        ***************

int    ScalarConverter::setType(std::string str) {
    int type;

    if (ScalarConverter::ischar(str))
        type = CHAR;
    else if (ScalarConverter::isint(str))
        type = INT;
    else if (ScalarConverter::isfloat(str))
        type = FLOAT;
    else if (ScalarConverter::isdouble(str))
        type = DOUBLE;
    else if (ScalarConverter::isliterals(str))
        type = LITERAL;
    else
        throw UnknownType();
    return (type);
}

//      ***************       exceptions       ***************

const char* ScalarConverter::UnknownType::what(void) const throw() {
    return ("UnknownType");
}

const char* ScalarConverter::ConvertionFailed::what(void) const throw() {
    return ("Convertion failed");
}
