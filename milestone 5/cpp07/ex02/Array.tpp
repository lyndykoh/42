/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:04:56 by lkoh              #+#    #+#             */
/*   Updated: 2025/09/24 15:27:06 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template<typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template<typename T>
Array<T>::Array(const Array &other) : _array(NULL), _size(other._size)
{
    if (_size > 0)
    {
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++)
        {
            _array[i] = other._array[i];
        }
    }
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
    if (this != &other)
    {
        delete[] _array;
        _array = NULL;
        _size = other._size;
        if (_size > 0)
        {
            _array = new T[_size];
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>::~Array() 
{
    delete[] _array;
}

template<typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= _size)
        throw OOBException();
    return _array[i];
}

template<typename T>
const T &Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw OOBException();
    return _array[i];
}

template<typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

template<typename T>
const char* Array<T>::OOBException::what() const throw() {
    return (RED "Out of Bounds" RESET);
}

#endif