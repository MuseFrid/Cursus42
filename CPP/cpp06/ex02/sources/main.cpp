/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:02:44 by gduchesn          #+#    #+#             */
/*   Updated: 2024/01/31 11:00:07 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Base {public : virtual ~Base(void);};
class A : public Base {};
class B : public Base {};
class C : public Base {};

Base::~Base(void) {}

Base *  generate(void) {
    Base *randomClass;
    int random = rand() % 3 + 1;
    if (random == 1)
        randomClass = new A;
    if (random == 2)
        randomClass = new B;
    if (random == 3)
        randomClass = new C;
    return (randomClass);
}

void    identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A";
    else if (dynamic_cast<B*>(p))
        std::cout << "B";
    else if (dynamic_cast<C*>(p))
        std::cout << "C";
    else
        std::cerr << "unknowned type";
}

void    identify(Base& p) {
    try {
        A& new_A = dynamic_cast<A&>(p);
        (void) new_A;
        std::cout << "A";
        return;
    }   catch(std::exception& e) {}
    try {
        B& new_B = dynamic_cast<B&>(p);
        (void) new_B;
        std::cout << "B";
        return;
    }   catch(std::exception& e) {}
    try {
        C& new_C = dynamic_cast<C&>(p);
        (void) new_C;
        std::cout << "C";
        return;
    }   catch(std::exception& e) {}
}

int main(void) {
    std::srand(time(0));
    
    Base *caseA = generate();
    Base *caseB = generate();
    Base *caseC = generate();
    Base *caseD = generate();
    
    std::cout << "case A*: "; identify(caseA); std::cout << std::endl;
    std::cout << "case A&: "; identify(*caseA); std::cout << std::endl << std::endl;
    
    std::cout << "case B*: "; identify(caseB); std::cout << std::endl;
    std::cout << "case B&: "; identify(*caseB); std::cout << std::endl << std::endl;
    
    std::cout << "case C*: "; identify(caseC); std::cout << std::endl;
    std::cout << "case C&: "; identify(*caseC); std::cout << std::endl << std::endl;
    
    std::cout << "case D*: "; identify(caseD); std::cout << std::endl;
    std::cout << "case D&: "; identify(*caseD); std::cout << std::endl;
    
    delete caseA;
    delete caseB;
    delete caseC;
    delete caseD;
    
    return 0;
}