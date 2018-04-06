#ifndef SOURCESERIALIZER_H
#define SOURCESERIALIZER_H

#include "AbstractSerializer.h"
#include "HeaderSerializer.h"

class SourceSerializer : public AbstractSerializer
{
public:
    SourceSerializer(const QString &output, const ClassInfos &classInfos);

    virtual void serialize();
    virtual void write();

    void addInclude(const QString &include);
    void addFunction(FunctionData function);

    HeaderSerializer &getHeader();

private:
    bool m_hasConstructor;
    bool m_needsConstructor;
    HeaderSerializer m_header;
    ClassInfos m_classInfos;
    QList<FunctionData> m_functions;
    QStringList m_includes;
    QByteArray m_content;
};

#endif // SOURCESERIALIZER_H
