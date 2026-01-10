/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:00:29 by lkoh              #+#    #+#             */
/*   Updated: 2025/11/21 14:44:06 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define BLUE    "\033[34m"
#define PINK    "\033[95m"

class btc 
{
    private: 
        std::string _input;
        std::map<std::string, float> _data;
        bool _validDate(std::string date);
        bool _validValue(std::string valueS, float &storeVal);
        void _validLine(std::string line);
        
    public:
        const std::map<std::string, float>& getData() const;
        void openReadFile();
        void processInput(std::string input);
        btc();
        btc(const btc &other);
        btc(const std::string input);
        btc &operator=(const btc &other);
        ~btc();
        class OpenFileException : public std::exception {
            public: const char* what() const throw();
        };
                
        class WrongDateFormat : public std::exception {
            public: const char* what() const throw();
        };

        class WrongColumnFormat : public std::exception {
            public: const char* what() const throw();
        };

        class WrongPriceFormat : public std::exception {
            public: const char* what() const throw();
        };
};
