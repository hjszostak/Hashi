#ifndef ISLAND_H
#define ISLAND_H

#include "GridComponent.h"

class Island : public GridComponent {
public:
    Island( Value );
    Island( const Island& );

    virtual GridComponent* copy() const;
    virtual Value value() const;
    virtual char toPrint() const;
    virtual bool isIsland() const;

private:
    Value value_;
};

#endif /* ISLAND_H */