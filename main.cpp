#include <iostream>
#include "Constants.hpp"
#include "NumberGenerator.hpp"

int main() {
  NumberGenerator gen;
  types::number_t num = gen.getNext();

  std::cout << num << "\n";

  return 0;
}
