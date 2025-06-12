#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // size_t
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template <typename TypeElement, typename TypeFunction>
void iter(TypeElement* ArrayAddress, size_t Length, TypeFunction FunctionToApply) {
    if (!ArrayAddress || Length == 0)
        return;

    for (size_t Index = 0; Index < Length; ++Index) {
        FunctionToApply(ArrayAddress[Index]);
    }
}

#endif
