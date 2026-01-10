/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:07:25 by lkoh              #+#    #+#             */
/*   Updated: 2025/11/07 17:39:01 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>

#define RESET   "\033[0m"
#define RED     "\033[31m"

class Span {
    private:
        unsigned int _N;
        std::vector<int> _v;

    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int a);
        void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int shortestSpan();
        int longestSpan();

        class OOBException : public std::exception {
            const char* what() const throw();
        };
        class notEnoughException : public std::exception {
            const char* what() const throw();
        };
        
};

#endif