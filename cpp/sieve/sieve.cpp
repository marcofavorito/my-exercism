#include "sieve.h"

std::vector<int> sieve::primes(unsigned int n){
  std::set<int> primes;
  for (int x = 2; x < n; x++){
    primes.insert(x);
  }

  auto start = primes.begin();
  while (start != primes.end()){
    int p = *start;
    auto it = start + 1;
    while (it != primes.end()){
      if (*it % p == 0){
        primes.erase(it);
      }
      else{
        ++it;
      }
      
    }
  }

  return std::vector<int>(primes.begin(), primes.end());
}

