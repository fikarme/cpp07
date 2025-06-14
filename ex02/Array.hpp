#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef> // For NULL
#include <stdexcept> // For std::out_of_range
#include <iostream> // for std::cerr
#include <cstdlib>

using std::cout;
using std::cerr;
using std::endl;
using std::out_of_range;
using std::exception;
using std::srand;
using std::rand;

template <typename T>
class Array {
public:
    Array<T>(void) : _size(0), _arr(NULL) {}

    Array<T>(unsigned int N) : _size(N), _arr(NULL) {
        if (N > 0)
            _arr = new T[N];
    }

    Array<T>(const Array<T>& Other) : _size(Other._size), _arr(NULL) {
        if (_size > 0) {
            _arr = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _arr[i] = Other._arr[i];
        }
    }

    ~Array<T>(void) {
        delete[] _arr;
    }

    Array<T>& operator=(const Array<T>& Other) {
        if (this == &Other)
            return *this;

        delete[] _arr;

        _size = Other._size;
        _arr = NULL;

        if (_size > 0) {
            _arr = new T[_size];
            for (unsigned int i = 0; i < _size; ++i)
                _arr[i] = Other._arr[i];
        }
        return *this;
    }

    T& operator[](unsigned int Index) {
        if (Index >= _size)
            throw out_of_range("Index out of bounds");
        return _arr[Index];
    }

    const T& operator[](unsigned int Index) const {
        if (Index >= _size)
            throw out_of_range("Index out of bounds");
        return _arr[Index];
    }

    unsigned int GetSize(void) const {
        return _size;
    }

private:
    unsigned int _size;
    T* _arr;
};

#endif
