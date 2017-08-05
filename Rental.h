#ifndef COMMANDLINE_VIDEOSTORE_CPP_RENTAL_H
#define COMMANDLINE_VIDEOSTORE_CPP_RENTAL_H


#include "Movie.h"

class Rental {

protected:
  int daysRented;
  Movie const& movie;
public:
  Rental(const Movie& movie, int daysRented);
  Movie const& getMovie() const { return movie; }
  int getDaysRented() const { return daysRented; }

  const std::string& getMovieName() const;

  virtual int getFrequentRenterPoints() const = 0;

  virtual double getAmount() const = 0;

};


#endif //COMMANDLINE_VIDEOSTORE_CPP_RENTAL_H
