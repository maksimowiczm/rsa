#ifndef BSK_RSA_RSA_HPP
#define BSK_RSA_RSA_HPP


#include <tuple>
#include "Constants.hpp"

class Rsa {
public:
  typedef types::number_t PUBLIC_KEY;
  typedef types::number_t PRIVATE_KEY;
  typedef types::number_t MODULO;
  using KEYS = std::tuple<PUBLIC_KEY, PRIVATE_KEY, MODULO>;

  static KEYS generateKeys();
};


#endif //BSK_RSA_RSA_HPP
