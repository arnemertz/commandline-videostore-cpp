#include <iomanip>
#include "MovieRepository.h"
#include "Rental.h"
#include "Movie.h"
#include "run.h"
#include "RentalFactory.h"
#include "SplitString.h"


RentalFactory::RentalFactory(MovieRepository const& repository)
  : movieRepository{repository}
{

}

Rental RentalFactory::createRental(const std::string& input) {
  std::vector<std::string> rentalData = split(input, ' ');
  auto key = stoi(rentalData[0]);
  Movie const& movie = movieRepository.getByKey(key);
  int daysRented = stoi(rentalData[1]);
  return Rental{movie, daysRented};
}