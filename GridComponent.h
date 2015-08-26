#ifndef GRIDCOMPONENT_H
#define GRIDCOMPONENT_H

#include "Types.h"

class GridComponent {
public:
    static GridComponent* create( ComponentType, Value = 0, Direction = DIRECTION_COUNT );

    virtual GridComponent* copy() const = 0;
    virtual Value value() const { return 0; };
    virtual bool isBlock( Direction ) const { return false; };
    virtual char toPrint() const = 0;
    virtual bool isIsland() const { return false; };
    virtual bool isHorizontal() const { return false; };
};

#endif /* GRIDCOMPONENT_H */