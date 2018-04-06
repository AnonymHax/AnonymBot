#include "Layer.h"

Layer::Layer(Reader *reader, Map *map)
{
    int layerId;

    if(map->getMapVersion() >= 9)
        layerId = reader->readByte();

    else
        layerId = reader->readInt();

    short cellcount = reader->readShort();

    for (int i = 0; i < cellcount; i++)
        MapCell mapCell(reader, map);
}

