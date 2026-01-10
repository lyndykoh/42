/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:54:02 by lkoh              #+#    #+#             */
/*   Updated: 2025/11/28 12:09:51 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &other)
{
    *this = other;
}

RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        _stack = other._stack;
    return *this;
}

RPN::~RPN() {}

double RPN::_plus(double a, double b)
{
    return b + a;
}

double RPN::_minus(double a, double b)
{
    return b - a;
}

double RPN::_times(double a, double b)
{
    return b * a;
}

double RPN::_divide(double a, double b)
{
    if (a == 0.0)
        throw Error("Division by zero");
    return b / a;
}

void RPN::processEx(const std::string &input)
{
    std::stringstream ss(input);
    std::string token;
    
    while (ss >> token)
    {
        if (token.length() == 1 && isdigit(token[0]))
            _stack.push(std::atof(token.c_str()));
        else if (token == "+") 
            _exec(&RPN::_plus);
        else if (token == "-")
            _exec(&RPN::_minus);
        else if (token == "*")
            _exec(&RPN::_times);
        else if (token == "/")
            _exec(&RPN::_divide);
        else 
            throw Error("Invalid token: " + token);
    }

    if (_stack.size() != 1)
        throw Error("Invalid expression: too many operands");
    std::cout << _stack.top() << std::endl;
}

void RPN::_exec(double (RPN::*f)(double, double))
{
    if (_stack.size() < 2)
        throw Error("Not enough operands");
    double a = _stack.top();
    _stack.pop();
    double b = _stack.top();
    _stack.pop();
    _stack.push((this->*f)(a, b));
}

RPN::Error::Error(const std::string &msg) : _msg(msg) {}
RPN::Error::~Error() throw() {}
const char *RPN::Error::what() const throw() 
{
    return _msg.c_str();
}