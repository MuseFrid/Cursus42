/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 09:59:22 by gduchesn          #+#    #+#             */
/*   Updated: 2024/01/29 17:50:02 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER
# define SCALARCONVERTER
# include <iostream>
# include <iomanip>
# include <cctype>
# include <sstream>

enum type {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    LITERAL
};

class ScalarConverter {
    private:
        ScalarConverter(void);
        ScalarConverter(ScalarConverter const & ScalarConverter);
        ScalarConverter & operator=(ScalarConverter const & rhs);
        virtual ~ScalarConverter(void);

        static int         setType(std::string str);
        static void        castToFinal(std::string str, int type);

        static void        printchar(char c, int i, int type);
        static void        printint(int i, std::string str);
        static void        printfloat(float f, std::string str);
        static void        printdouble(double d, std::string str);
        
        static bool    ischar(std::string str);
        static bool    isint(std::string str);
        static bool    isfloat(std::string str);
        static bool    isdouble(std::string str);
        static bool    isliterals(std::string str);
        
        class UnknownType : public std::exception {
            public:
                virtual const char* what(void) const throw();
        };
        class ConvertionFailed : public std::exception {
            public:
                virtual const char* what(void) const throw();
        };

    public:
        static void convert(std::string toConvert);
};

#endif