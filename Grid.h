#ifndef GRID_H
#define GRID_H

#include "GridComponent.h"
#include "Coordinate.h"
#include "Types.h"
#include <ostream>
#include "IslandIterator.h"
#include "BridgeIterator.h"

class Grid {
    friend std::ostream& operator<< ( std::ostream&, const Grid& );
    friend class IslandIterator;
public:
    Grid( unsigned int, unsigned int );
    Grid( const Grid& );
    ~Grid();

    // Wrapper to component methods
    // Used to verify coordinates
    void setComponent( ComponentType, Coordinate, Value = 0, Direction = DIRECTION_COUNT );
    Value value( Coordinate ) const;
    bool isBlock( Coordinate, Direction ) const;
    char toPrint( Coordinate ) const;
    bool isIsland( Coordinate ) const;
    bool isHorizontal( Coordinate ) const;

    // Iterators
    IslandIterator beginIsland() const;
    IslandIterator endIsland() const;
    BridgeIterator beginBridge( Coordinate, Direction ) const;
    BridgeIterator endBridge() const;

    // Errors
    class BadCoordinate {
    public:
        BadCoordinate( Coordinate );
        Coordinate coordinate() const;

    private:
        Coordinate c_;
    };

    class BadDimensions {
    public:
        BadDimensions( unsigned int, unsigned int );
        unsigned int width() const;
        unsigned int height() const;

    private:
        unsigned int width_;
        unsigned int height_;
    };

private:
    unsigned int width_, height_;
    GridComponent*** components_;

    GridComponent* getComponent( Coordinate ) const;
    void setComponent( Coordinate, GridComponent* );
    bool isValidCoordinate( Coordinate ) const;
};

std::ostream& operator<< ( std::ostream&, const Grid& );

#endif /* GRID_H */