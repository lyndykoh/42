/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 14:44:18 by lkoh              #+#    #+#             */
/*   Updated: 2025/09/17 14:59:26 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap (T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T> 
T min (T &a, T &b)
{
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T max (T &a, T &b)
{
    if (a > b)
        return a;
    else 
        return b;
}

#endif