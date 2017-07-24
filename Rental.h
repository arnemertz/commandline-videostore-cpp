#ifndef COMMANDLINE_VIDEOSTORE_CPP_RENTAL_H
#define COMMANDLINE_VIDEOSTORE_CPP_RENTAL_H


#include "Movie.h"

class Rental {
  Movie const& movie;
  int daysRented;

public:
  Rental(const Movie& movie, int daysRented);
  Movie const& getMovie() const { return movie; }
  int getDaysRented() const { return daysRented; }
};


#endif //COMMANDLINE_VIDEOSTORE_CPP_RENTAL_H
