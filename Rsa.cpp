#include "Rsa.hpp"
#include "NumberGenerator.hpp"
#include "boost/integer/mod_inverse.hpp"

namespace mp = boost::multiprecision;

Rsa::KEYS Rsa::generateKeys() {
  using number_t = types::number_t;
  NumberGenerator gen;
  number_t p = gen.getPrime(), q = gen.getPrime();
  while (q == p) {
    q = gen.getPrime();
  }
  const auto N = p * q;
  const auto fiN = (p - 1) * (q - 1);

  PUBLIC_KEY pub = gen.getNext();
  PRIVATE_KEY priv;

  while (priv == 0 || (pub < fiN && mp::gcd(pub, fiN) != 1)) {
    pub++;
    priv = boost::integer::mod_inverse(pub, fiN);
  }
  return {pub, priv, N};
}
