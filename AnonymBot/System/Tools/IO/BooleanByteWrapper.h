#ifndef BOOLEANBYTEWRAPPER_H
#define BOOLEANBYTEWRAPPER_H

#include "Public.h"

class BooleanByteWrapper
{
public:
    BooleanByteWrapper();
    static uint setFlag(uint param1, uint param2, bool param3);
    static bool getFlag(uint param1, uint param2);
};

#endif // BOOLEANBYTEWRAPPER_H
