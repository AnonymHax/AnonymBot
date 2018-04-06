#include "EnumTranslator.h"

EnumTranslator::EnumTranslator(const QString &input, const QString &output):
    AbstractParser(input),
    AbstractSerializer(output),
    m_splitter(input)
{
}

void EnumTranslator::parse()
{
    m_splitter.parse();
    Translator::addConversionVariable(m_splitter.getClassInfos().name, m_splitter.getClassInfos().name, ENUM);
}

void EnumTranslator::serialize()
{
    m_content.clear();
    QTextStream out(&m_content);

    out<<"#ifndef "<<m_splitter.getClassInfos().name.toUpper()<<"_H\n";
    out<<"#define "<<m_splitter.getClassInfos().name.toUpper()<<"_H\n";

    out<<"\nenum class "<<m_splitter.getClassInfos().name;
    out<<"\n{";

    bool firstRound = true;

    foreach(const ClassVariable &classVariable, m_splitter.getClassVariables())
    {
        ConversionFunction enumVar;
        enumVar.originalName = classVariable.variable.name;
        enumVar.translatedName = classVariable.variable.name.toUpper();

        Translator::addFunction(m_splitter.getClassInfos().name, enumVar);

        if(firstRound)
            firstRound = false;

        else
            out<<",";

        out<<"\n    "<<classVariable.variable.name.toUpper()<<" = "<<classVariable.variable.value;
    }

    out<<"\n};\n";

    out<<"\n#endif // "<<m_splitter.getClassInfos().name.toUpper()<<"_H";

    out.flush();
}

void EnumTranslator::write()
{
    QDir().mkpath(m_output);

    QFile file(m_output+"/"+m_splitter.getClassInfos().name+".h");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug()<<"ERREUR - EnumTranslator - Ouverture du fichier echouée"<<m_output;

    file.resize(0);

    QTextStream out(&file);

    out<<m_content;

    out.flush();

    file.close();
}

QString EnumTranslator::getName() const
{
    return m_splitter.getClassInfos().name;
}
