#ifndef BSK_RSA_RSA_HPP
#define BSK_RSA_RSA_HPP


#include <tuple>
#include "Constants.hpp"

class Rsa {
  using KEYS = std::tuple<types::number_t, types::number_t, types::number_t>;

  static KEYS generateKeys();
};


#endif //BSK_RSA_RSA_HPP
