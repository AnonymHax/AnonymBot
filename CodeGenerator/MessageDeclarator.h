#ifndef MESSAGEDECLARATOR_H
#define MESSAGEDECLARATOR_H

#include "Public.h"
#include "MessageLocalizer.h"

class MessageDeclarator : public AbstractSerializer
{
public:
    MessageDeclarator(const QString &output, MessageLocalizer *localizer);

    virtual void serialize();
    virtual void write();

private:
    QString m_fileName;
    QByteArray m_content;
    MessageLocalizer *m_localizer;
};

#endif // MESSAGEDECLARATOR_H
