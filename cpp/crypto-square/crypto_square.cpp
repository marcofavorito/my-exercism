#include "crypto_square.h"

std::string crypto_square::cipher::normalize_plain_text(){
    std::string temp {_plaintext};

    //remove punctuations
    std::regex e ("\\W");
    temp = std::regex_replace(temp, e, "");

    //lowercase
    std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    return temp;

}

std::vector<std::string> plain_text_segments(){
    std::vector<std::string> result;
    return result;
}


