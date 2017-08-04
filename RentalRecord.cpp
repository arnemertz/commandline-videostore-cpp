#include <iomanip>
#include "MovieRepository.h"
#include "Rental.h"
#include "Movie.h"
#include "run.h"
#include "RentalRecord.h"

double getTotalAmount(const std::vector<Rental>& rentals);

int getFrequentRenterPoints(const std::vector<Rental>& rentals);

RentalRecord::RentalRecord(std::string const& customerName, std::vector<std::unique_ptr<Rental>> rentals)
  : customerName(customerName)
  , rentals(std::move(rentals))
{
}

double RentalRecord::getTotalAmount() const {
  double totalAmount = 0;
  for (auto const& rental : rentals) {
    totalAmount += rental->getAmount();
  }
  return totalAmount;
}

int RentalRecord::getFrequentRenterPoints() const {
  int frequentRenterPoints = 0;
  for (auto const& rental : rentals) {
    frequentRenterPoints += rental->getFrequentRenterPoints();
  }
  return frequentRenterPoints;
}