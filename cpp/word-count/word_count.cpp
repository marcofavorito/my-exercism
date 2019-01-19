#include "word_count.h"
#include <iostream>

char delimiters[] = " :,.-!&@$%^&\n\t";
/*
std::map<std::string, int> word_count::words(std::string sentence){
    auto result = std::map<std::string,int>();

    char * cstr = new char [sentence.length()+1];
    std::strcpy (cstr, sentence.c_str());

    const char* tok = std::strtok(cstr, delimiters);
    while (tok != NULL){
        std::string word{tok};
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (result.find(word) == result.end()){
            result[word] = 0;
        }
        result[word] += 1;
        tok = std::strtok(NULL, delimiters);
    }
    return result;
}
*/


std::map<std::string, int> word_count::words(std::string sentence){
    auto result = std::map<std::string, int>();
    std::regex rgx("\\W'\\W|[\n .,\\/#!$%\\^&\\*;:{}=\\-_`~()@]");
    std::sregex_token_iterator iter(
        sentence.begin(),
        sentence.end(),
        rgx,
        -1);
    std::sregex_token_iterator end;
    for ( ; iter != end; ++iter){
        std::string word{*iter};
        if (word == "") continue;
        if (word[0] == '\'') word = word.substr(1, word.length() - 1);
        if (word[word.length() - 1] == '\'') word = word.substr(0, word.length() - 1);
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (result.find(word) == result.end()){
            result[word] = 0;
        }
        result[word] += 1;
    }

    return result; 
}

