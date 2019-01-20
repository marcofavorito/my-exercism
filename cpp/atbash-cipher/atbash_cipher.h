#ifndef ATBASH_CIPHER
#define ATBASH_CIPHER

#include <string>
#include <map>
#include <vector>
#include <cassert>
#include <algorithm>
#include <cctype>

namespace atbash{
    std::string encode(std::string plaintext);
    std::string decode(std::string ciphertext);
    std::vector<std::pair<char, char>> zip(const std::string s1, const std::string s2);
    std::map<char, char> mapFromPairs(const std::vector<std::pair<char, char>> pairs);


}

#endif /* !ATBASH_CIPHER */


