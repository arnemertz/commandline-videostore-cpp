#include "run.h"
#include <string>
#include <sstream>
#include <iostream>

/**
 * Simple pin-down test. Do not use this as an example for a good test ;-)
 */
int main() {
  using namespace std::literals;
  const std::string consoleInput =
      "John Doe\n"s +
      "0 1\n"s +
      "2 3\n"s +
      "6 1\n"s +
      "9 1\n"s +
      "10 2\n"s +
      "13 5\n"s +
      "\n"s;

  std::istringstream input{consoleInput};
  std::ostringstream output;
  run(input, output);

  const std::string& expected =
      "0: The Shawshank Redemption (1994)\n"s +
      "1: The Godfather (1972)\n"s +
      "2: The Godfather: Part II (1974)\n"s +
      "3: The Dark Knight (2008)\n"s +
      "4: Pulp Fiction (1994)\n"s +
      "5: The Good, the Bad and the Ugly (1966)\n"s +
      "6: The Lord of the Rings: The Return of the King (2003)\n"s +
      "7: Fight Club (1999)\n"s +
      "8: The Lord of the Rings: The Fellowship of the Ring (2001)\n"s +
                 "9: Interstellar (2014)\n"s +
                 "10: Whiplash (2014)\n"s +
                 "11: Birdman (2014)\n"s +
                 "12: Up (2009)\n"s +
                 "13: WALL·E (2008)\n"s +
      "Enter customer name: Choose movie by number followed by rental days, just ENTER for bill:\n"s +
      "Rental Record for John Doe\n"s +
      "\tThe Shawshank Redemption (1994)\t2.0\n"s +
      "\tThe Godfather: Part II (1974)\t3.5\n"s +
      "\tThe Lord of the Rings: The Return of the King (2003)\t1.5\n"s +
      "\tInterstellar (2014)\t3.0\n"s +
      "\tWhiplash (2014)\t6.0\n"s +
      "\tWALL·E (2008)\t4.5\n"s +
      "You owed 20.5\n"s +
      "You earned 7 frequent renter points\n"s;
  if (output.str() == expected) {
    std::cout << "1 Test passed\n";
  } else {
    std::cerr << "TEST FAILED! Expected: \n" << expected << "\n actual:\n" << output.str() << '\n';
  }
}


