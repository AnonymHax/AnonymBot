#ifndef CLASSLOCALIZER_H
#define CLASSLOCALIZER_H

#include "Public.h"
#include "ClassTranslator.h"

class ClassLocalizer : public AbstractParser, public AbstractSerializer
{
public:
    ClassLocalizer(const QString &input, const QString &output);
    ~ClassLocalizer();

    virtual void parse();
    virtual void serialize();
    virtual void write();

    void setDerivableChildren(const QStringList &derivableClasses);
    const QList<ClassTranslator> &getChildren() const;

private:
    void orderChild(QString childName, QHash<QString, int> &toLoad, QString previous = "", bool ignorePrevious = false);
    bool hasPointers(QString childName, QHash<QString, int> &toLoad);

    QList<ClassTranslator> m_children;
    QList<ClassTranslator*> m_orderedChildren;
    QStringList m_derivableChildren;
};

#endif // CLASSLOCALIZER_H
