#ifndef COMMANDLINE_VIDEOSTORE_CPP_REGULARRENTAL_H
#define COMMANDLINE_VIDEOSTORE_CPP_REGULARRENTAL_H


#include "Rental.h"

class RegularRental : public Rental {
public:
  RegularRental(Movie const& movie, int daysRented);

  int getFrequentRenterPoints() const override;

  double getAmount() const override;
};


#endif //COMMANDLINE_VIDEOSTORE_CPP_REGULARRENTAL_H
