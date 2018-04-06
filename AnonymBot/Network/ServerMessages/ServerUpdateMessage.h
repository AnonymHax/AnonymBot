#ifndef SERVERUPDATEMESSAGE_H
#define SERVERUPDATEMESSAGE_H

#include "Public.h"
#include "AbstractServerMessage.h"

class ServerUpdateMessage : public AbstractServerMessage
{
public:
    ServerUpdateMessage();  

    virtual void serialize(Writer *writer);
    virtual void deserialize(Reader *reader);

    uint nbActiveBots;
};

#endif // SERVERUPDATEMESSAGE_H
