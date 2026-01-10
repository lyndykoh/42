/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 12:11:57 by lkoh              #+#    #+#             */
/*   Updated: 2026/01/10 21:32:41 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

Pmergeme::Pmergeme() {}

Pmergeme::Pmergeme(const Pmergeme &other) 
{
    *this = other;
}

Pmergeme &Pmergeme::operator=(const Pmergeme &other)
{
    if (this != &other)
    {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

Pmergeme::~Pmergeme() {}

template <typename T>
void Pmergeme::printshit(const T &c) const
{
    for (typename T::const_iterator it = c.begin(); it != c.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void Pmergeme::_insertvec(std::vector<int>& main, int value)
{
    std::vector<int>::iterator it = std::lower_bound(main.begin(), main.end(), value);
    main.insert(it, value);
}

void Pmergeme::_sortvec(std::vector<int> &arr)
{
    size_t n = arr.size();
    if (n <= 1)
        return;
    
    bool lonely = (n % 2 != 0);
    int loner = 0;
    if (lonely)
    {
        loner = arr.back();
        arr.pop_back();
    }

    std::vector<int> chickydinny; // winner
    std::vector<std::pair<int, int> > pairs;

    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
            chickydinny.push_back(arr[i]);
        }
        else 
        {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
            chickydinny.push_back(arr[i + 1]);
        }
    }    
    _sortvec(chickydinny);

    std::vector<int> mainchain = chickydinny;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first == mainchain[0])
        {
            mainchain.insert(mainchain.begin(), pairs[i].second);
            pairs.erase(pairs.begin() + i);
            break;
        }
    }
    
    std::vector<int> sortedChicks; // sorted winner
    std::vector<int> sortedLosers;

    for (size_t i = 0; i < mainchain.size(); i++)
    {
        int currentWin = mainchain[i];
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == currentWin)
            {
                sortedLosers.push_back(pairs[j].second);
                sortedChicks.push_back(currentWin);
                break;
            }
        }
    }
    
    const int jacob[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
    size_t pendingCount = sortedChicks.size();
    int lastJacob = 0;
    
    if (pendingCount > 0)
    {
        for (size_t i = 0; i < sizeof(jacob) / sizeof(int); ++i)
        {
            int curJacob = jacob[i];
            bool last = false;
            
            if (curJacob >= (int)pendingCount)
            {
                curJacob = pendingCount;
                last = true;
            }

            for (int i = curJacob; i > lastJacob; --i)
            {
                int loser = sortedLosers[i - 1];
                int limitValue = sortedChicks[i - 1];

                std::vector<int>::iterator boundIt = std::find(mainchain.begin(), mainchain.end(), limitValue);
                std::vector<int>::iterator pos = std::lower_bound(mainchain.begin(), boundIt, loser);
                mainchain.insert(pos, loser);
            }
            lastJacob = curJacob;
            if (last)
                break;
        }
    }
    if (loner)
    {
        _insertvec(mainchain, loner);
    }
    arr = mainchain;
}

void Pmergeme::_insertdeq(std::deque<int> &main, int value)
{
    std::deque<int>::iterator it = std::lower_bound(main.begin(), main.end(), value);
    main.insert(it, value);
}

void Pmergeme::_sortdeq(std::deque<int> &arr)
{
    size_t n = arr.size();
    if (n <= 1)
        return;
    
    bool lonely = (n % 2 != 0);
    int loner = 0;
    if (lonely)
    {
        loner = arr.back();
        arr.pop_back();
    }

    std::deque<int> chickydinny; // winner
    std::deque<std::pair<int, int> > pairs;

    for (size_t i = 0; i < arr.size(); i += 2)
    {
        if (arr[i] > arr[i + 1])
        {
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
            chickydinny.push_back(arr[i]);
        }
        else 
        {
            pairs.push_back(std::make_pair(arr[i + 1], arr[i]));
            chickydinny.push_back(arr[i + 1]);
        }
    }    
    _sortdeq(chickydinny);

    std::deque<int> mainchain = chickydinny;
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (pairs[i].first == mainchain[0])
        {
            mainchain.insert(mainchain.begin(), pairs[i].second);
            pairs.erase(pairs.begin() + i);
            break;
        }
    }
    
    std::deque<int> sortedChicks; // sorted winner
    std::deque<int> sortedLosers;

    for (size_t i = 0; i < mainchain.size(); i++)
    {
        int currentWin = mainchain[i];
        for (size_t j = 0; j < pairs.size(); j++)
        {
            if (pairs[j].first == currentWin)
            {
                sortedLosers.push_back(pairs[j].second);
                sortedChicks.push_back(currentWin);
                break;
            }
        }
    }
    
    const int jacob[] = {3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525};
    size_t pendingCount = sortedChicks.size();
    int lastJacob = 0;
    
    if (pendingCount > 0)
    {
        for (size_t i = 0; i < sizeof(jacob) / sizeof(int); ++i)
        {
            int curJacob = jacob[i];
            bool last = false;
            
            if (curJacob >= (int)pendingCount)
            {
                curJacob = pendingCount;
                last = true;
            }

            for (int i = curJacob; i > lastJacob; --i)
            {
                int loser = sortedLosers[i - 1];
                int limitValue = sortedChicks[i - 1];

                std::deque<int>::iterator boundIt = std::find(mainchain.begin(), mainchain.end(), limitValue);
                std::deque<int>::iterator pos = std::lower_bound(mainchain.begin(), boundIt, loser);
                mainchain.insert(pos, loser);
            }
            lastJacob = curJacob;
            if (last)
                break;
        }
    }
    if (loner)
    {
        _insertdeq(mainchain, loner);
    }
    arr = mainchain;
}

// void Pmergeme::exec(int argc, char *argv[])
// {
//     // 1. Validate Inputs
//     for (int i = 1; i < argc; ++i) {
//         std::string arg = argv[i];
//         if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos) {
//             std::cerr << "Error: Invalid character (positive integers only)." << std::endl;
//             return;
//         }
//         long val = std::atol(arg.c_str());
//         if (val < 0 || val > 2147483647) {
//             std::cerr << "Error: Integer out of range." << std::endl;
//             return;
//         }
//     }

//     // --- PROCESS VECTOR ---
//     struct timeval startVec, endVec;
//     gettimeofday(&startVec, NULL);

//     for (int i = 1; i < argc; ++i) {
//         _vec.push_back(std::atoi(argv[i]));
//     }
    
//     // Print "Before"
//     std::cout << "Before: ";
//     for (size_t i = 0; i < _vec.size(); ++i) {
//         if (i > 4) { std::cout << "[...]"; break; }
//         std::cout << _vec[i] << " ";
//     }
//     std::cout << std::endl;

//     _sortvec(_vec);
    
//     gettimeofday(&endVec, NULL);
//     double timeVec = (endVec.tv_sec - startVec.tv_sec) * 1000000.0 + (endVec.tv_usec - startVec.tv_usec);

//     // --- PROCESS DEQUE ---
//     struct timeval startDeq, endDeq;
//     gettimeofday(&startDeq, NULL);

//     for (int i = 1; i < argc; ++i) {
//         _deq.push_back(std::atoi(argv[i]));
//     }
//     _sortdeq(_deq);

//     gettimeofday(&endDeq, NULL);
//     double timeDeq = (endDeq.tv_sec - startDeq.tv_sec) * 1000000.0 + (endDeq.tv_usec - startDeq.tv_usec);

//     // --- OUTPUT ---
    
//     std::cout << "After:  ";
//     for (size_t i = 0; i < _vec.size(); ++i) {
//         if (i > 4) { std::cout << "[...]"; break; }
//         std::cout << _vec[i] << " ";
//     }
//     std::cout << std::endl;

//     std::cout << "Time to process a range of " << _vec.size() 
//               << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
              
//     std::cout << "Time to process a range of " << _deq.size() 
//               << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
            
// }

void Pmergeme::exec(int argc, char **argv) {
    // 1. Validate Inputs
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg.empty() || arg.find_first_not_of("0123456789") != std::string::npos) {
            std::cerr << "Error: Invalid character (positive integers only)." << std::endl;
            return;
        }
        long val = std::atol(arg.c_str());
        if (val < 0 || val > 2147483647) {
            std::cerr << "Error: Integer out of range." << std::endl;
            return;
        }
    }

    // ==========================================
    //   PROCESS STD::VECTOR
    // ==========================================
    struct timeval startVec, endVec;
    gettimeofday(&startVec, NULL);

    // 1. Fill Vector
    for (int i = 1; i < argc; ++i) {
        _vec.push_back(std::atoi(argv[i]));
    }
    
    // 2. Print Before (Vector)
    std::cout << "Vector Before: ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        if (i > 4) { std::cout << "[...]"; break; }
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;

    // 3. Sort Vector
    _sortvec(_vec);
    
    gettimeofday(&endVec, NULL);
    double timeVec = (endVec.tv_sec - startVec.tv_sec) * 1000000.0 + (endVec.tv_usec - startVec.tv_usec);

    // 4. Print After (Vector)
    std::cout << "Vector After:  ";
    for (size_t i = 0; i < _vec.size(); ++i) {
        if (i > 4) { std::cout << "[...]"; break; }
        std::cout << _vec[i] << " ";
    }
    std::cout << std::endl;


    // ==========================================
    //   PROCESS STD::DEQUE
    // ==========================================
    struct timeval startDeq, endDeq;
    gettimeofday(&startDeq, NULL);

    // 1. Fill Deque
    for (int i = 1; i < argc; ++i) {
        _deq.push_back(std::atoi(argv[i]));
    }

    // 2. Print Before (Deque)
    std::cout << "Deque Before:  ";
    for (size_t i = 0; i < _deq.size(); ++i) {
        if (i > 4) { std::cout << "[...]"; break; }
        std::cout << _deq[i] << " ";
    }
    std::cout << std::endl;

    // 3. Sort Deque
    _sortdeq(_deq);

    gettimeofday(&endDeq, NULL);
    double timeDeq = (endDeq.tv_sec - startDeq.tv_sec) * 1000000.0 + (endDeq.tv_usec - startDeq.tv_usec);

    // 4. Print After (Deque)
    std::cout << "Deque After:   ";
    for (size_t i = 0; i < _deq.size(); ++i) {
        if (i > 4) { std::cout << "[...]"; break; }
        std::cout << _deq[i] << " ";
    }
    std::cout << std::endl;


    // ==========================================
    //   FINAL TIME OUTPUT
    // ==========================================
    std::cout << std::endl;
    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
              
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
}