#include "sieve.h"
#include <iostream>
std::vector<int> sieve::primes(unsigned int n){

  std::set<int> primes;
  for (unsigned int x = 2; x < n; x++){
    primes.insert(x);
  }

  auto start = primes.begin();
  while (start != primes.end()){
    unsigned int p = *start;
    auto it = start;
    ++it;
    while (it != primes.end()){
      if (*it % p == 0){
        primes.erase(it);
      }
      ++it;
      
    }
    ++start;
  }

  return std::vector<int>(primes.begin(), primes.end());
}

