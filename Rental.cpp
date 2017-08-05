#include "Movie.h"
#include "Rental.h"


Rental::Rental(const Movie& movie, int daysRented)
    : movie{movie}, daysRented{daysRented} {
}

const std::string& Rental::getMovieName() const { return getMovie().name; }

