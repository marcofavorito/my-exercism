#include "series.h"
#include <iostream>
#include <iterator>

std::vector<int> series::digits(std::string number){
  auto result = std::vector<int>();
  std::transform(number.begin(), number.end(), std::back_inserter(result),
                        [](unsigned char c) -> int {return c - '0';});
  return result;
}

std::vector<std::vector<int>> series::slice(std::string number, unsigned int length){
  if (length > number.length()){
    throw std::domain_error("");
  }
  auto number_digits = series::digits(number);
  auto result = std::vector<std::vector<int>>();
  std::vector<int> current_slice;
  auto start = number_digits.begin();  
  auto end = start + length;
  while(end != number_digits.end() + 1){
    current_slice = std::vector<int>(start, end);
    result.push_back(current_slice);
    ++start;
    ++end;
  }

  return result;
}

