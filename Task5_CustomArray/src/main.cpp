#include <iostream>

#include "my_cpp_array.h"

void HandleSearchValue(const MyCppArray& arr) {
    int search_value;
    std::cout << "Enter a value to search for: ";
    std::cin >> search_value;

    int index = arr.Find(search_value);
    if (index != -1) {
        std::cout << "Value " << search_value << " found at index " << index
            << "." << std::endl;
    }
    else {
        std::cout << "Value " << search_value << " not found." << std::endl;
    }
}

void PrintArrayInfo(const MyCppArray& arr) {
    std::cout << "Size: " << arr.size() << std::endl;

    if (!arr.empty()) {
        std::cout << "Min value: " << arr.min() << std::endl;
        std::cout << "Max value: " << arr.max() << std::endl;
    }
    else {
        std::cout << "Array is empty." << std::endl;
    }
}

int main() {
    
    std::cout << "Part A: Fixed-size array " << std::endl;

    MyCppArray my_array;

    for (int i = 1; i <= 5; ++i) {
        my_array.Insert(i * 2);  // Fills with 2, 4, 6, 8, 10.
    }

    PrintArrayInfo(my_array);
    HandleSearchValue(my_array);

    std::cout << std::endl;

    // Part B: Dynamic array demo
    std::cout << "Part B: Dynamic array" << std::endl;

    // same array object is filled twice with different sizes
    for (int i = 0; i < 2; ++i) {
        int choice;
        std::cout << "Enter size for dynamic array: ";
        std::cin >> choice;

        my_array.Init(choice);

        PrintArrayInfo(my_array);
        HandleSearchValue(my_array);

        std::cout << std::endl;
    }

    return 0;
}