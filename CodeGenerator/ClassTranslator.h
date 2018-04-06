#ifndef CLASSTRANSLATOR_H
#define CLASSTRANSLATOR_H

#include "Public.h"
#include "Translator.h"
#include "Splitter.h"
#include "SourceSerializer.h"

class ClassTranslator : public AbstractParser, public AbstractSerializer
{
public:
    ClassTranslator(const QString &input, const QString &output);
    ~ClassTranslator();

    virtual void parse();
    virtual void serialize();
    virtual void write();

    void addManualInclude(QString include);
    void addAnticipatedDeclaration(QString className, QString include);

    QStringList getMissingIncludes() const;
    QString getName() const;
    int getId() const;
    QList<ClassVariable> getClassVariables() const;
    QList<InheritedClass> getInheritedClasses() const;

private:    
    Splitter m_splitter;
    SourceSerializer *m_source;
    int m_id;
    QStringList m_manualIncludes;
    QStringList m_missingIncludes;
    QList<QPair<QString, QString>> m_anticipatedDeclarations;
};

#endif // CLASSTRANSLATOR_H
