#include "hamming.h"

int hamming::compute(std::string s1, std::string s2){
  if (s1.length() != s2.length())
    throw std::domain_error("The strings lengths are different.");
  int hamming_distance = 0;
  for (size_t i=0; i<s1.length(); i++){
    if (s1[i] != s2[i]){
      ++hamming_distance;
    }
  }
  return hamming_distance;
}

