#include "iter.hpp"
#include <typeinfo>
void ft_toupper(char &arr) {
	arr = std::toupper(arr);
}

template <typename T>
void ft_print(T &c) {
    cout << typeid(c).name() << ": " << c << endl;
}

int main() {
	char arr[3] = {'a', 'b', 'c'};

	cout << "origin:" <<
	endl << "a[0]: " << arr[0] <<
	endl << "a[1]: " << arr[1] <<
	endl << "a[2]: " << arr[2] <<
	endl << endl;

	iter(arr, 3, ft_toupper);

	cout << "upped:" <<
	endl << "a[0]: " << arr[0] <<
	endl << "a[1]: " << arr[1] <<
	endl << "a[2]: " << arr[2] <<
	endl << endl;

    int ints[6] = {1, 2, 3, 4, 5, 6};
	char chars[6] = {'1', '2', '3', '4', '5', '6'};
	string strings[6] = {"one", "two", "three", "four", "five", "six"};

    // "The third parameter can be an instantiated function template."
    // ft_print<int> (an instantiated function template)
    iter(ints, 6, ft_print<int>);
    iter(chars, 6, ft_print<char>);
    iter(strings, 6, ft_print<string>);

    // iter(ints, 6, ft_print);
    // iter(chars, 6, ft_print);
    // iter(strings, 6, ft_print);
}
