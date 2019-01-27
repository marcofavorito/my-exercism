#include "bracket_push.h"
#include <iostream>

uint8_t ROUND = 1;
uint8_t SQUARE = 2; 
uint8_t CURLY = 4; 
uint8_t CLOSED = 8;
uint8_t TYPE_MASK = 7;

std::string allowed_chars = "{[(}])";

uint8_t bracket_push::encode(char c){
    uint8_t result = 0;
    if      (c == '{') result |= CURLY;
    else if (c == '[') result |= SQUARE;
    else if (c == '(') result |= ROUND;
    else if (c == '}') result |= CURLY | CLOSED;
    else if (c == ']') result |= SQUARE | CLOSED;
    else if (c == ')') result |= ROUND | CLOSED;
    else throw std::domain_error("");
    return result;
}


bool bracket_push::check(std::string s){
    std::stack<uint8_t> stack{};
    for (unsigned int i = 0; i < s.length(); i++){
        char c = s.at(i);
        if (allowed_chars.find(c) == std::string::npos) continue;
        uint8_t encoded = bracket_push::encode(c);
        if (! (encoded & CLOSED)) stack.push(encoded);
        else if (stack.size() == 0) return false;
        else{
            uint8_t last = stack.top();
            if ((last & TYPE_MASK) == (encoded & TYPE_MASK)){
                stack.pop();
            }
            else{
                return false;
            }
        }
    }
    return stack.size() == 0;
}
