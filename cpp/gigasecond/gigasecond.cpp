#include "gigasecond.h"

const boost::posix_time::ptime gigasecond::advance(const boost::posix_time::ptime p){
  boost::posix_time::ptime result = p + gigasecond::GIGASECOND;
  return result;
}

