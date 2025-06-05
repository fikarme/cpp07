# General rules
- use UpperCamelCase
- use Orthodox Canonical Form
- use C++98 standard.
- use these flags: -Wall -Wextra -Werror
- don't use braces for single-line if statements
- no function implementation in header files

# ex00: Start with a few functions
Files to turn in :Makefile, main.cpp, whatever.{h, hpp}
Forbidden functions :None

Implement the following function templates:
- swap: Swaps the values of two given parameters. Does not return anything.
- min: Compares the two values passed as parameters and returns the smallest one.
    If they are equal, it returns the second one.
- max: Compares the two values passed as parameters and returns the greatest one.
    If they are equal, it returns the second one.

These functions can be called with any type of argument. The only requirement is
that the two arguments must have the same type and must support all the comparison
operators.

Templates must be defined in the header files.

Running the following code:

int main( void ) {
int a = 2;
int b = 3;
::swap( a, b );
std::cout << "a = " << a << ", b = " << b << std::endl;
std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
std::string c = "chaine1";
std::string d = "chaine2";
::swap(c, d);
std::cout << "c = " << c << ", d = " << d << std::endl;
std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
return 0;
}

Should output:

a = 3, b = 2
min(a, b) = 2
max(a, b) = 3
c = chaine2, d = chaine
min(c, d) = chaine
max(c, d) = chaine

# ex01: Iter
Files to turn in :Makefile, main.cpp, iter.{h, hpp}
Forbidden functions :None

Implement a function templateiterthat takes 3 parameters and returns nothing.
- The first parameter is the address of an array.
- The second one is the length of the array.
- The third one is a function that will be called on every element of the array.

Submit amain.cppfile that contains your tests. Provide enough code to generate a
test executable.

Youriterfunction template must work with any type of array. The third parameter
can be an instantiated function template.

The function passed as the third parameter may take its argument byconstreference
or non-constreference, depending on the context.

Think carefully about how to support both const and non-const
elements in your iter function.

# ex02: Array
Files to turn in :Makefile, main.cpp, Array.{h, hpp}
and optional file: Array.tpp
Forbidden functions :None

Develop a class template **Array** that contains elements of typeTand that implements
the following behavior and functions:

- Construction with no parameter: Creates an empty array.
- Construction with an unsigned intnas a parameter: Creates an array ofnelements
    initialized by default.
    Tip: Try to compileint * a = new int();then display*a.
- Construction by copy and assignment operator. In both cases, modifying either the
    original array or its copy after copying musn’t affect the other array.
- You MUST use the operatornew[]to allocate memory. Preventive allocation (al-
    locating memory in advance) is forbidden. Your program must never access non-
    allocated memory.
- Elements can be accessed through the subscript operator: [ ].
- When accessing an element with the [ ] operator, if its index is out of bounds, an
    std::exceptionis thrown.
- A member functionsize()that returns the number of elements in the array. This
    member function takes no parameters and must not modify the current instance.

As usual, ensure everything works as expected and turn in amain.cppfile that con-
tains your tests.