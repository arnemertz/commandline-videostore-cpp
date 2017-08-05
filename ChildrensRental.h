#ifndef COMMANDLINE_VIDEOSTORE_CPP_CHILDRENSRENTAL_H
#define COMMANDLINE_VIDEOSTORE_CPP_CHILDRENSRENTAL_H


#include "Rental.h"

class ChildrensRental : public Rental {
public:
  ChildrensRental(Movie const& movie, int daysRented);

  int getFrequentRenterPoints() const override;

  double getAmount() const override;
};


#endif //COMMANDLINE_VIDEOSTORE_CPP_CHILDRENSRENTAL_H
