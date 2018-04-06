#ifndef DATATRANSLATOR_H
#define DATATRANSLATOR_H

#include "Public.h"
#include "AbstractParser.h"
#include "AbstractSerializer.h"
#include "Splitter.h"
#include "Translator.h"
#include "SourceSerializer.h"

class DataTranslator : public AbstractParser, public AbstractSerializer
{
public:
    DataTranslator(const QString &input, const QString &output);
    ~DataTranslator();

    virtual void parse();
    virtual void serialize();
    virtual void write();

    void addManualInclude(QString include);
    void addAnticipatedDeclaration(QString className, QString include);

    QStringList getMissingIncludes() const;
    QString getName() const;
    QString getDofusName() const;
    QStringList getRequiredIncludes() const;
    QString getModule() const;

private:
    QString getFieldTranslatedLine(Variable variable, bool isFirst);

    Splitter m_splitter;
    SourceSerializer *m_source;
    QStringList m_manualIncludes;
    QStringList m_missingIncludes;
    QList<QPair<QString, QString>> m_anticipatedDeclarations;
    QString m_module;
};

#endif // DATATRANSLATOR_H
