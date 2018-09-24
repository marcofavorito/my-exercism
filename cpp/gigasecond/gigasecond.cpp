#include "gigasecond.h"

seconds gigasecond::GIGASECOND = seconds(1000000000);

const ptime gigasecond::advance(const ptime p){
    ptime result = p + gigasecond::GIGASECOND;
    return result;
}