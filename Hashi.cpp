#include "Hashi.h"
#include <string>

using namespace std;

Hashi::Hashi() {}

Hashi::Hashi( unsigned int, unsigned int ) {}

Hashi::~Hashi() {}

void Hashi::addIsland( unsigned int x, unsigned int y, Value value ) {
    if ( grid_ )
        grid_->setComponent( ISLAND, Coordinate( x, y ), value );
}

bool Hashi::solve() {
    SolveStatus curStatus = status();

    if ( curStatus == SOLVED )
        return true;

    if ( curStatus == UNSOLVABLE )
        return false;

    Grid state = Grid( *grid_ );

    for ( auto it = grid_->beginIsland(); it != grid_->endIsland(); ++it ) {
        Coordinate c = *it;
        for ( Direction d = UP; d == UP || d == RIGHT; d = Direction( d + 1 ) ) {
            if ( !addBridge( c, d, false, 1 ) )
                continue;

            if ( solve() )
                return true;

            removeBridge( c, d );

            if ( !addBridge( c, d, false, 2 ) ) {
                addBridge( c, d, true );
                continue;
            }

            if ( solve() )
                return true;

            removeBridge( c, d );

            addBridge( c, d, true );
        }
    }

    delete grid_;
    grid_ = new Grid( state );

    return false;
}

// assuming the input is valid
istream& operator>> ( istream& sin, Hashi& h ) {
    unsigned int width, height;
    sin >> width >> height;

    if ( width == 0 || height == 0 ) {
        // TODO: throw input error
        return sin;
    }

    h.grid_ = new Grid( width, height );

    string line;
    // clear current line
    getline( sin, line );

    for ( unsigned int i = 0; i < height; i++ ) {
        getline( sin, line );
        for ( unsigned int j = 0; j < line.length(); j++ ) {
            if ( line[ j ] >= '1' && line[ j ] <= '8' ) {
                h.addIsland( j, i, line[ j ] - '0' );
            }
        }
    }

    return sin;
}

bool Hashi::addBridge( Coordinate c, Direction d, bool isBad, Value value ) {
    if ( grid_->beginBridge( c, d ) == grid_->endBridge() )
        return false;

    for ( auto it = grid_->beginBridge( c, d ); it != grid_->endBridge(); ++it ) {
        if ( grid_->isBlock( *it, d ) )
            return false;
    }

    Coordinate otherIsland = grid_->beginBridge( c, d ).otherIsland();

    // if one of the islands does not have the enough spaces
    // for the bridge, don't add it
    if ( !isBad ) {
        if ( currentIslandValue( c ) + value > grid_->value( c ) )
            return false;
        if ( currentIslandValue( otherIsland ) + value > grid_->value( otherIsland ) )
            return false;
    }

    for ( auto it = grid_->beginBridge( c, d ); it != grid_->endBridge(); ++it ) {
        if ( isBad )
            grid_->setComponent( BAD_BRIDGE, *it, 0, d );
        else
            grid_->setComponent( BRIDGE, *it, value, d );
    }

    return true;
}

void Hashi::removeBridge( Coordinate c, Direction d ) {
    for ( auto it = grid_->beginBridge( c, d ); it != grid_->endBridge(); ++it ) {
        grid_->setComponent( EMPTY, *it );
    }
}

Value Hashi::currentIslandValue( Coordinate c ) const {
    // TODO: check for bad input

    unsigned toReturn = 0;

    for ( Direction d = UP; d != DIRECTION_COUNT; d = Direction( d + 1 ) ) {
        auto it = grid_->beginBridge( c, d );
        if ( it == grid_->endBridge() )
            continue;

        bool isHorizontal = d == RIGHT || d == LEFT;

        if ( !isHorizontal xor grid_->isHorizontal( *it ) )
            toReturn += grid_->value( *it );
    }

    return toReturn;
}

SolveStatus Hashi::status() const {
    for ( auto it = grid_->beginIsland(); it != grid_->endIsland(); ++it ) {
        unsigned int numBridges = 0;
        for ( Direction d = Direction( 0 ); d != DIRECTION_COUNT; d = Direction( d + 1 ) ) {
            // skip if no other island
            if ( grid_->beginBridge( *it, d ) == grid_->endBridge() ) {
                continue;
            }

            // skip if link is blocked
            auto cur = grid_->beginBridge( *it, d );
            while ( cur != grid_->endBridge() ) {
                if ( grid_->isBlock( *cur, d ) )
                    break;
                ++cur;
            }

            if ( cur != grid_->endBridge() )
                continue;

            Coordinate c = grid_->beginBridge( *it, d ).otherIsland();
            numBridges += min( ( unsigned int ) 2, grid_->value( c ) - currentIslandValue( c ) );
        }

        if ( numBridges < grid_->value( *it ) - currentIslandValue( *it ) )
            return UNSOLVABLE;
    }

    for ( auto it = grid_->beginIsland(); it != grid_->endIsland(); ++it ) {
        if ( currentIslandValue( *it ) != grid_->value( *it ) )
            return UNSOLVED;
    }

    // TODO: make sure islands aren't in seperate groups

    return SOLVED;
}

ostream& operator<< ( ostream& sout, const Hashi& h ) {
    if ( NULL != h.grid_ )
        sout << *( h.grid_ );
    return sout;
}  