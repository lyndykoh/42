/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:47:30 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/19 22:33:34 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main (int argc, char *argv[]) {
    if (argc == 4) {
        std::ifstream f(argv[1]);
        std::string s1 = argv[2];
        std::string s2 = argv[3];
    }
    else {
        std::cerr << "Brother like that lah: ./sed <filename> <s1> <s2> " << std::endl;
        return (1);
    }
}