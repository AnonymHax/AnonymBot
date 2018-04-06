#ifndef CONNECTIONFAILUREMESSAGE_H
#define CONNECTIONFAILUREMESSAGE_H

#include "Public.h"
#include "AbstractServerMessage.h"

class ConnectionFailureMessage : public AbstractServerMessage
{
public:
    ConnectionFailureMessage();

    virtual void serialize(Writer *writer);
    virtual void deserialize(Reader *reader);

    FailureReasonsEnum reason;
};

#endif // CONNECTIONFAILUREMESSAGE_H
