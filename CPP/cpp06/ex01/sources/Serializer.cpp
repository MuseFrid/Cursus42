/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:54:38 by gduchesn          #+#    #+#             */
/*   Updated: 2024/01/30 16:10:17 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(Serializer const & Serializer) {(void) Serializer;}

Serializer::~Serializer(void) {}

Serializer & Serializer::operator=(Serializer const & rhs) {
    (void) rhs;
    return (*this);
}

uintptr_t   Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*   Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}
