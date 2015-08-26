#ifndef BRIDGE_H
#define BRIDGE_H

#include "GridComponent.h"

class Bridge : public GridComponent {
public:
    Bridge( Value, Direction );

    virtual GridComponent* copy() const;
    virtual Value value() const;
    virtual bool isBlock( Direction ) const;
    virtual char toPrint() const;
    virtual bool isHorizontal() const;

private:
    Value value_;
    bool isHorizontal_;
};

#endif /* BRIDGE_H */