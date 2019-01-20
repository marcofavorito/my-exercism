#include "atbash_cipher.h"
#include<iostream>

std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
std::string reverseAlphabet = std::string(alphabet.rbegin(), alphabet.rend());
    
auto encoder = atbash::mapFromPairs(atbash::zip(alphabet, reverseAlphabet));
auto decoder = atbash::mapFromPairs(atbash::zip(reverseAlphabet, alphabet));

std::string punctuation = " ,;:.";

std::vector<std::pair<char, char>> atbash::zip(
        const std::string s1, 
        const std::string s2){

    assert(s1.length() == s2.length());
    auto result = std::vector<std::pair<char, char>>();
    for (unsigned int i=0; i<s1.length(); i++){
        result.push_back(std::make_pair(s1.at(i), s2.at(i)));
    }
    return result;
}

std::map<char, char> atbash::mapFromPairs(const std::vector<std::pair<char, char>> pairs){
    auto result = std::map<char, char>();

    for (auto pair : pairs){
        result.insert(pair);
    }
    return result;
}



std::string atbash::encode(std::string plaintext){
    int counter = 0;
    std::string ciphertext = "";
    std::string new_plaintext = plaintext;
    std::transform(plaintext.begin(), plaintext.end(), new_plaintext.begin(), ::tolower);
    for (char& c : new_plaintext){
        if (std::isdigit(c)){
            ciphertext += c;
            ++counter;
            if (counter != 0 && counter % 5 == 0) ciphertext += " ";
        } 
        else if (encoder.find(c) != encoder.end()){
            ciphertext += encoder[c];
            ++counter;
            if (counter != 0 && counter % 5 == 0) ciphertext += " ";
        }
    }

    //remove trailing " "
    if (ciphertext.at(ciphertext.length()-1) == ' ') 
        ciphertext = ciphertext.substr(0, ciphertext.length() - 1);
    return ciphertext;
}

std::string atbash::decode(std::string ciphertext){
    std::string plaintext = "";
    for (char& c : ciphertext){
        if (c == ' ') continue;
        if (std::isdigit(c)){
            plaintext += c;
        }
        else if (decoder.find(c) != decoder.end()){
            plaintext += decoder[c];
        }
    }
    return plaintext;
}

