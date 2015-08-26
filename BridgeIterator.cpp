#include "BridgeIterator.h"
#include "Grid.h"

BridgeIterator::BridgeIterator() :
    grid_ { 0 },
    end_ { true } {}

BridgeIterator::BridgeIterator( Grid* g, Coordinate c, Direction d ) :
    grid_{ g },
    d_{ d }
{
    if ( g == 0 ) {
        end_ = true;
        return;
    }

    if ( !grid_->isIsland( c ) ) {
        end_ = true;
        return;
    }

    int dx, dy;

    switch ( d_ ) {
        case UP:
            dx = 0;
            dy = -1;
            break;
        case RIGHT:
            dx = 1;
            dy = 0;
            break;
        case DOWN:
            dx = 0;
            dy = 1;
            break;
        case LEFT:
            dx = -1;
            dy = 0;
            break;
        default:
            end_ = true;
            return;
    }

    int x = dx + c.x();
    int y = dy + c.y();

    try {
        while ( x >= 0 && y >= 0 && !grid_->isIsland( Coordinate( x, y ) ) ) {
            x += dx;
            y += dy;
        }
    }
    catch ( Grid::BadCoordinate& e ) {
        end_ = true;
        return;
    }

    if ( x < 0 || y < 0 ) {
        end_ = true;
        return;
    }

    otherIsland_ = Coordinate( x, y );

    c_ = Coordinate( c.x() + dx, c.y() + dy );
    end_ = false;
}

BridgeIterator::BridgeIterator( const BridgeIterator& ) = default;

bool BridgeIterator::operator== ( const BridgeIterator& other ) const {
    if ( end_ || other.end_ ) {
        return end_ == other.end_;
    }

    return grid_ == other.grid_ && c_ == other.c_ && d_ == other.d_;
}

bool BridgeIterator::operator!= ( const BridgeIterator& other ) const {
    return !( *this == other );
}

Coordinate BridgeIterator::operator* () const {
    if ( end_ ) {
        return Coordinate();
    }

    return c_;
}

BridgeIterator& BridgeIterator::operator++ () {
    if ( end_ ) {
        return *this;
    }

    int dx, dy;

    switch ( d_ ) {
        case UP:
            dx = 0;
            dy = -1;
            break;
        case RIGHT:
            dx = 1;
            dy = 0;
            break;
        case DOWN:
            dx = 0;
            dy = 1;
            break;
        case LEFT:
            dx = -1;
            dy = 0;
        default:
            end_ = true;
            return *this;
    }

    int x = dx + c_.x();
    int y = dy + c_.y();

    if ( grid_->isIsland( Coordinate( x, y ) ) ) {
        c_ = Coordinate();
        end_ = true;
        return *this;
    }

    c_ = Coordinate( x, y );
    return *this;
}

BridgeIterator BridgeIterator::operator++ ( int ) {
    BridgeIterator copy = BridgeIterator( *this );
    ++( *this );

    return copy;
}

Coordinate BridgeIterator::otherIsland() const {
    return otherIsland_;
}