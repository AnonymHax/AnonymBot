#ifndef HEADERSERIALIZER_H
#define HEADERSERIALIZER_H

#include "AbstractSerializer.h"
#include "Public.h"

class HeaderSerializer : public AbstractSerializer
{
public:
    HeaderSerializer(const QString &output, const ClassInfos &classInfos);

    virtual void serialize();
    virtual void write();

    void addInclude(const QString &include);
    void addFunction(FunctionPrototype prototype);
    void addClassVariable(ClassVariable variable);
    void addImplicitClass(const QString &implicitClass);

private:
    void writeFunctionPrototype(FunctionPrototype prototype, QTextStream &out);
    void writeClassVariable(ClassVariable variable, QTextStream &out);

    bool m_hasConstructor;
    bool m_needsConstructor;
    ClassInfos m_classInfos;
    QStringList m_includes;
    QList<FunctionPrototype> m_prototypes;
    QList<ClassVariable> m_variables;
    QStringList m_implicitClasses;
    QByteArray m_content;
};

#endif // HEADERSERIALIZER_H
