#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

struct TypeWithTheGoods {
    void doTheThing() {
        cout << "TypeWithTheGoods is doing the thing!" << endl;
    }
};

// This class is SUS - it's missing the doTheThing().
struct TypeMissingStuff {
    void doSomethingElse() {
        cout << "TypeMissingStuff is just doing something else, my bad." << endl;
    }
};

template <typename T_Risky>
void tryToDoTheThing(T_Risky& anObject) {
    cout << "Attempting to call 'doTheThing()' on our object..." << endl;

    // During Phase 1 (template definition), the compiler is like:
    // "Okay, 'anObject.doTheThing()'... I trust you that T_Risky will have this. We'll see."
    anObject.doTheThing();

    cout << "Successfully did the thing!" << endl;
}

int main() {

    TypeWithTheGoods goodInstance;
    tryToDoTheThing(goodInstance);
    // Phase 2 Check for TypeWithTheGoods:
    // Compiler asks: "Does TypeWithTheGoods have 'doTheThing()'?"
    // Answer: "Yes, it does!"
    // Result: All good, code is generated for tryToDoTheThing<TypeWithTheGoods>

    TypeMissingStuff badInstance;
    //tryToDoTheThing(badInstance);
    // ERROR: no member named 'doTheThing' in 'TypeMissingStuff'
    // anObject.doTheThing();
    // ~~~~~~~~ ^

}

// templates: they let you write code that works with any type,
// but only checks for correctness when you actually use that type.
