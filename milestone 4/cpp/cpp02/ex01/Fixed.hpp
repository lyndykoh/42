/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:09:02 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/30 14:43:38 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
    private:
        int _value;
        static const int _fraction = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed& operator=(const Fixed& other);
        ~Fixed();
        int getRawBits(void) const;
        void setRawBits(int const raw);  
           
        Fixed(const int num);
        Fixed(const float num);
        float toFloat(void) const;
        int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);


#endif