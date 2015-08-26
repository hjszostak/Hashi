#ifndef BRIDGEITERATOR_H
#define BRIDGEITERATOR_H

#include "Coordinate.h"
#include "Types.h"

class Grid;

// Iterator across coordinates in a possible bridge
class BridgeIterator {
public:
    BridgeIterator();
    BridgeIterator( Grid*, Coordinate, Direction );

    BridgeIterator( const BridgeIterator& );

    bool            operator== ( const BridgeIterator& )    const;
    bool            operator!= ( const BridgeIterator& )    const;
    Coordinate      operator* ()                                    const;
    BridgeIterator& operator++ ();
    BridgeIterator  operator++ ( int );

    Coordinate otherIsland() const;

private:
    Grid* grid_;
    Coordinate c_;
    Coordinate otherIsland_;
    Direction d_;
    bool end_;
};

#endif /* BRIDGEITERATOR_H */