#include "DataDeclarator.h"

DataDeclarator::DataDeclarator(const QString &output, DataLocalizer *localizer):
    AbstractSerializer(output),
    m_localizer(localizer),
    m_fileName(DATA_DECLARATOR_NAME)
{
}

void DataDeclarator::serialize()
{
    m_content.clear();
    QTextStream out(&m_content);

    out<<"#ifndef "+m_fileName.toUpper()+"_H\n";
    out<<"#define "+m_fileName.toUpper()+"_H\n";

    out<<"\n";

    foreach(const DataTranslator &child, m_localizer->getChildren())
        out<<"#include \""<<child.getOutput().remove(m_output).remove(0,1)+child.getName()+".h"<<"\"\n";

    out<<"\nenum class "+QString(DATA_ENUM_NAME);
    out<<"\n{";

    bool firstRound = true;

    foreach(const DataTranslator &child, m_localizer->getChildren())
    {
        if(firstRound)
            firstRound = false;

        else
            out<<",";

        out<<"\n    "<<child.getName().toUpper();
    }


    out<<"\n};\n";

    out<<"\n#endif // "+m_fileName.toUpper()+"_H";

    out.flush();
}

void DataDeclarator::write()
{
    QDir().mkpath(m_output+"/"+DATA_UTILS_PATH);

    QFile file(m_output+"/"+DATA_UTILS_PATH+"/"+m_fileName+".h");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug()<<"ERREUR - DataDeclarator - Ouverture  du fichier echouée"<<m_output+"/"+DATA_UTILS_PATH+"/"+m_fileName+".h";

    file.resize(0);

    QTextStream out(&file);

    out<<m_content;

    out.flush();

    file.close();
}
