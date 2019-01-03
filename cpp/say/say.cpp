#include "say.h"
#include <iostream>

unsigned int nearest_power_of_10(unsigned long long n){
    return std::to_string(n).length() - 1;
}

std::string say::in_english(unsigned long long n){
  if (n < 20){
    return say::words_below_twenty[n];
  }
  else if (n >= 20 && n < 100) {
    return say::tens_words[n/10] + (n % 10 == 0? "": "-"+say::in_english(n % 10));
  }
  else if (n >= 100 && n < 1000ULL){
    return say::in_english(n/100) + " " + 
           say::tens_words[10] + 
           (n % 100 == 0? "": " " + say::in_english(n % 100));
  }
  else if (n >= 1000ULL && n < 1000ULL * 1000ULL * 1000ULL * 1000ULL){
    unsigned int power = nearest_power_of_10(n);
    unsigned long long magnitude = pow(10.0, power/3 * 3);
    return say::in_english(n / magnitude) + " " + 
           say::thousands_words[power/3] + 
           (n % magnitude == 0? "":  " " + say::in_english(n % magnitude));
    //return std::to_string(n) + " " + std::to_string(nearest_power_of_10(n));
  }
  else{
    throw std::domain_error("The number is negative or is above one trillion.");
  }
}


