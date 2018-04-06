#ifndef RAWRESOLVEMESSAGE_H
#define RAWRESOLVEMESSAGE_H

#include "AbstractServerMessage.h"

class RawResolveMessage : public AbstractServerMessage
{
public:
    RawResolveMessage();

    virtual void serialize(Writer *writer);
    virtual void deserialize(Reader *reader);

    int index;
    QList<int> data;
};

#endif // RAWRESOLVEMESSAGE_H
