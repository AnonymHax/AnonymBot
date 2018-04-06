#ifndef DATALOCALIZER_H
#define DATALOCALIZER_H

#include "Public.h"
#include "DataTranslator.h"

class DataLocalizer : public AbstractParser, public AbstractSerializer
{
public:
    DataLocalizer(const QString &input, const QString &output);

    virtual void parse();
    virtual void serialize();
    virtual void write();

    const QList<DataTranslator> &getChildren() const;
    const QList<DataTranslator> &getUselessChildren() const;

private:
    void loadChild(QString childName, QHash<QString, int> &toLoad, QString previous = "", bool ignorePrevious = false);

    QList<DataTranslator> m_children;
    QList<DataTranslator> m_uselessChildren;
};

#endif // DATALOCALIZER_H
