#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef> // For size_t, gotta have the right size type, fam

// Iter: Loops through an array, applies a function to each element. Real MVP.
// Template Parameters:
//   TypeElement: Deduced type of the elements in your array. Could be `int`, `std::string`, or even `const Whatever`.
//   TypeFunction: Deduced type of the function you're passing. This could be a pointer to a regular function or an instantiated function template.
// Function Parameters:
//   ArrayAddress: Pointer to the first element of the array you wanna iterate over.
//   Length: How many elements are in the array. Gotta know when to stop, right?
//   FunctionToApply: The actual function that's gonna do something to each element.
template <typename TypeElement, typename TypeFunction>
void Iter(TypeElement* ArrayAddress, size_t Length, TypeFunction FunctionToApply) {
    // Basic safety check: no null arrays or zero-length shenanigans.
    if (!ArrayAddress || Length == 0)
        return; // Peace out, nothing to do here.

    // The main loop: hit up every element.
    for (size_t Index = 0; Index < Length; ++Index) {
        FunctionToApply(ArrayAddress[Index]); // Apply the drip (function) to the element.
    }
}

#endif
