/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:24:35 by lkoh              #+#    #+#             */
/*   Updated: 2025/09/17 17:57:09 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void times2(int i)
{
    i = i * 2;
}

template<typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

template<typename T>
void doubleElement(T& element) {
    element *= 2;
}

// Function that takes const reference for strings
void printString(const std::string& str) {
    std::cout << "[" << str << "] ";
}

// Function that modifies strings
void appendExclamation(std::string& str) {
    str += "!";
}

// Function object (functor) example
struct Printer {
    template<typename T>
    void operator()(const T& element) const {
        std::cout << "(" << element << ") ";
    }
};

// Lambda-compatible function object for modification
struct Incrementer {
    template<typename T>
    void operator()(T& element) const {
        ++element;
    }
};

int main (void) 
{
    std::cout << "=== Testing iter function template ===\n\n";
    
    // Test 1: Integer array with const function (read-only)
    std::cout << "Test 1: Integer array - printing elements\n";
    int intArray[] = {1, 2, 3, 4, 5};
    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
    
    std::cout << "Original: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << "\n";

// Test 2: Integer array with non-const function (modifying)
    std::cout << "\nTest 2: Integer array - doubling elements\n";
    std::cout << "Before doubling: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << "\n";
    
    iter(intArray, intSize, doubleElement<int>);
    std::cout << "After doubling: ";
    iter(intArray, intSize, printElement<int>);
    std::cout << "\n";
    
    // Test 3: Double array
    std::cout << "\nTest 3: Double array\n";
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4};
    size_t doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
    
    std::cout << "Original: ";
    iter(doubleArray, doubleSize, printElement<double>);
    std::cout << "\n";
    
    iter(doubleArray, doubleSize, doubleElement<double>);
    std::cout << "After doubling: ";
    iter(doubleArray, doubleSize, printElement<double>);
    std::cout << "\n";
    
    // Test 4: String array with const function
    std::cout << "\nTest 4: String array - printing\n";
    std::string stringArray[] = {"Hello", "World", "Template", "Magic"};
    size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
    
    std::cout << "Original strings: ";
    iter(stringArray, stringSize, printString);
    std::cout << "\n";
    
    // Test 5: String array with modifying function
    std::cout << "\nTest 5: String array - adding exclamations\n";
    iter(stringArray, stringSize, appendExclamation);
    std::cout << "After modification: ";
    iter(stringArray, stringSize, printString);
    std::cout << "\n";
    
    // Test 6: Using function objects (functors)
    std::cout << "\nTest 6: Using function objects\n";
    int testArray[] = {10, 20, 30};
    size_t testSize = sizeof(testArray) / sizeof(testArray[0]);
    
    std::cout << "Using Printer function: ";
    Printer printer;
    iter(testArray, testSize, printer);
    std::cout << "\n";
    
    std::cout << "Before increment: ";
    iter(testArray, testSize, printElement<int>);
    std::cout << "\n";
    
    Incrementer inc;
    iter(testArray, testSize, inc);
    std::cout << "After increment: ";
    iter(testArray, testSize, printElement<int>);
    std::cout << "\n";
    
    // Test 8: Const array (should work with const functions only)
    std::cout << "\nTest 7: Const array\n";
    const int constArray[] = {100, 200, 300};
    size_t constSize = sizeof(constArray) / sizeof(constArray[0]);
    
    std::cout << "Const array elements: ";
    iter(constArray, constSize, printElement<int>);
    std::cout << "\n";
    
    // This would cause a compilation error if uncommented:
    // iter(constArray, constSize, doubleElement<int>);
    
    std::cout << "\n=== All tests completed successfully! ===\n";
    
    return 0;    
}