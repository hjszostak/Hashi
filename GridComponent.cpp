#include "GridComponent.h"
#include "EmptyComponent.h"
#include "Island.h"
#include "Bridge.h"
#include "BadBridge.h"

GridComponent* GridComponent::create( ComponentType type, Value value, Direction d ) {
    switch ( type ) {
        case EMPTY:
            return new EmptyComponent();
        case ISLAND:
            return new Island( value );
        case BRIDGE:
            return new Bridge( value, d );
        case BAD_BRIDGE:
            return new BadBridge( d );
        default:
            return 0;
    }
}