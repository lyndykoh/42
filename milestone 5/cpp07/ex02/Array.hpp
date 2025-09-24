/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:04:25 by lkoh              #+#    #+#             */
/*   Updated: 2025/09/24 15:21:01 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define PINK "\033[95m"

template <typename T> 
class Array {
    private:
    T*              _array;
    unsigned int    _size;
    
    public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();
    
    T &operator[](unsigned int i);
    const T &operator[](unsigned int i) const;
    unsigned int size() const;
    
    class OOBException : public std::exception {
        const char* what() const throw();
    };
};

#include "Array.tpp"

#endif
