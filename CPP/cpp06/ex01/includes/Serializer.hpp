/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:54:59 by gduchesn          #+#    #+#             */
/*   Updated: 2024/01/30 16:08:05 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <iostream>

    struct Data {
        int dogIQ;
        int dogAge;
        std::string dogName;
    };

    class Serializer {
        private:
            Serializer(void);
            Serializer(Serializer const & Serializer);
            Serializer & operator=(Serializer const & rhs);
            virtual ~Serializer(void);
        public:
            static uintptr_t serialize(Data* ptr);
            static Data* deserialize(uintptr_t raw);
    };

#endif
