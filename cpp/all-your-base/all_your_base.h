#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <vector>
#include <algorithm>

namespace all_your_base{
    std::vector<unsigned int> convert(
        unsigned int in,
        std::vector<unsigned int> in_digits,
        unsigned int out
    );

    unsigned int to_base_10(unsigned int in, std::vector<unsigned int> in_digits);
    std::vector<unsigned int> from_base_10(unsigned int n, unsigned int base);
}

#endif /* !ALL_YOUR_BASE_H */ 

