#include "Movie.h"
#include "Rental.h"


Rental::Rental(const Movie& movie, int daysRented)
    : movie{movie}, daysRented{daysRented} {
}

int Rental::getFrequentRenterPoints() const {
  int rentalFrequentRentalPoints = 1;
  // add bonus for a two day new release rental
  if (getMovie().category == "NEW_RELEASE" && getDaysRented() > 1) {
    rentalFrequentRentalPoints++;
  }
  return rentalFrequentRentalPoints;
}

const std::string& Rental::getMovieName() const { return getMovie().name; }

double Rental::getAmount() const {
  double thisAmount = 0;
  const std::string& category = movie.category;
  if (category == "REGULAR") {
    thisAmount += 2;
    if (daysRented > 2)
      thisAmount += (daysRented - 2) * 1.5;
  } else if (category == "NEW_RELEASE") {
    thisAmount += daysRented * 3;
  } else if (category == "CHILDRENS") {
    thisAmount += 1.5;
    if (daysRented > 3)
      thisAmount += (daysRented - 3) * 1.5;
  }
  return thisAmount;
}