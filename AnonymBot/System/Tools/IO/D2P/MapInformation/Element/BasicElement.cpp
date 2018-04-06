#include "BasicElement.h"

BasicElement::BasicElement(Reader *reader, Map *map, int cellId)
{
    uchar be = reader->readByte();

    switch (be)
    {
    case 2: {
        GraphicalElement ge(reader, map, cellId); }
        break;

    case 33: {
        SoundElement se(reader); }
        break;

    default:
        break;
    }
}
