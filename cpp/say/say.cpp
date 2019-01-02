#include "say.h"

std::string say::in_english(unsigned long long n){
  if (n < 20){
    return say::words_below_twenty[n];
  }
  else{
    return "";
  }
}


