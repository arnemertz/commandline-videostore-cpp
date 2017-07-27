#include "run.h"
#include "Movie.h"
#include "Rental.h"
#include "MovieRepository.h"
#include "SplitString.h"
#include <iomanip>
#include <sstream>


void run(std::istream& in, std::ostream& out){
  using namespace std::literals;
  MovieRepository movieRepository;
  for (auto const& movie : movieRepository.getAll()) {
    out << movie.key << ": " << movie.name << "\n";
  }

  out << "Enter customer name: ";
  std::string customerName;
  getline(in, customerName);

  out << "Choose movie by number followed by rental days, just ENTER for bill:\n";
  double totalAmount = 0;
  int frequentRenterPoints = 0;
  std::ostringstream result;
  result << std::fixed << std::setprecision(1);
  result << "Rental Record for " + customerName + "\n";
  while (true) {
    std::string input;
    std::getline(in, input);
    if (input.empty()) {
      break;
    }

    std::vector<std::string> rentalData = split(input, ' ');
    auto key = std::stoi(rentalData[0]);
    Movie const& movie = movieRepository.getByKey(key);
    int daysRented = std::stoi(rentalData[1]);
    Rental rental(movie, daysRented);

    //determine amounts for rentaldouble thisAmount;
    double thisAmount = rental.getAmount();

    // add frequent renter points
    frequentRenterPoints += rental.getFrequentRenterPoints();
    // show figures for this rental
    result << "\t" << rental.getMovieName() + "\t" << thisAmount << "\n";
    totalAmount += thisAmount;
  }

  // add footer lines
  result << "You owed " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints << " frequent renter points\n";

  out << result.str();
}

