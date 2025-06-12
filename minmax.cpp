#include <array>
#include <iostream>

int main() {
  int a = 2;
  int b = 2;
  std::cout << "min( a, b ) = " << std::min(a, b) << std::endl;
  std::cout << "max( a, b ) = " << std::max(a, b) << std::endl;
  std::string c = "chaine1";
  std::string d = "chaine2";
  std::cout << "min( c, d ) = " << std::min(c, d) << std::endl;
  std::cout << "max( c, d ) = " << std::max(c, d) << std::endl;
  return 0;
}

// a = 3, b = 2
// min(a, b) = 2
// max(a, b) = 3
// c = chaine2, d = chaine1
// min(c, d) = chaine1
// max(c, d) = chaine2
