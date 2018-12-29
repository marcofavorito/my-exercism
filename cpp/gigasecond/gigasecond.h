#ifndef GIGASECOND_H 
#define GIGASECOND_H

#include <boost/date_time/posix_time/posix_time.hpp>

namespace gigasecond{
  const auto GIGASECOND = boost::posix_time::seconds(1e9);
  const boost::posix_time::ptime advance(const boost::posix_time::ptime p);
};

#endif 

