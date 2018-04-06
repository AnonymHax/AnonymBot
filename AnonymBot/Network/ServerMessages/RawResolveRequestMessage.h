#ifndef RAWRESOLVEREQUESTMESSAGE_H
#define RAWRESOLVEREQUESTMESSAGE_H

#include "AbstractServerMessage.h"

class RawResolveRequestMessage : public AbstractServerMessage
{
public:

    RawResolveRequestMessage();

    virtual void serialize(Writer *writer);
    virtual void deserialize(Reader *reader);

    int index;
    QString ticket;
    QByteArray content;
};


#endif // RAWRESOLVEREQUESTMESSAGE_H
