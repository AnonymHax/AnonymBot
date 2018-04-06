#ifndef UPDATEMESSAGE_H
#define UPDATEMESSAGE_H

#include "Public.h"
#include "AbstractServerMessage.h"

class UpdateMessage : public AbstractServerMessage
{
public:
    UpdateMessage();

    virtual void serialize(Writer *writer);
    virtual void deserialize(Reader *reader);

    uint nbActiveBots;
};

#endif // UPDATEMESSAGE_H
