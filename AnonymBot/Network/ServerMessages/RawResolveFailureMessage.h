#ifndef RAWRESOLVEFAILUREMESSAGE_H
#define RAWRESOLVEFAILUREMESSAGE_H

#include "AbstractServerMessage.h"

class RawResolveFailureMessage : public AbstractServerMessage
{
public:
    RawResolveFailureMessage();

    virtual void serialize(Writer *writer);
    virtual void deserialize(Reader *reader);

    int index;
    FailureReasonsEnum reason;
};

#endif // RAWRESOLVEFAILUREMESSAGE_H
