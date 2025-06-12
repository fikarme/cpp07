#include <iostream>
#include <string>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::min;
using std::max;

namespace MyCustomFuncs {
    template <typename T>
    const T& Min(const T& ValA, const T& ValB) {
        if (ValA <= ValB)
            return ValA;
        return ValB;
    }

    template <typename T>
    const T& Max(const T& ValA, const T& ValB) {
        return (ValA >= ValB) ? ValA : ValB;
    }
}

int main() {
    int Num1 = 42;
    int Num2 = 42;

    cout << "--- Testing with min/max ---" << endl;
    const int& RefMinStd = min(Num1, Num2);
    if (&RefMinStd == &Num1)
        cout << "min(Num1, Num2) returned a reference to Num1" << endl;
    else if (&RefMinStd == &Num2)
        cout << "min(Num1, Num2) returned a reference to Num2" << endl;

    const int& RefMaxStd = max(Num1, Num2);
    if (&RefMaxStd == &Num1)
        cout << "max(Num1, Num2) returned a reference to Num1" << endl;
    else if (&RefMaxStd == &Num2)
        cout << "max(Num1, Num2) returned a reference to Num2" << endl;

    cout << "\n--- Testing with MyCustomFuncs::Min/MyCustomFuncs::Max ---" << endl;
    const int& RefMinCustom = MyCustomFuncs::Min(Num1, Num2);
    if (&RefMinCustom == &Num1)
        cout << "MyCustomFuncs::Min(Num1, Num2) returned a reference to Num1" << endl;
    else if (&RefMinCustom == &Num2)
        cout << "MyCustomFuncs::Min(Num1, Num2) returned a reference to Num2" << endl;

    const int& RefMaxCustom = MyCustomFuncs::Max(Num1, Num2);
    if (&RefMaxCustom == &Num1)
        cout << "MyCustomFuncs::Max(Num1, Num2) returned a reference to Num1" << endl;
    else if (&RefMaxCustom == &Num2)
        cout << "MyCustomFuncs::Max(Num1, Num2) returned a reference to Num2" << endl;

    string Str1 = "level";
    string Str2 = "level";

    cout << "\n--- Testing min with string ---" << endl;
    const string& RefMinStrStd = min(Str1, Str2);
    if (&RefMinStrStd == &Str1)
        cout << "min(Str1, Str2) returned a reference to Str1" << endl;
    else if (&RefMinStrStd == &Str2)
        cout << "min(Str1, Str2) returned a reference to Str2" << endl;

    cout << "\n--- Testing MyCustomFuncs::Min with string ---" << endl;
    const string& RefMinStrCustom = MyCustomFuncs::Min(Str1, Str2);
    if (&RefMinStrCustom == &Str1)
        cout << "MyCustomFuncs::Min(Str1, Str2) returned a reference to Str1" << endl;
    else if (&RefMinStrCustom == &Str2)
        cout << "MyCustomFuncs::Min(Str1, Str2) returned a reference to Str2" << endl;

    return 0;
}
