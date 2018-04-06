#pragma once

#include "System/Tools/IO/Reader.h"
#include "System/Tools/IO/D2P/MapInformation/Map.h"

#define FIXEDMAPCHANGER_GRAPHICAL_ID 34708

class GraphicalElement
{
public:
    GraphicalElement(Reader *reader, Map *map, int cellId);
};

