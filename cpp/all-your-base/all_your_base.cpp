#include "all_your_base.h"

bool check_input(unsigned int in,
    std::vector<unsigned int> in_digits,
    unsigned int out){

    bool check_leading_zero = true;
    if (in <= 1 || out <= 1) return false;
    for (unsigned int i : in_digits){
        if (i >= in) return false;
        if (i != 0) check_leading_zero = false;
        if (check_leading_zero && i == 0) return false;
    }

    return true;
}

std::vector<unsigned int> all_your_base::convert(
    unsigned int in,
    std::vector<unsigned int> in_digits,
    unsigned int out){
    if (!check_input(in, in_digits, out)) return std::vector<unsigned int>();
    return all_your_base::from_base_10(all_your_base::to_base_10(in, in_digits), out);
}


unsigned int all_your_base::to_base_10(unsigned int in, std::vector<unsigned int> in_digits){
    int base10 = 0;
    for (size_t i = 0; i < in_digits.size(); i++){
        base10 *= in;
        base10 += in_digits[i];
    }
    return base10;
}


std::vector<unsigned int> all_your_base::from_base_10(unsigned int n, unsigned int base){
    std::vector<unsigned int> result;
    unsigned int temp = n;
    while(temp > 0){
        result.push_back(temp % base);
        temp /= base;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

