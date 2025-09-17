/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 11:34:33 by lkoh              #+#    #+#             */
/*   Updated: 2025/09/17 11:41:49 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    // 1. Create a Data object
    Data data1;
    data1.number = 42;
    data1.text = "Hello, world!";
    data1.value = 3.14159;

    // 2. Show original object and address
    std::cout << "Original Data object:\n";
    std::cout << "  Address: " << &data1 << "\n";
    std::cout << "  number:  " << data1.number << "\n";
    std::cout << "  text:    " << data1.text << "\n";
    std::cout << "  value:   " << data1.value << "\n\n";

    // 3. Serialize pointer
    uintptr_t raw = Serializer::serialize(&data1);
    std::cout << "Serialized uintptr_t value: " << raw << "\n\n";

    // 4. Deserialize back
    Data* ptr = Serializer::deserialize(raw);

    // 5. Verify pointer matches
    std::cout << "Deserialized Data pointer:\n";
    std::cout << "  Address: " << ptr << "\n";
    std::cout << "  number:  " << ptr->number << "\n";
    std::cout << "  text:    " << ptr->text << "\n";
    std::cout << "  value:   " << ptr->value << "\n\n";

    // 6. Check equality
    if (ptr == &data1) {
        std::cout << "✅ Success: Pointers match after serialization/deserialization!\n";
    } else {
        std::cout << "❌ Error: Pointers do NOT match!\n";
    }

    // 7. Test with another object
    Data data2;
    data2.number = -7;
    data2.text = "Second object";
    data2.value = 2.71828;

    std::cout << "Original Data object:\n";
    std::cout << "  Address: " << &data2 << "\n";
    std::cout << "  number:  " << data2.number << "\n";
    std::cout << "  text:    " << data2.text << "\n";
    std::cout << "  value:   " << data2.value << "\n\n";

    uintptr_t raw2 = Serializer::serialize(&data2);
    Data* ptr2 = Serializer::deserialize(raw2);

    std::cout << "\nSecond Data object test:\n";
    std::cout << "  Original address: " << &data2 << "\n";
    std::cout << "  Deserialized addr: " << ptr2 << "\n";
    std::cout << "  number:  " << ptr2->number << "\n";
    std::cout << "  text:    " << ptr2->text << "\n";
    std::cout << "  value:   " << ptr2->value << "\n";

    if (ptr2 == &data2) {
        std::cout << "✅ Success: Pointers match after serialization/deserialization!\n";
    } else {
        std::cout << "❌ Error: Pointers do NOT match!\n";
    }
    
    return 0;
}
