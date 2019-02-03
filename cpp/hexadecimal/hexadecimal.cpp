#include "hexadecimal.h"

int hexadecimal::convert(std::string n){
    std::string reversed_n = n; 
    int result = 0;
    int temp = 0;
    for (unsigned int i = 0; i < n.length(); i++){
        char c = n[i];
        if (c >= 48 && c < 58)
            result += (c - 48);
        else if (c >= 97 && c < 103)
            result += (c - 97 + 10);
        else
            return 0;
        if (i != n.length() - 1)
            result *= 16;
    }
    return result;
}

