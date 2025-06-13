#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // size_t
#include <cctype> // toupper
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// template <typename T>
// void iter(T *arr,  size_t len, void (*f)(T &c)) {
//     if (!arr || len == 0)
//         return;
// 	for (size_t i = 0; i < len; i++)
// 		(*f)(arr[i]);
// }


template <typename E, typename F>
void iter(E* arr, size_t len, F f) {
    if (!arr || len == 0)
        return;
    for (size_t i = 0; i < len; ++i)
        f(arr[i]);
}

#endif
