#include "Grid.h"

using namespace std;

Grid::Grid( unsigned int width, unsigned int height ) :
    width_{ width },
    height_{ height } {
    if ( width == 0 || height == 0 )
        throw BadDimensions( width, height );
    
    components_ = new GridComponent**[ width_ ];
    for ( unsigned int i = 0; i < width; i++ ) {
        components_[ i ] = new GridComponent*[ height_ ];

        for ( unsigned int j = 0; j < height_; j++ ) {
            components_[ i ][ j ] = GridComponent::create( EMPTY );
        }
    }
}

Grid::Grid( const Grid& other ) :
    width_{ other.width_ },
    height_{ other.height_ } {
    components_ = new GridComponent**[ width_ ];
    for ( unsigned int i = 0; i < width_; i++ ) {
        components_[ i ] = new GridComponent*[ height_ ];

        for ( unsigned int j = 0; j < height_; j++ ) {
            components_[ i ][ j ] = other.components_[ i ][ j ]->copy();
        }
    }
}

Grid::~Grid() {
    for ( unsigned int i = 0; i < width_; i++ ) {
        for ( unsigned int j = 0; j < height_; j++ ) {
            delete components_[ i ][ j ];
        }
        delete components_[ i ];
    }
    delete components_;
}

void Grid::setComponent( ComponentType type, Coordinate c, Value value, Direction d ) {
    if ( !isValidCoordinate( c ) )
        throw BadCoordinate( c );

    delete getComponent( c );
    components_[ c.x() ][ c.y() ] = GridComponent::create( type, value, d );
}

Value Grid::value( Coordinate c ) const {
    return getComponent( c )->value();
}

bool Grid::isBlock( Coordinate c, Direction d ) const {
    return getComponent( c )->isBlock( d );
}

char Grid::toPrint( Coordinate c ) const {
    return getComponent( c )->toPrint();
}

bool Grid::isIsland( Coordinate c ) const {
    return getComponent( c )->isIsland();
}

bool Grid::isHorizontal( Coordinate c ) const {
    return getComponent( c )->isHorizontal();
}

IslandIterator Grid::beginIsland() const {
    return IslandIterator( const_cast<Grid*>( this ) );
}

IslandIterator Grid::endIsland() const {
    return IslandIterator();
}

BridgeIterator Grid::beginBridge( Coordinate c, Direction d ) const {
    return BridgeIterator( const_cast<Grid*>( this ), c, d );
}

BridgeIterator Grid::endBridge() const {
    return BridgeIterator();
}

Grid::BadCoordinate::BadCoordinate( Coordinate c ) :
    c_{ c } {}

Coordinate Grid::BadCoordinate::coordinate() const {
    return c_;
}

Grid::BadDimensions::BadDimensions( unsigned int width, unsigned int height ) :
    width_{ width },
    height_{ height } {}

unsigned int Grid::BadDimensions::width() const {
    return width_;
}

unsigned int Grid::BadDimensions::height() const {
    return height_;
}

GridComponent* Grid::getComponent( Coordinate c ) const {
    if ( !isValidCoordinate( c ) )
        throw BadCoordinate( c );

    return components_[ c.x() ][ c.y() ];
}

void Grid::setComponent( Coordinate c, GridComponent* gc ) {
    if ( !isValidCoordinate( c ) )
        throw BadCoordinate( c );

    components_[ c.x() ][ c.y() ] = gc;
}

bool Grid::isValidCoordinate( Coordinate c ) const {
    return c.x() < width_ && c.y() < height_;
}

ostream& operator<< ( ostream& sout, const Grid& g ) {
    for ( unsigned int y = 0; y < g.height_; y++ ) {
        for ( unsigned int x = 0; x < g.width_; x++ ) {
            sout << g.toPrint( Coordinate( x, y ) );
        }
        sout << endl;
    }
    return sout;
}