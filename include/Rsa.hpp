#ifndef BSK_RSA_RSA_HPP
#define BSK_RSA_RSA_HPP


#include <tuple>
#include "Constants.hpp"

class Rsa {
public:
  typedef types::number_t KEY;
  typedef types::number_t PUBLIC_KEY;
  typedef types::number_t PRIVATE_KEY;
  typedef types::number_t MODULO;
  using KEYS = std::tuple<PUBLIC_KEY, PRIVATE_KEY, MODULO>;

  static KEYS generateKeys();

  [[nodiscard]]
  static std::vector<types::DATA_BLOCK> useKey(const KEY &key,
                                               const MODULO &modulo,
                                               const std::vector<types::DATA_BLOCK> &data);
};


#endif //BSK_RSA_RSA_HPP
