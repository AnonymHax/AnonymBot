#include "MessageDeclarator.h"

MessageDeclarator::MessageDeclarator(const QString &output, MessageLocalizer *localizer):
    AbstractSerializer(output),
    m_localizer(localizer),
    m_fileName(MESSAGE_DECLARATOR_NAME)
{
}

void MessageDeclarator::serialize()
{
    m_content.clear();
    QTextStream out(&m_content);

    out<<"#ifndef "+m_fileName.toUpper()+"_H\n";
    out<<"#define "+m_fileName.toUpper()+"_H\n";

    out<<"\n";

    foreach(const MessageTranslator &child, m_localizer->getChildren())
        out<<"#include \""<<child.getOutput().remove(m_output).remove(0,1)+child.getName()+".h"<<"\"\n";

    out<<"\n#endif // "+m_fileName.toUpper()+"_H";

    out.flush();
}

void MessageDeclarator::write()
{
    QDir().mkpath(m_output+"/"+MESSAGE_UTILS_PATH);

    QFile file(m_output+"/"+MESSAGE_UTILS_PATH+"/"+m_fileName+".h");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug()<<"ERREUR - MessageDeclarator - Ouverture du fichier echouée"<<m_output+"/"+MESSAGE_UTILS_PATH+"/"+m_fileName+".h";

    file.resize(0);

    QTextStream out(&file);

    out<<m_content;

    out.flush();

    file.close();
}
