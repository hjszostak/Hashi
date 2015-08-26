#ifndef BADBRIDGE_H
#define BADBRIDGE_H

#include "GridComponent.h"

class BadBridge : public GridComponent {
public:
    BadBridge( Direction );

    virtual GridComponent* copy() const;
    virtual bool isBlock( Direction ) const;
    virtual char toPrint() const;
    virtual bool isHorizontal() const;

private:
    bool isHorizontal_;
};

#endif /* BADBRIDGE_H */