/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:58:58 by lkoh              #+#    #+#             */
/*   Updated: 2025/09/17 12:12:31 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base() {}

Base * generate(void)
{
    int i = rand() % 3;
    switch(i)
    {
        case 0:
            std::cout << "A generated" << std::endl;
            return new A;
        case 1: 
            std::cout << "B generated" << std::endl;
            return new B;
        default:
            std::cout << "C generated" << std::endl;
            return new C;
    }
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "Type A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Type B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Type C" << std::endl;
    else 
        std::cout << "idk what type u getting this from.." << std::endl;
}

void identify(Base& p) 
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "Type A" <<std::endl;
        return;
    }
    catch (std::exception &e) {}
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "Type B" <<std::endl;
        return;
    }
    catch(const std::exception& e) {}
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "Type C" <<std::endl;
        return;
    }
    catch(const std::exception& e) {}
    std::cout << "man idk wtf u did" << std::endl;
}