#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

//             ↓ type parameter (can use class it's the same)
// template <typename T>
// void Print(const T& value) {
//     cout << typo << endl; //
// }   ~~~~~~~~^ but compiler still checks for basic syntax errors.
// not a real func. only gets created when called.

template <typename T>
void Print(const T& value) {
    cout << "template: " << value << endl;
}

void Print(int value) {
    cout << "overload: " << value << endl;
}

template <int N>
class Array {
    private:
        int arr[N];
    public:
        int getSize() const { return N; }
};

int main() {

    Print(5);
    Print("Hello, World!");
    Print(3.14);

    Print<char>('A');
    Print<char>(42);

    Array<5> dizi;
    cout << "Size of dizi: " << dizi.getSize() << endl;
    Array<'5'> dizi2;
    cout << "Size of dizi2: " << dizi2.getSize() << endl;

}

//std library use templates
//its usually takes a type and size parameter

//meta programming:
//when you write a template, the compiler will generate code for each type you use with it
//so we dont code the for the runtime we code for the compiler thats called 'meta programming'

//meta language:
//lots of companys like game studios ban templates
//cuz its hard to debug when its spirals to a 'meta language'
