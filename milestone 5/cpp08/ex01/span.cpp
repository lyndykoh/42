/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 15:19:26 by lkoh              #+#    #+#             */
/*   Updated: 2025/09/25 16:25:28 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::Span(const Span &other) : _N(other._N), _v(other._v) {}

Span &Span::operator=(const Span &other) 
{
    if (this != &other)
    {
        _N = other._N;
        _v = other._v;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int a) 
{
    if (_v.size() > _N)
        throw OOBException();
    _v.push_back(a);
}

int Span::shortestSpan()
{
    if (_v.size() < 2)
        throw notEnoughException();
    std::vector<int> sorted = _v;
    std::sort(sorted.begin(), sorted.end());

    int min = std::numeric_limits<int>::max();
    for (size_t i = 0; i < sorted.size() - 1; i++)
    {
        int diff = sorted[i + 1] - sorted[i];
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan() 
{
    if (_v.size() < 2)
        throw notEnoughException();
    std::vector<int> sorted = _v;
    std::sort(sorted.begin(), sorted.end());
    int min = sorted.front();
    int max = sorted.back();
    return max-min;
}

const char *Span::OOBException::what() const throw()
{
	return (RED "Container is full" RESET);
}

const char *Span::notEnoughException::what() const throw()
{
	return (RED "Not enough numbers" RESET);
}

