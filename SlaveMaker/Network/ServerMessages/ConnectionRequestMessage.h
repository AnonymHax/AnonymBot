#ifndef CONNECTIONREQUESTMESSAGE_H
#define CONNECTIONREQUESTMESSAGE_H

#include "Public.h"
#include "AbstractServerMessage.h"

class ConnectionRequestMessage : public AbstractServerMessage
{
public:
    ConnectionRequestMessage();

    virtual void serialize(Writer *writer);
    virtual void deserialize(Reader *reader);

    QString login;
    QString password;
};

#endif // CONNECTIONREQUESTMESSAGE_H
