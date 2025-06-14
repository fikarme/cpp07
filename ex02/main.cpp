#include "Array.hpp"

int main()
{
  Array<int> Numbers(100);
  int *PtrArr = new int[100];

  srand(time(NULL));

  for (int i = 0; i < 100; i++)
  {
    const int Value = rand();
    Numbers[i] = Value;
    PtrArr[i] = Value;
  }

  {
    Array<int> Tmp(100);

    cout << "______________TEST - 1___________________" << endl;

    try
    {
      for (int i = 0; i < 100; i++)
        Tmp[i] = 7;
      for (int i = 0; i < 100; i++)
        cout << "Tmp[" << i << "]_" << Tmp[i] << endl;
      cout << endl;
    }
    catch (const exception &E)
    {
      cerr << E.what();
    }

    cout << "______________TEST - 2___________________" << endl;

    Tmp = Numbers;
    Array<int> Test(Tmp);

    try
    {
      for (int i = 0; i < 100; i++)
      {
        if (Tmp[i] != Test[i])
        {
          cerr << "Didn't save the same value!!" << endl;
          return 1;
        }
        cout << "Tmp[" << i << "]_" << Tmp[i] << "  -  " << "Test[" << i
             << "]_" << Test[i] << endl;
      }
    }
    catch (const exception &E)
    {
      cerr << E.what();
    }

    cout << endl << "______________TEST - 3___________________" << endl;

    cout << "Test[1]_" << Test[1] << endl;
    cout << "Tmp[1]_" << Tmp[1] << endl;

    cout << endl << "______________TEST - 4___________________" << endl;

    Test[1] = 123456789;

    cout << "Test[1]_" << Test[1] << endl;
    cout << "Tmp[1]_" << Tmp[1] << endl;
  }

  {
    try
    {
      cout << endl << "______________TEST - 5___________________" << endl;
      Numbers[100] = 0;
    }
    catch (const exception &E)
    {
      cerr << E.what() << endl;
      cout << "You are trying to access out of range. WTF?" << endl;
    }
  }

  delete[] PtrArr;
  return 0;
}
