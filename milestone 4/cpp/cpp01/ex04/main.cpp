/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:47:30 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/27 16:13:15 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void replaceStr(std::string &content, std::string &s1, std::string &s2) {
    size_t pos = 0;

    while ((pos = content.find(s1, pos)) != std::string::npos) {
        content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
        pos += s2.length();
    }
}

int main (int argc, char *argv[]) {
    if (argc == 4) {
        std::string f = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        std::ifstream infile(f);
        std::ofstream outfile(f + ".replace");
        
        if (!infile.is_open() || !outfile.is_open()) {
            std::cerr << "brother cannot open ur stupid file bruh.." << std::endl;
            return (1);
        }
        if (s1.empty() || s2.empty()) {
            std::cout << "bruh u give me stupid input?" << std::endl;
            return (1);
        }
        std::string content;
        while (std::getline(infile, content)) {
            replaceStr(content, s1, s2);
            outfile << content;
            if (!infile.eof())
                outfile << std::endl;
        }
        infile.close();
        outfile.close();
        return (0);
    }
    else {
        std::cerr << "Brother like that lah: ./sed <filename> <s1> <s2> " << std::endl;
        return (1);
    }
}