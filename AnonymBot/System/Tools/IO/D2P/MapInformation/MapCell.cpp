#include "MapCell.h"

MapCell::MapCell(Reader *reader, Map *map)
{
    short cellId = reader->readShort();
    short elementcount = reader->readShort();

    for (int i = 0; i < elementcount; i++)
        BasicElement basicElement(reader, map, cellId);
}
