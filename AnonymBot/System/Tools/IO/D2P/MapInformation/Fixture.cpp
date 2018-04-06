#include "Fixture.h"

Fixture::Fixture(Reader *reader)
{
    int fixturid = reader->readInt();
    short offsetx = reader->readShort();
    short offsety = reader->readShort();
    short rotation = reader->readShort();
    short xscale = reader->readShort();
    short yscale = reader->readShort();
    uchar redmultiplier = reader->readByte();
    uchar greenmultiplier = reader->readByte();
    uchar bluemultiplier = reader->readByte();
    uchar alpha = reader->readByte();
}

