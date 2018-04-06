#ifndef CONNECTIONSUCCESSMESSAGE_H
#define CONNECTIONSUCCESSMESSAGE_H

#include "Public.h"
#include "AbstractServerMessage.h"

class ConnectionSuccessMessage : public AbstractServerMessage
{
public:
    ConnectionSuccessMessage();

    virtual void serialize(Writer *writer);
    virtual void deserialize(Reader *reader);

    AccountTypeEnum accountType;
    uint leftTime;
};

#endif // CONNECTIONSUCCESSMESSAGE_H
