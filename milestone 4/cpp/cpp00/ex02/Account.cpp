/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:27:02 by lkoh              #+#    #+#             */
/*   Updated: 2025/05/16 14:57:21 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account() {}

void Account::_displayTimestamp() {
    time_t timestamp;
    char output[50];
    struct tm * datetime;
    time(&timestamp);
    datetime = localtime(&timestamp);

    strftime(output, 50, "[%Y%m%d_%H%M%S]", datetime);
    std::cout << output << " ";
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";" 
              << "total:" << _totalAmount << ";"
              << "deposits:" << _totalNbDeposits << ";"
              << "withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";" 
              << "p_amount:" << _totalAmount << ";"
              << "deposit:" << deposit << ";";

    _totalAmount += deposit;
    _amount += deposit;
    _totalNbDeposits++;
    _nbDeposits++;

    std::cout << "amount:" << _amount << ";"
              << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    
    if (_amount >= withdrawal) {
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _totalAmount << ";"
              << "withdrawal:" << withdrawal << ";";
              
    _totalAmount += withdrawal;
    _amount += withdrawal;
    _totalNbWithdrawals++;
    _nbWithdrawals++;  
    
    std::cout << "amount:" << _amount << ";"
              << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
    }
    else {
        std::cout << "index:" << _accountIndex << ";"
                  << "p_amount:" << _totalAmount << ";"
                  << "withdrawal:refused" << std::endl;
        return (false);
    }
}

int Account::checkAmount() const {
    return (_amount);
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "p_amount:" << _totalAmount << ";"
              << "deposits:" << _nbDeposits << ";"
              << "withdrawals:" << _nbWithdrawals << std::endl;
}

Account::Account(int initial_deposit){
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _totalAmount += _amount;
    _displayTimestamp();
    std::cout << "index:" <<  _accountIndex << ";"
              << "amount:" << initial_deposit << ";"
              << "created" << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";"
              << "amount:" << _amount << ";"
              << "closed" << std::endl;
}