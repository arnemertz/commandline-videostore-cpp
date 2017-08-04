#ifndef COMMANDLINE_VIDEOSTORE_CPP_CONSOLE_H
#define COMMANDLINE_VIDEOSTORE_CPP_CONSOLE_H

#include <iosfwd>

class Console {
  std::istream& in;
  std::ostream& out;

public:
  Console(std::istream& in, std::ostream& out);

  void printRentalRecord(RentalRecord const& rentalRecord) const;
  std::vector<std::unique_ptr<Rental>> inputRentals(RentalFactory& rentalFactory);
  std::string inputCustomerName();
  void printMovies(std::vector<Movie> const& allMovies) const;
};

#endif //COMMANDLINE_VIDEOSTORE_CPP_CONSOLE_H
