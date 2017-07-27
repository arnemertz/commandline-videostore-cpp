#ifndef COMMANDLINE_VIDEOSTORE_CPP_MOVIEREPOSITORY_H
#define COMMANDLINE_VIDEOSTORE_CPP_MOVIEREPOSITORY_H


#include <map>
#include <vector>
#include "Movie.h"

class MovieRepository {
  std::map<int, Movie> movies;

public:
  MovieRepository();

  const Movie& getByKey(int key) const;
  std::vector<Movie> getAll() const;
};


#endif //COMMANDLINE_VIDEOSTORE_CPP_MOVIEREPOSITORY_H
