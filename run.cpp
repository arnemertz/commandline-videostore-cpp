#include "run.h"
#include "Movie.h"
#include "Rental.h"
#include "MovieRepository.h"
#include "RentalFactory.h"
#include "RentalRecord.h"
#include "Console.h"

void run(std::istream& in, std::ostream& out){
  Console console(in, out);
  MovieRepository movieRepository;
  RentalFactory rentalFactory(movieRepository);

  std::vector<Movie> const& allMovies = movieRepository.getAll();
  console.printMovies(allMovies);

  auto customerName = console.inputCustomerName();
  auto rentals = console.inputRentals(rentalFactory);

  RentalRecord rentalRecord(customerName, std::move(rentals));
  console.printRentalRecord(rentalRecord);
}

