#ifndef ISLANDITERATOR_H
#define ISLANDITERATOR_H

#include "Coordinate.h"

class Grid;

// Iterates across islands in a grid
class IslandIterator {
public:
    IslandIterator();
    IslandIterator( Grid* );

    IslandIterator( const IslandIterator& );

    bool            operator==  ( const IslandIterator& )   const;
    bool            operator!=  ( const IslandIterator& )   const;
    Coordinate      operator*   ()                          const;
    IslandIterator& operator++  ();
    IslandIterator  operator++  ( int );

private:
    Grid* grid_;
    Coordinate c_;
    bool end_;
};

#endif /* ISLANDITERATOR_H */