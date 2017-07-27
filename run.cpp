#include "run.h"
#include "Movie.h"
#include "Rental.h"
#include "MovieRepository.h"
#include "RentalFactory.h"
#include <iomanip>
#include <sstream>


std::vector<Rental> inputRentals(std::istream& in, RentalFactory& rentalFactory);

int getFrequentRenterPoints(const std::vector<Rental>& rentals);

double getTotalAmount(const std::vector<Rental>& rentals);

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
  int frequentRenterPoints = getFrequentRenterPoints(rentals);
  double totalAmount = getTotalAmount(rentals);

  // show figures for each rental
  for (auto const& rental : rentals) {
    result << "\t" << rental.getMovieName() + "\t" << rental.getAmount() << "\n";
  }

  // add footer lines
  result << "You owed " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints << " frequent renter points\n";

  out << result.str();
}

double getTotalAmount(const std::vector<Rental>& rentals) {
  double totalAmount = 0;
  for (auto const& rental : rentals) {
    totalAmount += rental.getAmount();
  }
  return totalAmount;
}

int getFrequentRenterPoints(const std::vector<Rental>& rentals) {
  int frequentRenterPoints = 0;
  for (auto const& rental : rentals) {
    frequentRenterPoints += rental.getFrequentRenterPoints();
  }
  return frequentRenterPoints;
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

