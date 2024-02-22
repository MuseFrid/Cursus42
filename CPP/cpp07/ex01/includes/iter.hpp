/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:45:06 by gduchesn          #+#    #+#             */
/*   Updated: 2024/02/21 15:17:23 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
# include <iostream>

template<typename W>
void    displayTabParameter(W &element) {
    std::cout << "Element: " << element << std::endl;
}

template<typename W>
void    iter(W array[], int lenght, void(*f)(W &)) {
    int i = 0;
    
    while (i < lenght) {
        f(array[i++]);
    }
}

#endif
