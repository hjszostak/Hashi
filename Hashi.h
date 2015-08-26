#ifndef HASHI_H
#define HASHI_H

#include <iostream>
#include "Grid.h"
#include "Coordinate.h"
#include "Types.h"

typedef unsigned int Value;

class Hashi {
    friend std::istream& operator>> ( std::istream&, Hashi& );
    friend std::ostream& operator<< ( std::ostream&, const Hashi& );

public:
    Hashi();
    Hashi( unsigned int, unsigned int );    // construct with dimensions
    ~Hashi();

    void addIsland( unsigned int, unsigned int, Value ); // add an island to the puzzle
    bool solve();

private:
    // Bridge methods
    bool addBridge( Coordinate, Direction, bool, Value = 0 );
    void removeBridge( Coordinate, Direction );
    Value currentIslandValue( Coordinate ) const;
    SolveStatus status() const;

    Grid* grid_;
};

std::istream& operator>> ( std::istream&, Hashi& );
std::ostream& operator<< ( std::ostream&, const Hashi& );


#endif /* HASHI_H */