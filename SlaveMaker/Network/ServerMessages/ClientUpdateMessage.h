#ifndef CLIENTUPDATEMESSAGE_H
#define CLIENTUPDATEMESSAGE_H

#include "Public.h"
#include "AbstractServerMessage.h"

class ClientUpdateMessage : public AbstractServerMessage
{
public:
    ClientUpdateMessage();

    virtual void serialize(Writer *writer);
    virtual void deserialize(Reader *reader);

    uint nbActiveBots;
};

#endif // CLIENTUPDATEMESSAGE_H
