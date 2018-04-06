#ifndef MESSAGEENUM_H
#define MESSAGEENUM_H

#include "Public.h"
#include "MessageLocalizer.h"

class MessageEnum : public AbstractSerializer
{
public:
    MessageEnum(const QString &output, MessageLocalizer *localizer);

    virtual void serialize();
    virtual void write();

private:
    QString m_fileName;
    QByteArray m_content;
    MessageLocalizer *m_localizer;
};

#endif // MESSAGEENUM_H
