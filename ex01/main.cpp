#include "iter.hpp"

void ft_toupper(char &array) {
	array = std::toupper(array);
}

template <typename T>
void ft_print(T &c) {
    cout << c << endl;
}

int main() {
	char arr[3] = {'a', 'b', 'c'};

	cout << "Original:" <<
	endl << "a[0]: " << arr[0] <<
	endl << "a[1]: " << arr[1] <<
	endl << "a[2]: " << arr[2] <<
	endl << endl;

	iter(arr, 3, ft_toupper);

	cout << "Changed:" <<
	endl << "a[0]: " << arr[0] <<
	endl << "a[1]: " << arr[1] <<
	endl << "a[2]: " << arr[2] <<
	endl << endl;

    int ints[6] = {1, 2, 3, 4, 5, 6};
	char chars[6] = {'1', '2', '3', '4', '5', '6'};
	string strings[6] = {"one", "two", "three", "four", "five", "six"};

    iter(ints, 6, ft_print);
    iter(chars, 6, ft_print);
    iter(strings, 6, ft_print);
    return 0;
}
