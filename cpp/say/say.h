#ifndef SAY_H
#define SAY_H

#include <unordered_map>
#include <cmath>
#include <string>

namespace say{
  const std::string words_below_twenty[] {
    "zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten", 
    "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"
  };

  const std::string tens_words[] {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety",
    "hundred"
  };
  
  const std::string thousands_words[] {
    "", "thousand", "million", "billion"
  };

  std::string in_english(unsigned long long n);
}

#endif /* !SAY_H */


