/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:45:37 by gduchesn          #+#    #+#             */
/*   Updated: 2024/02/21 15:40:43 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void) {
    std::cout << "array int" << std::endl;
    int tab[] = {4, 43, 5, 12, 18, 24, 32};
    ::iter(tab, 7, displayTabParameter<int>);
    
    std::cout << std::endl << "Array char" << std::endl;
    char itHurt[] = {'c', 'a', 'l', 'v', 'i', 't', 'i', 'e'};
    ::iter(itHurt, 8, displayTabParameter<char>);

    std::cout << std::endl << "Array string" << std::endl;
    std::string goat[] = {"the goat", "is taking a walk", "in the fields"};
    ::iter(goat, 3, displayTabParameter<std::string>);
}