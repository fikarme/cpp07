#include <iostream>
using std::cout;
using std::endl;

int add(int a, int b) {
    return a + b;
    // cout << a + b << endl;
}

int main() {
    float bad = add(3.14f, 2.86f);
    float badder = add(static_cast<int>(3.14f), static_cast<int>(2.86f));
    int good = add(3, 2);
    cout << "bad: " << bad << endl;
    cout << "badder: " << badder << endl;
    cout << "good: " << good << endl;
}
