#include "Array.hpp"

inline void y(int n) {
	cout << endl << YLW << " _/\\__________TEST"
		 << n << "__________/\\_ " << RST << endl;
}

int main() {
	srand(time(NULL));

	Array<int> numbers(100);
	int *arr = new int[100]; // raw array

	for (int i = 0; i < 100; i++) {
		const int val = rand();
		numbers[i] = val;
		arr[i] = val;
	}

	Array<int> tmp(100); // indices 0-99

	y(1);
	try
	{
		for (int i = 0; i < 100; i++)
			tmp[i] = 4;
		for (int i = 0; i < 100; i++)
			cout << "tmp[" << i << "] = " << tmp[i] << endl;
	}
	catch (const exception &e) { cerr << RED << e.what() << RST << endl; }

	tmp = numbers;
	Array<int> tst(tmp);

	y(2);
	try
	{
		for (int i = 0; i < 100; i++)
		{
			if (tmp[i] != tst[i])
				cerr << RED << "ERR: didn't save the same val!" << RST << endl;
			cout << "tmp[" << i << "] = " << tmp[i] << "	-	"
				 << "tst[" << i << "] = " << tst[i] << endl;
		}
	}
	catch (const exception &e) { cerr << RED << e.what() << RST << endl; }

	y(3);
	cout << "tst[1] = " << tst[1] << endl;
	cout << "tmp[1] = " << tmp[1] << endl;

	y(4);
	tst[1] = 1234567890;
	cout << "tst[1] = " << tst[1] << endl;
	cout << "tmp[1] = " << tmp[1] << endl;

	y(5);
	try
	{
		numbers[100] = 0;
	}
	catch (const exception &e) { cerr << RED << e.what() << RST << endl; }

	delete[] arr;
	return 0;
}
