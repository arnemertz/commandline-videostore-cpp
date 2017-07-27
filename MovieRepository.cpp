#include "SplitString.h"
#include "Movie.h"
#include "MovieRepository.h"
#include <algorithm>
#include <fstream>


MovieRepository::MovieRepository() {
  std::ifstream movieStream{"movies.csv"};
  for (std::string line; getline(movieStream, line);) {
    std::vector<std::string> movieData = split(line, ';');
    int key = stoi(movieData[0]);
    Movie movie{key, movieData[1], movieData[2]};
    movies.insert(std::make_pair(key, movie));
  }
}

Movie const& MovieRepository::getByKey(int key) const {
  return movies.find(key)->second;
}

std::vector<Movie> MovieRepository::getAll() const {
  std::vector<Movie> allMovies;
  allMovies.reserve(movies.size());
  std::transform(movies.begin(), movies.end(), back_inserter(allMovies), [](auto const& pair) { return pair.second; });
  return allMovies;
}


