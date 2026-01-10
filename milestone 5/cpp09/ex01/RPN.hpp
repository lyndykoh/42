/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:54:05 by lkoh              #+#    #+#             */
/*   Updated: 2025/11/26 13:31:22 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <sstream>

class RPN 
{
    private:
        std::stack<double> _stack;
        void _exec(double (RPN::*f)(double, double));
        double _plus(double a, double b);
        double _minus(double a, double b);
        double _times(double a, double b);
        double _divide(double a, double b);

    public:
        RPN();
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void processEx(const std::string &input);
        
        class Error: public std::exception {
            public:
                Error(const std::string &msg);
                virtual ~Error() throw();
                virtual const char* what() const throw();
            private:
                std::string _msg;
        };
};

#endif