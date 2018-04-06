#include "SoundElement.h"

SoundElement::SoundElement(Reader *reader)
{
    int soundid = reader->readInt();
    short basevolume = reader->readShort();
    int fullvolumedistance = reader->readInt();
    int nullvolumedistance = reader->readInt();
    short mindelaybetweenloops = reader->readShort();
    short maxdelaybetweenloops = reader->readShort();
}
