/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:02:44 by gduchesn          #+#    #+#             */
/*   Updated: 2024/01/29 15:26:58 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Error: prog need one parameter" << std::endl;
        return (1);
    }
    try {
        ScalarConverter::convert(argv[1]);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}