#ifndef COMMANDLINE_VIDEOSTORE_CPP_RENTALRECORD_H
#define COMMANDLINE_VIDEOSTORE_CPP_RENTALRECORD_H


#include <string>
#include <vector>
#include "Rental.h"

class RentalRecord {
  std::string customerName;
  std::vector<Rental> rentals;
public:
  RentalRecord(std::string const& customerName, std::vector<Rental> rentals);
  std::vector<Rental> const& getRentals() const { return rentals; }
  std::string const& getCustomerName() const { return customerName; }

  double getTotalAmount() const;

  int getFrequentRenterPoints() const;
};


#endif //COMMANDLINE_VIDEOSTORE_CPP_RENTALRECORD_H
