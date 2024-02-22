/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:02:44 by gduchesn          #+#    #+#             */
/*   Updated: 2024/01/31 11:03:26 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void) {
    Data    *dog = new Data;
    
    dog->dogIQ = 113;
    dog->dogAge = 18;
    dog->dogName = "DoRaGon";

    std::cout << "Dog Name: " << Serializer::deserialize(Serializer::serialize(dog))->dogName << std::endl;
    std::cout << "Dog Age: " << Serializer::deserialize(Serializer::serialize(dog))->dogAge << std::endl;
    std::cout << "Dog IQ: " << Serializer::deserialize(Serializer::serialize(dog))->dogIQ << std::endl;

    delete dog;
    
    return 0;
}