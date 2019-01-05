#ifndef SERIES_H
#define SERIES_H

#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>

namespace series{
  std::vector<int> digits(std::string number);
  std::vector<std::vector<int>> slice(std::string number, unsigned int length);
}

#endif /* !SERIES_H */


