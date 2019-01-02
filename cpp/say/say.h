#ifndef SAY_H
#define SAY_H

#include <unordered_map>
#include <string>

namespace say{
  const std::string words_below_twenty[] {
    "zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine", "ten", 
    "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"
  };
  std::string in_english(unsigned long long n);
}

#endif /* !SAY_H */


