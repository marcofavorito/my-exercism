#include "crypto_square.h"
#include <iostream>


std::pair<int, int> find_perfect_rectangle(int n){
    int temp = sqrt(n);
    int c; int r;
    if (temp * temp == n){
        c = temp;
        r = temp;
    }
    else{
        c = temp + 1;
        r = temp;
    }
    return std::make_pair(c, r);
}

std::string crypto_square::cipher::normalize_plain_text(){
    std::string temp {_plaintext};

    //remove punctuations
    std::regex e ("\\W");
    temp = std::regex_replace(temp, e, "");

    //lowercase
    std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    return temp;

}

std::vector<std::string> crypto_square::cipher::plain_text_segments(){
    std::vector<std::string> result;
    std::string normalized_plaintext = this->normalize_plain_text();

    int n = normalized_plaintext.length();
    int c; int r;
    std::tie(c, r) = find_perfect_rectangle(n);

    for (int i = 0; i < r; i++){
        int base = c * i;
        int offset = base + c > n? n - base : c;
        
        std::string row = normalized_plaintext.substr(base, offset);
        result.push_back(row);
    }

    return result;
}

std::string crypto_square::cipher::cipher_text(){
    std::string result = "";
    auto segments = this->plain_text_segments();
    if (segments.size() == 0) return result;
    for (size_t i = 0; i < segments[0].length(); i++){
        for (size_t j = 0; j < segments.size(); j++){
            if (i >= segments[j].length()) continue;
            result += segments[j][i]; 
        }
    }
    return result;
}

std::string crypto_square::cipher::normalized_cipher_text(){
    std::string result = "";
    std::string cipher_text = this->cipher_text();
    int n = cipher_text.length();
    int c; int r;
    std::tie(r, c) = find_perfect_rectangle(n);
    int diff = c * r - n;
    int offset = 0;
    for (int i=0; i<r; i++){
        if (r - i > diff){
            result += cipher_text.substr(i * c, c) + " ";
        }
        else{
            result += cipher_text.substr(i * c - offset, c - 1) + "  ";
            offset++;
        }
    }
    return result.substr(0, result.length() - 1);
}



