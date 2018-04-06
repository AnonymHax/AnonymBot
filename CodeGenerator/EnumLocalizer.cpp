#include "EnumLocalizer.h"

EnumLocalizer::EnumLocalizer(const QString &input, const QString &output):
    AbstractParser(input),
    AbstractSerializer(output)
{
}

void EnumLocalizer::parse()
{
    QDirIterator dirIt(m_input+"/"+DOFUS_ENUM_PATH, QDirIterator::Subdirectories);

    while (dirIt.hasNext())
    {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile())
        {
            m_children<<EnumTranslator(dirIt.filePath(), m_output+"/"+ENUM_PATH+dirIt.filePath().remove(dirIt.fileName()).remove(m_input+"/"+DOFUS_ENUM_PATH));
            m_children.last().parse();
        }
    }
}

void EnumLocalizer::serialize()
{
    for(int i = 0; i < m_children.size(); i++)
        m_children[i].serialize();
}

void EnumLocalizer::write()
{
    for(int i = 0; i < m_children.size(); i++)
        m_children[i].write();
}

const QList<EnumTranslator> &EnumLocalizer::getChildren() const
{
    return m_children;
}
