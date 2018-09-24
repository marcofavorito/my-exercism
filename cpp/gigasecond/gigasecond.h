#include "boost/date_time/posix_time/posix_time_types.hpp"
using namespace boost::posix_time;

class gigasecond{
    public:
      static seconds GIGASECOND;
      static const ptime advance(const ptime p);
};