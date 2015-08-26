#include "Coordinate.h"

Coordinate::Coordinate( unsigned int x, unsigned int y ) :
    x_{ x },
    y_{ y } {}

Coordinate::Coordinate( const Coordinate& c ) :
    x_{ c.x() },
    y_{ c.y() } {}

Coordinate& Coordinate::operator= ( const Coordinate& c ) {
    x_ = c.x();
    y_ = c.y();

    return *this;
}

bool Coordinate::operator== ( const Coordinate& c ) const {
    return x_ == c.x() && y_ == c.y();
}

bool Coordinate::operator!= ( const Coordinate& c ) const {
    return !( *this == c );
}

unsigned int Coordinate::x() const {
    return x_;
}

unsigned int Coordinate::y() const {
    return y_;
}