#ifndef CRYPTO_SQUARE_H
#define CRYPTO_SQUARE_H

#include <string>
#include <vector>
#include <regex>

namespace crypto_square{
    class cipher{
        private:
            std::string _plaintext;
        public:
            cipher(std::string plaintext) : _plaintext{plaintext} {}
            std::string normalize_plain_text();
            std::vector<std::string> plain_text_segments();
            std::string cipher_text();
            std::string normalized_cipher_text();
    };
}

#endif /* !CRYPTO_SQUARE_H */


