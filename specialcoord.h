#ifndef SPECIALCOORD_H
#define SPECIALCOORD_H
#include "coords.h"
class SpecialCoord: public Coords {
    protected:
    Coords coords;
    public:
    virtual Coords getCoords() = 0;
};

#endif