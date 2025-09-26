/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 15:31:26 by lkoh              #+#    #+#             */
/*   Updated: 2025/09/25 15:03:25 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

#define RESET   "\033[0m"
#define RED     "\033[31m"

class OOBException : public std::exception {
    public: 
        virtual const char* what() const throw()
        {
            return (RED "Value not found" RESET);
        }
};

template <typename T>
typename T::iterator easyfind(T &a, int b)
{
    typename T::iterator iter;
    
    iter = std::find(a.begin(), a.end(), b);
    if (iter == a.end())
        throw OOBException();
    return (iter);
}

#endif
