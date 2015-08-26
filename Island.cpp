#include "Island.h"
#include <cassert>

Island::Island( Value value ) : GridComponent(),
    value_{ value } {
    assert( value_ >= 0 && value_ <= 8 );
}

Island::Island( const Island& ) = default;

GridComponent* Island::copy() const {
    return new Island( *this );
}

Value Island::value() const {
    return value_;
}

char Island::toPrint() const {
    return '0' + value_;
}

bool Island::isIsland() const {
    return true;
}