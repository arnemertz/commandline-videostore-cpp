#include "Rental.h"
#include "RegularRental.h"

RegularRental::RegularRental(Movie const& movie, int daysRented) : Rental(movie, daysRented) {}

int RegularRental::getFrequentRenterPoints() const {
  return 1;
}

double RegularRental::getAmount() const {
  double thisAmount = 2;
  if (daysRented > 2)
    thisAmount += (daysRented - 2) * 1.5;
  return thisAmount;
}