#include "reverse_string.h"

std::string reverse_string::reverse_string(std::string s){
  return std::string(s.rbegin(), s.rend());
}

