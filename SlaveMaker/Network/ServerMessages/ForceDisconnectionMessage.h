#ifndef FORCEDISCONNECTIONMESSAGE_H
#define FORCEDISCONNECTIONMESSAGE_H

#include "Public.h"
#include "AbstractServerMessage.h"

class ForceDisconnectionMessage : public AbstractServerMessage
{
public:
    ForceDisconnectionMessage();

    virtual void serialize(Writer *writer);
    virtual void deserialize(Reader *reader);

    FailureReasonsEnum reason;
};

#endif // FORCEDISCONNECTIONMESSAGE_H
