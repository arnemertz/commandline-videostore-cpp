#ifndef COMMANDLINE_VIDEOSTORE_CPP_NEWRELEASERENTAL_H
#define COMMANDLINE_VIDEOSTORE_CPP_NEWRELEASERENTAL_H


#include "Rental.h"

class NewReleaseRental : public Rental {
public:
  NewReleaseRental(Movie const& movie, int daysRented);

  int getFrequentRenterPoints() const override;

  double getAmount() const override;
};


#endif //COMMANDLINE_VIDEOSTORE_CPP_NEWRELEASERENTAL_H
