#include <iostream>
#include "Rsa.hpp"

[[nodiscard]]
std::vector<types::DATA_BLOCK> get_numbers_from_string(const std::vector<uint8_t> &word) {
  std::vector<types::DATA_BLOCK> to_encrypt{};
  types::unumber_t num{0};
  int i = 0;

  for (const auto &c: word) {
    num = num << 8; // shift
    num += c;   // add
    i = (i + 1) % ((constants::KEY_SIZE - 8) / 8); // next byte

    // modulo overflow
    if (i == 0) {
      to_encrypt.emplace_back(num);
      num = 0;
    }
  }

  to_encrypt.emplace_back(num);
  std::reverse(to_encrypt.begin(), to_encrypt.end());
  return to_encrypt;
}

[[nodiscard]]
std::vector<uint8_t> get_string_from_numbers(const std::vector<types::DATA_BLOCK> &numbers) {
  namespace mp = boost::multiprecision;

  std::vector<uint8_t> str;
  for (auto num: numbers) {
    while (num > 0) {
      const auto c = num % mp::pow(types::number_t{2}, 8);
      str.push_back(static_cast<uint8_t>(c));
      num = num >> 8;
    }
  }

  std::reverse(str.begin(), str.end());
  return str;
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    throw std::runtime_error("Podaj wiadomosc do zaszyfrowania");
  }

  const auto [pub, priv, modulo] = Rsa::generateKeys();
  std::cout << "publiczny: " << pub << "\nprywatny: " << priv << "\nmod: " << modulo << "\n";

  std::string word{argv[1]};
  std::vector<uint8_t> buffer(word.begin(), word.end());
  std::vector<types::DATA_BLOCK> data = get_numbers_from_string(buffer);
  std::vector<types::DATA_BLOCK> encrypted = Rsa::useKey(pub, modulo, data);
  std::vector<types::DATA_BLOCK> decrypted = Rsa::useKey(priv, modulo, encrypted);
  std::vector<uint8_t> decrypted_buffer = get_string_from_numbers(decrypted);
  std::string decrypted_word(decrypted_buffer.begin(), decrypted_buffer.end());
  std::cout << decrypted_word << "\n";

  return 0;
}
