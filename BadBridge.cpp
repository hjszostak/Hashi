#include "BadBridge.h"

BadBridge::BadBridge( Direction d ) :
    isHorizontal_{ d == RIGHT || d == LEFT } {}

GridComponent* BadBridge::copy() const {
    return new BadBridge( *this );
}

bool BadBridge::isBlock( Direction d ) const {
    if ( isHorizontal_ && ( d == RIGHT || d == LEFT ) )
        return true;

    if ( !isHorizontal_ && ( d == UP || d == DOWN ) )
        return true;

    return false;
}

char BadBridge::toPrint() const {
    return ' ';
}

bool BadBridge::isHorizontal() const {
    return isHorizontal_;
}