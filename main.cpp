#include <iostream>
#include "Rsa.hpp"

int main() {
  const auto [pub, priv, modulo] = Rsa::generateKeys();

  std::cout << "publiczny: " << pub << "\nprywatny: " << priv << "\nmod: " << modulo << "\n";
  return 0;
}
