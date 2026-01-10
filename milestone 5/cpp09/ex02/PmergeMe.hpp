/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:12:00 by lkoh              #+#    #+#             */
/*   Updated: 2026/01/10 21:22:58 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <iomanip>

class Pmergeme
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

        void _sortvec(std::vector<int> &arr);
        void _insertvec(std::vector<int> &main, int value);

        void _sortdeq(std::deque<int> &arr);
        void _insertdeq(std::deque<int> &main, int value);
        
    public:
        Pmergeme();
        Pmergeme(const Pmergeme &other);
        Pmergeme &operator=(const Pmergeme &other);
        ~Pmergeme();

        template <typename T>
        void printshit(const T &c) const;
        
        void exec(int argc, char *argv[]);
    
};


#endif