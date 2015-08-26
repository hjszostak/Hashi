#ifndef EMPTYCOMPONENT_H
#define EMPTYCOMPONENT_H

#include "GridComponent.h"

class EmptyComponent : public GridComponent {
public:
    EmptyComponent() {};

    virtual GridComponent* copy() const { return new EmptyComponent(); };
    virtual char toPrint() const { return ' '; };
};

#endif /* EMPTYCOMPONENT_H */