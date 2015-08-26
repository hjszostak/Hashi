#include "Bridge.h"

Bridge::Bridge( Value value, Direction d ) :
    value_{ value },
    isHorizontal_{ d == RIGHT || d == LEFT } {}

GridComponent* Bridge::copy() const {
    return new Bridge( *this );
}

Value Bridge::value() const {
    return value_;
}

bool Bridge::isBlock( Direction ) const {
    return true;
}

char Bridge::toPrint() const {
    if ( isHorizontal_ ) {
        if ( value_ == 1 )
            return '-';
        if ( value_ == 2 )
            return '=';
    }
    else {
        if ( value_ == 1 )
            return '|';
        if ( value_ == 2 )
            return 'H';
    }

    return ' ';
}

bool Bridge::isHorizontal() const {
    return isHorizontal_;
}