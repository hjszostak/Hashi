#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
public:
    explicit Coordinate( unsigned int = 0, unsigned int = 0 );
    Coordinate( const Coordinate& ); // copy constructor
    Coordinate& operator= ( const Coordinate& ); // copy assignment

    bool operator== ( const Coordinate& ) const;
    bool operator!= ( const Coordinate& ) const;

    unsigned int x() const;
    unsigned int y() const;

private:
    unsigned int x_;
    unsigned int y_;
};

#endif /* COORDINATE_H */