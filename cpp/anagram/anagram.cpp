#include "anagram.h" 
#include <iostream>

anagram::anagram::anagram(std::string word) {
    this->word = word;
    // to lowercase
    std::transform(this->word.begin(), this->word.end(), this->word.begin(), ::tolower);
    for (char c : this->word){
        if (counts.find(c) == counts.end()) counts[c] = 0;
        ++counts[c];
    }
}

std::vector<std::string> anagram::anagram::matches(std::vector<std::string> words){
    auto result = std::vector<std::string>();
    for (std::string s : words){
        if (this->is_anagram(s)) result.push_back(s);
    }


    return result;
}

bool anagram::anagram::is_anagram(std::string word){
    std::string lower = word;
    std::transform(
        lower.begin(), 
        lower.end(), 
        lower.begin(), 
        ::tolower);
    if (lower == this->word) return false;
    auto counts = std::map<char, int>();
    for (char c : lower){
        if (counts.find(c) == counts.end()) counts[c] = 0;
        ++counts[c];
    }

    if (counts.size() != this->counts.size()) return false;
    for(auto pair : counts){
        std::cout << pair.first << " " << pair.second << std::endl;
        if (this->counts.find(pair.first) == this->counts.end()) return false;
        if (this->counts[pair.first] != pair.second) return false;
    }
    return true;
}

