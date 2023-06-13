#include "NumberGenerator.hpp"

#include "boost/multiprecision/miller_rabin.hpp"

namespace mp = boost::multiprecision;

NumberGenerator::NumberGenerator() {
  gen.seed(time(nullptr));
}

types::number_t NumberGenerator::getNext() {
  types::unumber_t num = gen();
  // first bit always 1
  num = num >> 1;
  num += mp::pow(types::unumber_t(2), constants::KEY_SIZE - 1);
  return {num};
}

types::number_t NumberGenerator::getPrime() {

  const auto predicate = [](const types::number_t &num) {
    if (num > primes.back())
      return mp::miller_rabin_test(types::unumber_t{num}, 10000);
    return std::find(primes.begin(), primes.end(), num) != std::end(primes);
  };

  types::number_t num = getNext();
  while (!predicate(num)) {
    num = getNext();
  }

  return num;
}

std::vector<uint64_t> NumberGenerator::get_primes(uint64_t n) {
  std::vector<bool> sito(n + 1, false);
  for (uint64_t i = 2; i * i <= n; i++) {
    if (!sito[i])
      for (uint64_t j = i * i; j <= n; j += i)
        sito[j] = true;
  }

  std::vector<uint64_t> primeNumbers;
  for (uint64_t i = 2; i < sito.size(); i++) {
    if (!sito[i]) {
      primeNumbers.push_back(i);
    }
  }

  return primeNumbers;
}

std::vector<uint64_t> NumberGenerator::primes = get_primes(10000);