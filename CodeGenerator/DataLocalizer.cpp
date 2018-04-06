#include "DataLocalizer.h"

DataLocalizer::DataLocalizer(const QString &input, const QString &output):
    AbstractParser(input),
    AbstractSerializer(output)
{
}

void DataLocalizer::parse()
{
    QDirIterator dirIt(m_input+"/"+DOFUS_DATA_PATH, QDirIterator::Subdirectories);
    QList<QPair<QString, QString>> childrenPaths;

    while (dirIt.hasNext())
    {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile())
        {
            QPair<QString, QString> pair;
            pair.first = dirIt.filePath();
            pair.second = m_output+"/"+DATA_PATH+dirIt.filePath().remove(dirIt.fileName()).remove(m_input+"/"+DOFUS_DATA_PATH);

            Splitter quick(pair.first);
            quick.parse();

            bool isDataCenter = false;

            foreach(const InheritedClass inherited, quick.getClassInfos().inheritedClasses)
            {
                if(inherited.name == "IDataCenter")
                {
                    isDataCenter = true;
                    break;
                }
            }

            if(isDataCenter)
            {
                Translator::addTranslated(quick.getClassInfos().name, quick.getClassInfos().name+"Data");
                childrenPaths<<pair;
            }

            else
            {
                DataTranslator u(pair.first, pair.second);
                u.parse();
                m_uselessChildren<<u;
            }
        }
    }

    for(int i = 0; i < childrenPaths.size(); i++)
    {
        m_children<<DataTranslator(childrenPaths[i].first, childrenPaths[i].second);
        m_children.last().parse();
    }
}

void DataLocalizer::serialize()
{
    QHash<QString, int> toLoad;
    for(int i = 0; i < m_children.size(); i++)
        toLoad[m_children[i].getDofusName()] = i;

    foreach(const QString &childName, toLoad.keys())
        loadChild(childName, toLoad);
}

void DataLocalizer::write()
{
    for(int i = 0; i < m_children.size(); i++)
        m_children[i].write();
}

const QList<DataTranslator> &DataLocalizer::getChildren() const
{
    return m_children;
}

const QList<DataTranslator> &DataLocalizer::getUselessChildren() const
{
    return m_uselessChildren;
}

void DataLocalizer::loadChild(QString childName, QHash<QString, int> &toLoad, QString previous, bool ignorePrevious)
{
    foreach(const QString &missingInclude, m_children[toLoad[childName]].getMissingIncludes())
    {
        QString path;

        for(int i = 0; i < m_children.size(); i++)
        {
            if(m_children[i].getDofusName() == missingInclude)
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
            m_children[toLoad[childName]].addAnticipatedDeclaration(m_children[toLoad[missingInclude]].getName(), path);
            loadChild(missingInclude, toLoad, childName, true);
        }
    }

    m_children[toLoad[childName]].serialize();
}

