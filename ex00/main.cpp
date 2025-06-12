#include "whatever.hpp"

int main() {
  int a = 2;
  int b = 2;
  ::swap(a, b);
  cout << "a = " << a << ", b = " << b << endl;
  cout << "min( a, b ) = " << ::min(a, b) << endl;
  cout << "max( a, b ) = " << ::max(a, b) << endl;
  string c = "chaine1";
  string d = "chaine2";
  ::swap(c, d);
  cout << "c = " << c << ", d = " << d << endl;
  cout << "min( c, d ) = " << ::min(c, d) << endl;
  cout << "max( c, d ) = " << ::max(c, d) << endl;
  return 0;
}

// a = 3, b = 2
// min(a, b) = 2
// max(a, b) = 3
// c = chaine2, d = chaine1
// min(c, d) = chaine1
// max(c, d) = chaine2
