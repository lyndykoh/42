/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:59:14 by lkoh              #+#    #+#             */
/*   Updated: 2025/11/21 15:19:56 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "sister... dont need me to hold ur hand for everything.. like that pls ./btc [file]" << std::endl;
        return 1;
    }
    else 
    {
        btc btc;
        try 
        {
            btc.openReadFile();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            return 1;
        }

        try 
        {
            btc.processInput(argv[1]);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            return 1;
        }
        return 0;
    }
}
