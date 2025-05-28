/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:18:37 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/28 15:07:14 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "KNN like that lah: ./harlFilter <level>" << std::endl;
        return (1);
    }
    
    Harl harl;
    harl.complain(argv[1]);
    return (0);
}