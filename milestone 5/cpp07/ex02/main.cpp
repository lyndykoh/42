#include "Array.hpp"
#include <string>
#include <cassert>

// A helper function to test const access
void printConstArray(const Array<int>& arr) {
    std::cout << "Const access test: ";
    for (unsigned int i = 0; i < arr.size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

int main() {
    // 1. Default constructor
    std::cout << "=== Test 1: Default constructor ===" << std::endl;
    Array<int> empty;
    std::cout << "Empty array size: " << empty.size() << std::endl;

    // 2. Constructor with size
    std::cout << "\n=== Test 2: Constructor with size ===" << std::endl;
    Array<int> ints(5);
    for (unsigned int i = 0; i < ints.size(); ++i)
        ints[i] = i * 10;
    for (unsigned int i = 0; i < ints.size(); ++i)
        std::cout << "ints[" << i << "] = " << ints[i] << std::endl;

    // 3. Out of bounds
    std::cout << "\n=== Test 3: Out of bounds ===" << std::endl;
    try {
        std::cout << ints[10] << std::endl; // should throw
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // 4. Copy constructor
    std::cout << "\n=== Test 4: Copy constructor ===" << std::endl;
    Array<int> copy(ints);
    for (unsigned int i = 0; i < copy.size(); ++i)
        std::cout << "copy[" << i << "] = " << copy[i] << std::endl;

    // Modify copy to ensure deep copy
    copy[0] = 999;
    std::cout << "After modifying copy[0]:" << std::endl;
    std::cout << "ints[0] = " << ints[0] << std::endl;
    std::cout << "copy[0] = " << copy[0] << std::endl;

    // 5. Assignment operator
    std::cout << "\n=== Test 5: Assignment operator ===" << std::endl;
    Array<int> assigned;
    assigned = ints;
    for (unsigned int i = 0; i < assigned.size(); ++i)
        std::cout << "assigned[" << i << "] = " << assigned[i] << std::endl;

    // Modify assigned to check deep copy
    assigned[1] = 12345;
    std::cout << "After modifying assigned[1]:" << std::endl;
    std::cout << "ints[1] = " << ints[1] << std::endl;
    std::cout << "assigned[1] = " << assigned[1] << std::endl;

    // 6. Const correctness
    std::cout << "\n=== Test 6: Const correctness ===" << std::endl;
    printConstArray(ints);

    // 7. Strings
    std::cout << "\n=== Test 7: Strings ===" << std::endl;
    Array<std::string> strs(3);
    strs[0] = "Hello";
    strs[1] = "42";
    strs[2] = "World";
    for (unsigned int i = 0; i < strs.size(); ++i)
        std::cout << "strs[" << i << "] = " << strs[i] << std::endl;

    // 8. Doubles
    std::cout << "\n=== Test 8: Doubles ===" << std::endl;
    Array<double> doubles(4);
    for (unsigned int i = 0; i < doubles.size(); ++i)
        doubles[i] = i * 0.5;
    for (unsigned int i = 0; i < doubles.size(); ++i)
        std::cout << "doubles[" << i << "] = " << doubles[i] << std::endl;

    std::cout << "\nAll tests done!" << std::endl;
    return 0;
}
