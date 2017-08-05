#include "Rental.h"
#include "ChildrensRental.h"

ChildrensRental::ChildrensRental(Movie const& movie, int daysRented) : Rental(movie, daysRented) {}

int ChildrensRental::getFrequentRenterPoints() const {
  return 1;
}

double ChildrensRental::getAmount() const {
  double thisAmount = 0;
  thisAmount += 1.5;
  if (daysRented > 3)
    thisAmount += (daysRented - 3) * 1.5;
  return thisAmount;
}