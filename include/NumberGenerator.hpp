#ifndef BSK_RSA_NUMBERGENERATOR_HPP
#define BSK_RSA_NUMBERGENERATOR_HPP

#include <boost/multiprecision/cpp_int.hpp>
#include "boost/random.hpp"
#include "Constants.hpp"

//template<unsigned KEY_SIZE>
class NumberGenerator {
private:
  static std::vector<uint64_t> primes;

  static std::vector<uint64_t> get_primes(uint64_t n);

  typedef boost::random::independent_bits_engine<boost::random::mt19937, constants::PQ_SIZE, types::unumber_t> generator_t;
  generator_t gen;

public:
  NumberGenerator();

  types::number_t getNext();

  types::number_t getPrime();
};


#endif //BSK_RSA_NUMBERGENERATOR_HPP
