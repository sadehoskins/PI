#include "my_cpp_array.h"

#include <iostream>

MyCppArray::MyCppArray()
    : data_(fixed_data_),
    size_(0),
    capacity_(kMaxCapacity),
    dynamic_(false) {
}

MyCppArray::~MyCppArray() {
    if (dynamic_) {
        delete[] data_;
    }
}

MyCppArray::MyCppArray(const MyCppArray& other)
    : size_(other.size_),
    capacity_(other.capacity_),
    dynamic_(other.dynamic_) {
    if (dynamic_) {
        data_ = new int[capacity_];
    }
    else {
        data_ = fixed_data_;
    }
    for (int i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }
}

MyCppArray& MyCppArray::operator=(const MyCppArray& other) {
    if (this == &other) {
        return *this;
    }

    // Clean up existing dynamic memory.
    if (dynamic_) {
        delete[] data_;
    }

    size_ = other.size_;
    capacity_ = other.capacity_;
    dynamic_ = other.dynamic_;

    if (dynamic_) {
        data_ = new int[capacity_];
    }
    else {
        data_ = fixed_data_;
    }
    for (int i = 0; i < size_; ++i) {
        data_[i] = other.data_[i];
    }

    return *this;
}

void MyCppArray::Insert(int value) {
    if (size_ < capacity_) {
        data_[size_] = value;
        ++size_;
    }
    else {
        std::cout << "Array is full. Cannot insert " << value << "."
            << std::endl;
    }
}

void MyCppArray::Init(int length) {
    // Free old dynamic memory if present.
    if (dynamic_) {
        delete[] data_;
    }

    // Allocate new dynamic storage for the requested length.
    capacity_ = length;
    size_ = length;
    data_ = new int[capacity_];
    dynamic_ = true;

    // Fill with generated values (example: multiples of 3).
    for (int i = 0; i < size_; ++i) {
        data_[i] = i * 3;
    }
}

int MyCppArray::size() const {
    return size_;
}

int MyCppArray::min() const {
    if (size_ == 0) {
        std::cout << "Array is empty." << std::endl;
        return 0;
    }
    int min_val = data_[0];
    for (int i = 1; i < size_; ++i) {
        if (data_[i] < min_val) {
            min_val = data_[i];
        }
    }
    return min_val;
}

int MyCppArray::max() const {
    if (size_ == 0) {
        std::cout << "Array is empty." << std::endl;
        return 0;
    }
    int max_val = data_[0];
    for (int i = 1; i < size_; ++i) {
        if (data_[i] > max_val) {
            max_val = data_[i];
        }
    }
    return max_val;
}

int MyCppArray::Find(int value) const {
    for (int i = 0; i < size_; ++i) {
        if (data_[i] == value) {
            return i;
        }
    }
    return -1;
}

bool MyCppArray::empty() const {
    return size_ == 0;
}