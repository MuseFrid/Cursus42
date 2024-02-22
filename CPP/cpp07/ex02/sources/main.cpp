/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:01:15 by gduchesn          #+#    #+#             */
/*   Updated: 2024/02/22 16:56:42 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#define MAX_VAL 750

int    tabOfStringCase(void) {
    Array<std::string> shoppingList(4);
    
    shoppingList[0] = "list of thing to buy :D";
    shoppingList[1] = "A lot of cold coffee";
    shoppingList[2] = "8.5kg flour";
    shoppingList[3] = "18 packs of toilet paper";
    
    std::cout << "Shopping list:" << std::endl;
    for (int i = 0; i < shoppingList.size(); i++) {
        std::cout << "decimal number: " << shoppingList[i] << std::endl;
    }
    
    return(0);
}

int mainFromIntra(void) {
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

int main(int argc, char **argv) {
    (void)argv;
    if (argc == 2)
        return (tabOfStringCase());
    if (argc == 3)
        return (mainFromIntra());
    
    Array<int> decimalNumber(10);
    for (int i = 0; i < 10; i++) {
        decimalNumber[i] = i;
    }
    
    Array<int> decimalCpy(decimalNumber);
    for (int i = 0; i < 10; i++) {
        ++decimalCpy[i];
    }
    
    try {
        for (int i = 0; i < decimalNumber.size(); i++) {
            std::cout << "decimal number: " << decimalNumber[i] << std::endl;
        }
        std::cout << std::endl;
        
        for (int i = 0; i < 11; i++) {
            std::cout << "decimal cpy: " << decimalCpy[i] << std::endl;
        }
        std::cout << std::endl;
    }   catch (std::exception & e) {
        std::cerr << e.what() << std::endl << std::endl;
    }
    
	Array<int>	decimalDefault;
    decimalDefault = decimalCpy;
    for (int i = 0; i < 10; i++) {
        std::cout << "decimal default equal to decimal cpy: " << decimalDefault[i] << std::endl;
    }
    
    return 0;
}
