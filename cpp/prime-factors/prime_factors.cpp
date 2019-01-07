#include "prime_factors.h"

std::vector<int> prime_factors::of(unsigned int n){
  std::vector<int> result;
  unsigned int temp = n;
  unsigned int p;

  while (temp %  2 == 0){
    temp /= 2;
    result.push_back(2);
  }

  double n_sqrt = sqrt(n);
  for (p = 3; p <= n_sqrt; p+=2){
    while (temp % p == 0){
      result.push_back(p);
      temp /= p;
    }
  }
  
  if (temp > 2){
    result.push_back(temp);
  }

  return result;
}

