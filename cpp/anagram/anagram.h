#ifndef ANAGRAM_H
#define ANAGRAM_H

#include <string>
#include <vector>
#include <map>
#include <algorithm>

namespace anagram {
    class anagram{
        private:
            std::string word;
            std::map<char, int> counts;
        public:
            anagram(std::string word);
            std::vector<std::string> matches(std::vector<std::string> words); 
            bool is_anagram(std::string word); 
    };
}

#endif /* !ANAGRAM_H */


