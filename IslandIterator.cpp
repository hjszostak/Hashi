#include "IslandIterator.h"
#include "Grid.h"

IslandIterator::IslandIterator() :
    grid_{ 0 },
    end_{ true } {}

IslandIterator::IslandIterator( Grid* g ) :
    grid_{ g }
{
    if ( g == 0 ) {
        end_ = true;
        return;
    }

    for ( unsigned int x = 0; x < g->width_; x++ ) {
        for ( unsigned int y = 0; y < g->height_; y++ ) {
            if ( g->isIsland( Coordinate( x, y ) ) ) {
                c_ = Coordinate( x, y );
                end_ = false;
                return;
            }
        }
    }

    end_ = true;
}

IslandIterator::IslandIterator( const IslandIterator& ) = default;

bool IslandIterator::operator== ( const IslandIterator& other ) const {
    if ( end_ || other.end_ ) {
        return end_ == other.end_;
    }

    return grid_ == other.grid_ && c_ == other.c_;
}

bool IslandIterator::operator!= ( const IslandIterator& other ) const {
    return !( *this == other );
}

Coordinate IslandIterator::operator* () const {
    if ( end_ ) {
        return Coordinate();
    }

    return c_;
}

IslandIterator& IslandIterator::operator++ () {
    if ( end_ )
        return *this;

    if ( grid_->isValidCoordinate( Coordinate( c_.x(), c_.y() + 1 ) ) ) {
        for ( unsigned int y = c_.y() + 1; y < grid_->height_; y++ ) {
            if ( grid_->isIsland( Coordinate( c_.x(), y ) ) ) {
                c_ = Coordinate( c_.x(), y );
                return *this;
            }
        }
    }

    if ( !grid_->isValidCoordinate( Coordinate( c_.x() + 1, 0 ) ) ) {
        c_ = Coordinate();
        end_ = true;
        return *this;
    }

    for ( unsigned int x = c_.x() + 1; x < grid_->width_; x++ ) {
        for ( unsigned int y = 0; y < grid_->height_; y++ ) {
            if ( grid_->isIsland( Coordinate( x, y ) ) ) {
                c_ = Coordinate( x, y );
                return *this;
            }
        }
    }

    c_ = Coordinate();
    end_ = true;
    return *this;
}

IslandIterator IslandIterator::operator++ ( int ) {
    IslandIterator copy = IslandIterator( *this );
    ++(*this);

    return copy;
}