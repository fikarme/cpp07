#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef> // For NULL
#include <stdexcept> // For std::out_of_range
#include <iostream> // For std::cerr
#include <cstdlib> // For std::srand and std::rand
#include <ctime> // For std::time

#define RST "\033[0m"
#define RED "\033[1;31m"
#define YLW "\033[1;33m"

using std::cout;
using std::cerr;
using std::endl;
using std::time;
using std::srand;
using std::rand;
using std::out_of_range;
using std::exception;

template <typename T>
class Array {
private:
    unsigned int size;
    T* arr;
public:
    Array<T>() : size(0), arr(NULL) {}

    Array<T>(unsigned int N) : size(N), arr(NULL) {
        if (N > 0)
            arr = new T[N];
    }

    Array<T>(const Array<T>& cpy) : size(cpy.size), arr(NULL) {
        if (size > 0) {
            arr = new T[size];
            for (unsigned int i = 0; i < size; ++i)
                arr[i] = cpy.arr[i];
        }
    }

    ~Array<T>() { delete[] arr; }

    Array<T>& operator=(const Array<T>& rhs) {
        if (this == &rhs)
            return *this;

        delete[] arr;

        size = rhs.size;
        arr = NULL;

        if (size > 0) {
            arr = new T[size];
            for (unsigned int i = 0; i < size; ++i)
                arr[i] = rhs.arr[i];
        }
        return *this;
    }

    T& operator[](unsigned int index) {
        if (index >= size)
            throw out_of_range("index out of bounds");
        return arr[index];
    }

    const T& operator[](unsigned int index) const {
        if (index >= size)
            throw out_of_range("index out of bounds (const)");
        return arr[index];
    }

    unsigned int getSize() const { return size; }
};

#endif
