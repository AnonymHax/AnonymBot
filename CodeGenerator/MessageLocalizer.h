#ifndef MESSAGELOCALIZER_H
#define MESSAGELOCALIZER_H

#include "Public.h"
#include "MessageTranslator.h"

class MessageLocalizer : public AbstractParser, public AbstractSerializer
{
public:
    MessageLocalizer(const QString &input, const QString &output);
    ~MessageLocalizer();

    virtual void parse();
    virtual void serialize();
    virtual void write();

    const QList<MessageTranslator> &getChildren() const;

private:
    void loadChild(QString childName, QHash<QString, int> &toLoad, QString previous = "", bool ignorePrevious = false);

    QList<MessageTranslator> m_children;
};

#endif // MESSAGELOCALIZER_H
