#ifndef COMMANDLINE_VIDEOSTORE_CPP_RENTALRECORD_H
#define COMMANDLINE_VIDEOSTORE_CPP_RENTALRECORD_H


#include <string>
#include <vector>
#include "Rental.h"

class RentalRecord {
  std::string customerName;
  std::vector<std::unique_ptr<Rental>> rentals;
public:
  RentalRecord(std::string const& customerName, std::vector<std::unique_ptr<Rental>> rentals);
  std::vector<std::unique_ptr<Rental>> const& getRentals() const { return rentals; }
  std::string const& getCustomerName() const { return customerName; }

  double getTotalAmount() const;

  int getFrequentRenterPoints() const;
};


#endif //COMMANDLINE_VIDEOSTORE_CPP_RENTALRECORD_H
