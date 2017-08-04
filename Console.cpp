#include <iostream>
#include <iomanip>
#include "RentalRecord.h"
#include "RentalFactory.h"
#include "Rental.h"
#include "Movie.h"
#include "Console.h"


Console::Console(std::istream& in, std::ostream& out)
    : in(in), out(out)
{
  out << std::fixed << std::setprecision(1);
}

void Console::printRentalRecord(RentalRecord const& rentalRecord) const {
  out << "Rental Record for " + rentalRecord.getCustomerName() + "\n";
  // show figures for each rental
  for (auto const& rental : rentalRecord.getRentals()) {
    out << "\t" << rental->getMovieName() + "\t" << rental->getAmount() << "\n";
  }

  // add footer lines
  double totalAmount = rentalRecord.getTotalAmount();
  out << "You owed " << totalAmount << "\n";
  int frequentRenterPoints = rentalRecord.getFrequentRenterPoints();
  out << "You earned " << frequentRenterPoints << " frequent renter points\n";
}

std::vector<std::unique_ptr<Rental>> Console::inputRentals(RentalFactory& rentalFactory) {
  out << "Choose movie by number followed by rental days, just ENTER for bill:\n";
  std::vector<std::unique_ptr<Rental>> rentals;
  while (true) {
    std::string input;
    getline(in, input);
    if (input.empty()) {
      break;
    }

    auto rental = rentalFactory.createRental(input);
    rentals.push_back(std::move(rental));
  }
  return rentals;
}

std::string Console::inputCustomerName() {
  std::string customerName;
  out << "Enter customer name: ";
  getline(in, customerName);
  return customerName;
}

void Console::printMovies(std::vector<Movie> const& allMovies) const {
  for (auto const& movie : allMovies) {
    out << movie.key << ": " << movie.name << "\n";
  }
}