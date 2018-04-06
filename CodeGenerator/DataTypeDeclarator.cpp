#include "DataTypeDeclarator.h"

DataTypeDeclarator::DataTypeDeclarator(const QString &output, DataLocalizer *localizer):
    AbstractSerializer(output),
    m_localizer(localizer),
    m_fileName(DATA_TYPE_DECLARATOR_NAME)
{
}

void DataTypeDeclarator::serialize()
{
    m_content.clear();
    QTextStream out(&m_content);

    out<<"#ifndef "+m_fileName.toUpper()+"_H\n";
    out<<"#define "+m_fileName.toUpper()+"_H\n";

    out<<"\n";

    out<<"\nenum class "+QString(DATA_ENUM_TYPE_NAME);
    out<<"\n{";

    out<<"\n    UNKNOWN";

    foreach(const DataTranslator &child, m_localizer->getChildren())
    {
        if(!child.getModule().isEmpty())
        {
            out<<",";
            out<<"\n    "<<child.getModule().toUpper();
        }
    }


    out<<"\n};\n";

    out<<"\n#endif // "+m_fileName.toUpper()+"_H";

    out.flush();
}

void DataTypeDeclarator::write()
{
    QDir().mkpath(m_output+"/"+DATA_UTILS_PATH);

    QFile file(m_output+"/"+DATA_UTILS_PATH+"/"+m_fileName+".h");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug()<<"ERREUR - DataTypeDeclarator - Ouverture du fichier echouée"<<m_output+"/"+DATA_UTILS_PATH+"/"+m_fileName+".h";

    file.resize(0);

    QTextStream out(&file);

    out<<m_content;

    out.flush();

    file.close();
}
