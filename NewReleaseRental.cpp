#include "Rental.h"
#include "NewReleaseRental.h"

NewReleaseRental::NewReleaseRental(Movie const& movie, int daysRented) : Rental(movie, daysRented) {}

int NewReleaseRental::getFrequentRenterPoints() const {
  int rentalFrequentRentalPoints = 1;
  if (getDaysRented() > 1) {
    rentalFrequentRentalPoints++;
  }
  return rentalFrequentRentalPoints;
}

double NewReleaseRental::getAmount() const {
  return daysRented * 3;
}