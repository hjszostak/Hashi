#ifndef TYPES_H
#define TYPES_H

enum Direction { UP, RIGHT, DOWN, LEFT, DIRECTION_COUNT };
enum ComponentType { EMPTY, ISLAND, BRIDGE, BAD_BRIDGE,
                     MAX_COMPONENT_TYPE };
enum SolveStatus { SOLVED, UNSOLVED, UNSOLVABLE };
typedef unsigned int Value;

#endif