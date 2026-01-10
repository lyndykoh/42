/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:11:52 by lkoh              #+#    #+#             */
/*   Updated: 2026/01/10 21:03:48 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        std::cerr << "Brother udk how to follow instructions? ./Pmergeme [POSITIVE INT]" << std::endl;
        return 1;
    }
    else 
    {
        Pmergeme sorter;
        sorter.exec(argc, argv);
    }
    return 0;
}