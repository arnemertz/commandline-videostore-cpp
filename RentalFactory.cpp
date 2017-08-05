#include <iomanip>
#include "MovieRepository.h"
#include "Rental.h"
#include "Movie.h"
#include "run.h"
#include "RentalFactory.h"
#include "SplitString.h"
#include "RegularRental.h"
#include "NewReleaseRental.h"
#include "ChildrensRental.h"


RentalFactory::RentalFactory(MovieRepository const& repository)
  : movieRepository{repository}
{

}

std::unique_ptr<Rental> RentalFactory::createRental(const std::string& input) {
  std::vector<std::string> rentalData = split(input, ' ');
  auto key = stoi(rentalData[0]);
  Movie const& movie = movieRepository.getByKey(key);
  int daysRented = stoi(rentalData[1]);

  auto const& category = movie.category;
  if (category == "REGULAR") {
    return std::make_unique<RegularRental>(movie, daysRented);
  } else if (category == "NEW_RELEASE") {
    return std::make_unique<NewReleaseRental>(movie, daysRented);
  } else if (category == "CHILDRENS") {
    return std::make_unique<ChildrensRental>(movie, daysRented);
  }

  throw std::logic_error("unknown category: " + category);
}