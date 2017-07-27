#include "run.h"
#include "Movie.h"
#include "Rental.h"
#include "MovieRepository.h"
#include "RentalFactory.h"
#include "RentalRecord.h"
#include <iomanip>
#include <sstream>


std::vector<Rental> inputRentals(std::istream& in, RentalFactory& rentalFactory);

void run(std::istream& in, std::ostream& out){

  MovieRepository movieRepository;
  RentalFactory rentalFactory(movieRepository);

  for (auto const& movie : movieRepository.getAll()) {
    out << movie.key << ": " << movie.name << "\n";
  }

  out << "Enter customer name: ";
  std::string customerName;
  getline(in, customerName);

  out << "Choose movie by number followed by rental days, just ENTER for bill:\n";
  std::ostringstream result;
  result << std::fixed << std::setprecision(1);
  result << "Rental Record for " + customerName + "\n";

  std::vector<Rental> rentals = inputRentals(in, rentalFactory);
  RentalRecord rentalRecord(customerName, rentals);

  int frequentRenterPoints = rentalRecord.getFrequentRenterPoints();
  double totalAmount = rentalRecord.getTotalAmount();

  // show figures for each rental
  for (auto const& rental : rentalRecord.getRentals()) {
    result << "\t" << rental.getMovieName() + "\t" << rental.getAmount() << "\n";
  }

  // add footer lines
  result << "You owed " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints << " frequent renter points\n";

  out << result.str();
}

std::vector<Rental> inputRentals(std::istream& in, RentalFactory& rentalFactory) {
  std::vector<Rental> rentals;
  while (true) {
    std::string input;
    getline(in, input);
    if (input.empty()) {
      break;
    }

    Rental rental = rentalFactory.createRental(input);
    rentals.push_back(rental);
  }
  return rentals;
}

