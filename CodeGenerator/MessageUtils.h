#ifndef MESSAGEUTILS_H
#define MESSAGEUTILS_H

#include "Public.h"
#include "MessageLocalizer.h"

class MessageUtils : public AbstractSerializer
{
public:
    MessageUtils(const QString &output, MessageLocalizer *localizer);
    ~MessageUtils();

    virtual void serialize();
    virtual void write();

private:
    SourceSerializer *m_source;
    MessageLocalizer *m_localizer;
};

#endif // MESSAGEUTILS_H
