#pragma once

#include <cstdint>
#include <boost/multiprecision/number.hpp>
#include <boost/multiprecision/cpp_int.hpp>

namespace constants {
  constexpr int KEY_SIZE = 64;
  constexpr int PQ_SIZE = KEY_SIZE / 2;
}

namespace types {
  // int
  typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<
          constants::KEY_SIZE * 2,
          constants::KEY_SIZE * 2,
          boost::multiprecision::signed_magnitude,
          boost::multiprecision::unchecked, void>> number_t;
  // uint
  typedef boost::multiprecision::number<boost::multiprecision::cpp_int_backend<
          constants::KEY_SIZE,
          constants::KEY_SIZE,
          boost::multiprecision::unsigned_magnitude,
          boost::multiprecision::unchecked, void>> unumber_t;
}