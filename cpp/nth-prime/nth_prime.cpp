#include "nth_prime.h"


unsigned int prime::nth(unsigned int n){
    if (n <= 0) throw std::domain_error("The number must be greater than 0.");
    std::vector<unsigned int> primes = std::vector<unsigned int>();
    unsigned int i = 2;
    bool isAPrime = true;
    while (primes.size() != n){
        for (unsigned int prime : primes){
            if (i % prime == 0){
                isAPrime = false;
                break;
            }
            if (prime > sqrt(i)) break;
        }
        if (isAPrime)
            primes.push_back(i);

        //reset the cycle
        ++i;
        isAPrime = true;
    }
    return primes[primes.size() - 1];
}

