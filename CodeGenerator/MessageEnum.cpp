#include "MessageEnum.h"

MessageEnum::MessageEnum(const QString &output, MessageLocalizer *localizer):
    AbstractSerializer(output),
    m_localizer(localizer),
    m_fileName(MESSAGE_ENUM_NAME)
{
}

void MessageEnum::serialize()
{
    m_content.clear();
    QTextStream out(&m_content);

    out<<"#ifndef "+m_fileName.toUpper()+"_H\n";
    out<<"#define "+m_fileName.toUpper()+"_H\n";

    out<<"\n";

    out<<"\nenum class "+QString(MESSAGE_ENUM_NAME);
    out<<"\n{";

    bool firstRound = true;

    foreach(const MessageTranslator &child, m_localizer->getChildren())
    {
        if(firstRound)
            firstRound = false;

        else
            out<<",";

        out<<"\n    "<<child.getName().toUpper()<<" = "<<QString::number(child.getId());
    }


    out<<"\n};\n";

    out<<"\n#endif // "+m_fileName.toUpper()+"_H";

    out.flush();
}

void MessageEnum::write()
{
    QDir().mkpath(m_output+"/"+MESSAGE_UTILS_PATH);

    QFile file(m_output+"/"+MESSAGE_UTILS_PATH+"/"+m_fileName+".h");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug()<<"ERREUR - MessageEnum - Ouverture du fichier echouée"<<m_output+"/"+MESSAGE_UTILS_PATH+"/"+m_fileName+".h";

    file.resize(0);

    QTextStream out(&file);

    out<<m_content;

    out.flush();

    file.close();
}
