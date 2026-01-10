/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 20:46:22 by lkoh              #+#    #+#             */
/*   Updated: 2025/11/21 15:10:28 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

btc::btc() : _input("Default") {}

btc::btc(const std::string input) : _input(input) {}

btc::btc(const btc &other) : _input(other._input) {}

btc::~btc() {}

const std::map<std::string, float>& btc::getData() const { return _data; }

btc &btc::operator=(const btc &other) 
{
    if (this != &other)
    {
        *this = other._input;
        this->_data  = other._data;
    }
    return *this;
}

void btc::openReadFile()
{
    std::ifstream file("data.csv");
    if (!file.is_open())
        throw OpenFileException();

    std::string line;
    std::getline(file, line);
    if (line != "date,exchange_rate")
    {
        throw WrongColumnFormat();
    }
    
    while (std::getline(file, line))
    {
        _validLine(line);
    }
    file.close();
}
void btc::processInput(std::string input)
{
    std::ifstream file(input.c_str());
    if (!file.is_open()) {
        std::cout << "Error: could not open file." << std::endl;
        return; 
    }
    
    std::string line;
    std::getline(file, line);

    if (line != "date | value") {
        std::cerr << "Error: file header format is incorrect." << std::endl;
    }

    while (std::getline(file, line))
    {
        size_t delim = line.find('|');
        if (delim == std::string::npos || line.empty()) {
            std::cout << "Error: bad input :/ => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, delim - 1);
        std::string exRate = line.substr(delim + 2);
        if (!_validDate(date)) {
            std::cout << "Error: bad input => " << date << std::endl;
            continue;
        }
        float value; 
        if (_validValue(exRate, value)) 
        {
            std::map<std::string, float>::iterator it = _data.lower_bound(date);
            
            if (it == _data.begin() && it->first != date) {
                std::cout << "Error: date too old" << std::endl;
            }
            else 
            {
                if (it == _data.end() || it->first != date)
                    it--;
                
                float result = value * it->second;
                std::cout << date << " => " << value << " = " << result << std::endl;
            }
        }
    }
    file.close();
}

bool btc::_validDate(std::string date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    
    std::string yearS = date.substr(0, 4);
    std::string monthS = date.substr(5, 2);
    std::string dayS = date.substr(8, 2);

    for (int i = 0; i < 4; i++)
    {
        if (!isdigit(yearS[i]))
            return false;
    }
        for (int i = 0; i < 2; i++)
    {
        if (!isdigit(monthS[i]) || !isdigit(dayS[i]))
            return false;
    }
    
    int year = std::atoi(yearS.c_str());
    int month = std::atoi(monthS.c_str());
    int day = std::atoi(dayS.c_str());

    int daysInMth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMth[1] = 29;

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > daysInMth[month - 1])
        return false;
    
    return true;
}

bool btc::_validValue(std::string valueS, float &storeVal)
{
    char *end;
    storeVal = std::strtof(valueS.c_str(), &end);
    if (valueS.empty() || *end != '\0')
    {
        std::cout << "Error: bad input => :(" << valueS << std::endl;
        return false;
    }
    if (storeVal < 0)
    {
        std::cout << "Error: not a positive number => " << valueS << std::endl;
        return false;
    }
    if (storeVal > 1000.0f)
    {
        std::cout << "Error: too large a number => " << valueS << std::endl;
        return false;
    }
    return true;
}

void btc::_validLine(std::string line)
{
    if (line.empty())
        return;
    size_t delimPos = line.find(',');
    if (delimPos == std::string::npos)
    {
        std::cout << "yes" << std::endl;
        throw WrongColumnFormat();
    }
    std::string date = line.substr(0, delimPos);
    std::string exRate = line.substr(delimPos + 1);

    if (!_validDate(date))
        throw WrongDateFormat();
    
    char *end;
    float rate = strtof(exRate.c_str(), &end);
    if (*end != '\0' || rate < 0)
        throw WrongPriceFormat();
    this->_data.insert(std::make_pair(date, rate));
}


const char* btc::OpenFileException::what() const throw() {
    return (RED "Cannot open file" RESET);
}

const char* btc::WrongColumnFormat::what() const throw() {
    return (RED "Wrong column format" RESET);
}

const char* btc::WrongDateFormat::what() const throw() {
    return (RED "Wrong date format" RESET);
}

const char* btc::WrongPriceFormat::what() const throw() {
    return (RED "Wrong price format" RESET);
}

