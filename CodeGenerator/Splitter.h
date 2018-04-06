#ifndef SPLITTER_H
#define SPLITTER_H

#include "Public.h"
#include "AbstractParser.h"

class Splitter : public AbstractParser
{
public:
    Splitter(const QString &input);

    virtual void parse();

    QList<QString> getIncludes() const;
    ClassInfos getClassInfos() const;
    QList<FunctionData> getFunctions() const;
    QList<ClassVariable> getClassVariables() const;

private:
    void readInclude(QString line);
    void readClass(QString line);
    void readPrototype(QString line);
    void readContent(QString line, int brackets);
    void readClassVariable(QString line);

    QList<FunctionData> m_functions;
    QList<QString> m_includes;
    ClassInfos m_classInfos;
    QList<ClassVariable> m_variables;
};

#endif // SPLITTER_H
