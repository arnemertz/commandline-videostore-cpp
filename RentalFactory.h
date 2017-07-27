#ifndef COMMANDLINE_VIDEOSTORE_CPP_RENTALFACTORY_H
#define COMMANDLINE_VIDEOSTORE_CPP_RENTALFACTORY_H


#include "MovieRepository.h"

class RentalFactory {
  MovieRepository const& movieRepository;
public:
  explicit RentalFactory(MovieRepository const& repository);
  Rental createRental(const std::string& input);
};



#endif //COMMANDLINE_VIDEOSTORE_CPP_RENTALFACTORY_H
