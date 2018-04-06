#pragma once

#include "System/Tools/IO/Reader.h"
#include "GraphicalElement.h"
#include "SoundElement.h"

class BasicElement
{
public:
    BasicElement(Reader *reader, Map *map, int cellId);
};
