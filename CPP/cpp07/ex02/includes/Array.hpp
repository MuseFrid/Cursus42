/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduchesn <gduchesn@students.s19.be>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:33:51 by gduchesn          #+#    #+#             */
/*   Updated: 2024/02/21 20:41:23 by gduchesn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <exception>
# include <iostream>

template<typename T>
class Array {
    private:
        T   *_Array;
        int _size;
    public:
        Array(void);
        Array(int n);
        Array(Array<T> const & src);
        Array<T> & operator=(Array<T> const & rhs);
        T & operator[](int index);
        class OutOfBounds : public std::exception {
            public://///////////////.......////////////////////////////////////////////////////////
                virtual const char * what(void) const throw();
        };
        int size(void);
};

template<typename T>
Array<T>::Array(void) : _size(0)  {
    _Array = nullptr;
}

template<typename T>
Array<T>::Array(int n) : _size(n) {
    _Array = new T[n];
}

template<typename T>
Array<T>::Array(Array<T> const & src) : _size(src._size){
    _Array = new T[_size];
    for (int i = 0; i < _size; i++) {
        this->_Array[i] = src._Array[i];
    }
}

template<typename T>
Array<T> & Array<T>::operator=(Array<T> const & rhs) {
    delete [] this->_Array;
    this->_size = rhs._size;
    _Array = new T[_size];
    for (int i = 0; i < _size; i++) {
        this->_Array[i] = rhs._Array[i];
    }
    return (*this);
}

template<typename T>
T & Array<T>::operator[](int index) {
    if (index > _size - 1)
        throw OutOfBounds();
    return(_Array[index]);
}

template<typename T>
const char * Array<T>::OutOfBounds::what(void) const throw() {
    return ("Error: Out of bounds, element does not exist");
}

template<typename T>
int Array<T>::size(void) {
    return (_size);
}

#endif
