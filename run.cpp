#include "run.h"
#include "Movie.h"
#include "Rental.h"
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>


std::vector<std::string> split(const std::string& str, char delimiter);

void run(std::istream& in, std::ostream& out){
  using namespace std::literals;
  // read movies from file
  std::ifstream movieStream{"movies.csv"};
  std::map<int, Movie> movies{};
  for (std::string line; std::getline(movieStream, line);) {
    std::vector<std::string> movieData = split(line, ';');
    int key = std::stoi(movieData[0]);
    Movie movie{key, movieData[1], movieData[2]};
    movies.insert(std::make_pair(key, movie));
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
    Movie const& movie = movies[key];
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

std::vector<std::string> split(const std::string& str, char delimiter) {
  std::vector<std::string> strings;
  for (size_t first=0, last=0; last < str.length(); first=last+1) {
    last = str.find(delimiter, first);
    strings.push_back(str.substr(first, last-first));
  }
  return strings;
}
