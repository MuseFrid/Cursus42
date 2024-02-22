/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:38:48 by gduchesn          #+#    #+#             */
/*   Updated: 2024/02/02 17:40:54 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
# include <iostream>

template<typename W>
void    swap(W & x, W & y) {
    W tmp;
    tmp = x;
    x = y;
    y = tmp;
}

template<typename W>
W   min(W & x, W & y) {
    if (x < y)
        return(x);
    return y;
}

template<typename W>
W   max(W & x, W & y) {
    if (x > y)
        return(x);
    return y;
}

#endif
