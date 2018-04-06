#include "MessageLocalizer.h"

MessageLocalizer::MessageLocalizer(const QString &input, const QString &output):
    AbstractParser(input),
    AbstractSerializer(output)
{
}

MessageLocalizer::~MessageLocalizer()
{

}

void MessageLocalizer::parse()
{
    QDirIterator dirIt(m_input+"/"+DOFUS_MESSAGE_PATH, QDirIterator::Subdirectories);
    QList<QPair<QString, QString>> childrenPaths;

    while (dirIt.hasNext())
    {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile())
        {
            QPair<QString, QString> pair;
            pair.first = dirIt.filePath();
            pair.second = m_output+"/"+MESSAGE_PATH+dirIt.filePath().remove(dirIt.fileName()).remove(m_input+"/"+DOFUS_MESSAGE_PATH);
            childrenPaths<<pair;
            Splitter quick(pair.first);
            quick.parse();
            Translator::addTranslated(quick.getClassInfos().name);
        }
    }

    for(int i = 0; i < childrenPaths.size(); i++)
    {
        m_children<<MessageTranslator(childrenPaths[i].first, childrenPaths[i].second);
        m_children.last().parse();
    }
}

void MessageLocalizer::serialize()
{
    QHash<QString, int> toLoad;
    for(int i = 0; i < m_children.size(); i++)
        toLoad[m_children[i].getName()] = i;

    foreach(const QString &childName, toLoad.keys())
        loadChild(childName, toLoad);
}

void MessageLocalizer::write()
{
    for(int i = 0; i < m_children.size(); i++)
        m_children[i].write();
}

const QList<MessageTranslator> &MessageLocalizer::getChildren() const
{
    return m_children;
}

void MessageLocalizer::loadChild(QString childName, QHash<QString, int> &toLoad, QString previous, bool ignorePrevious)
{
    foreach(const QString &missingInclude, m_children[toLoad[childName]].getMissingIncludes())
    {
        QString path;

        for(int i = 0; i < m_children.size(); i++)
        {
            if(m_children[i].getName() == missingInclude)
            {
                path = m_children[i].getOutput().remove(m_output);
                path.remove(0,1);
                path += m_children[i].getName()+".h";
            }
        }

        if(missingInclude != previous)
        {
//            if(Translator::getLinkType(childName) == POINTER)
//                m_children[toLoad[childName]].addAnticipatedDeclaration(missingInclude, path);

//            else
                m_children[toLoad[childName]].addManualInclude(path);

            loadChild(missingInclude, toLoad, childName);
            toLoad.remove(missingInclude);
        }

        else if(!ignorePrevious)
        {
            m_children[toLoad[childName]].addAnticipatedDeclaration(missingInclude, path);
            loadChild(missingInclude, toLoad, childName, true);
        }
    }

    m_children[toLoad[childName]].serialize();
}
