#include "run.h"
#include <fstream>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>

void run(std::istream& in, std::ostream& out){
  using namespace std::literals;
  // read movies from file
  std::ifstream movieStream{"movies.csv"};
  std::map<int, std::vector<std::string>> movies{};
  for (std::string line; std::getline(movieStream, line);) {
    std::vector<std::string> movie;
    for (size_t first=0, last=0; last < line.length(); first=last+1) {
      last = line.find(';', first);
      movie.push_back(line.substr(first, last-first));
    }
    movies.insert(std::make_pair(std::stoi(movie[0]), movie));
    out << movie[0] << ": " << movie[1] << "\n";
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
    std::vector<std::string> rental;
    for (size_t first=0, last=0; last < input.length(); first=last+1) {
      last = input.find(' ', first);
      rental.push_back(input.substr(first, last-first));
    }
    std::vector<std::string> movie = movies[std::stoi(rental[0])];
    double thisAmount = 0;
    int daysRented = std::stoi(rental[1]);
    //determine amounts for rental
    if (movie[2] == "REGULAR") {
      thisAmount += 2;
      if (daysRented > 2)
        thisAmount += (daysRented - 2) * 1.5;
    } else if (movie[2] == "NEW_RELEASE") {
      thisAmount += daysRented * 3;
    } else if (movie[2] == "CHILDRENS") {
      thisAmount += 1.5;
      if (daysRented > 3)
        thisAmount += (daysRented - 3) * 1.5;
    }

    // add frequent renter points
    frequentRenterPoints++;
    // add bonus for a two day new release rental
    if (movie[2] == "NEW_RELEASE" && daysRented > 1) {
      frequentRenterPoints++;
    }
    // show figures for this rental
    result << "\t" << movie[1] + "\t" << thisAmount << "\n";
    totalAmount += thisAmount;
  }

  // add footer lines
  result << "You owed " << totalAmount << "\n";
  result << "You earned " << frequentRenterPoints << " frequent renter points\n";

  out << result.str();
}
