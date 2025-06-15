#include "Array.hpp"

inline void y(int n) {
	cout << endl << YLW << " _/\\__________TEST"
		 << n << "__________/\\_ " << RST << endl;
}

inline void r(const char *msg) { cerr << RED << msg << RST << endl; }

int main() {
	srand(time(NULL));

	Array<int> numbers(100);
	int *arr = new int[100];

	for (int i = 0; i < 100; i++) {
		const int val = rand();
		numbers[i] = val;
		arr[i] = val;
	}

	Array<int> tmp(100);

	y(1);
	try
	{
		for (int i = 0; i < 100; i++)
			tmp[i] = 4;
		for (int i = 0; i < 100; i++)
			cout << "tmp[" << i << "] = " << tmp[i] << endl;
	}
	catch (const exception &e) { r(e.what()); }

	tmp = numbers;
	Array<int> tst(tmp);

	y(2);
	try
	{
		for (int i = 0; i < 100; i++)
		{
			if (tmp[i] != tst[i])
				r("didn't save the same val!");
			cout << "tmp[" << i << "] = " << tmp[i] << "	-	"
				 << "tst[" << i << "] = " << tst[i] << endl;
		}
	}
	catch (const exception &e) { r(e.what()); }

	y(3);
	tmp[3] = 123456789;
	cout << "tst[3] = " << tst[3] <<
	endl << "tmp[3] = " << tmp[3] << endl;
	if (tmp[3] == tst[3])
		r("tst[3] and tmp[3] are the same!");

	y(4);
	try { numbers[100] = 0; }
	catch (const exception &e) { r(e.what()); }

	delete[] arr;
	return 0;
}
