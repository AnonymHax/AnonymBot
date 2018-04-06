#include "ClassLocalizer.h"

ClassLocalizer::ClassLocalizer(const QString &input, const QString &output):
    AbstractParser(input),
    AbstractSerializer(output)
{

}

ClassLocalizer::~ClassLocalizer()
{
}

void ClassLocalizer::parse()
{
    QDirIterator dirIt(m_input+"/"+DOFUS_CLASS_PATH, QDirIterator::Subdirectories);
    QList<QPair<QString, QString>> childrenPaths;

    while (dirIt.hasNext())
    {
        dirIt.next();
        if (QFileInfo(dirIt.filePath()).isFile())
        {
            QPair<QString, QString> pair;
            pair.first = dirIt.filePath();
            pair.second = m_output+"/"+CLASS_PATH+dirIt.filePath().remove(dirIt.fileName()).remove(m_input+"/"+DOFUS_CLASS_PATH);
            childrenPaths<<pair;
            Splitter quick(pair.first);
            quick.parse();
            Translator::addTranslated(quick.getClassInfos().name, m_derivableChildren.contains(quick.getClassInfos().name));
        }
    }

    for(int i = 0; i < childrenPaths.size(); i++)
    {
        m_children<<ClassTranslator(childrenPaths[i].first, childrenPaths[i].second);
        m_children.last().parse();
    }
}

void ClassLocalizer::serialize()
{
    QHash<QString, int> toLoad;

    for(int i = 0; i < m_children.size(); i++)
        toLoad[m_children[i].getName()] = i;

    foreach(QString x, m_derivableChildren)
        orderChild(x, toLoad);

    foreach(const QString &childName, toLoad.keys())
        orderChild(childName, toLoad);

    for(int i = 0; i < m_orderedChildren.size(); i++)
        toLoad[m_orderedChildren[i]->getName()] = i;

    foreach(ClassTranslator *child, m_orderedChildren)
    {
        if(Translator::getLinkType(child->getName()) != SHARED_POINTER && hasPointers(child->getName(), toLoad))
            Translator::addTranslated(child->getName(), true);
    }

    foreach(ClassTranslator *child, m_orderedChildren)
        child->serialize();
}

void ClassLocalizer::write()
{
    for(int i = 0; i < m_children.size(); i++)
        m_children[i].write();
}

void ClassLocalizer::setDerivableChildren(const QStringList &derivableChildren)
{
    m_derivableChildren = derivableChildren;
}

const QList<ClassTranslator> &ClassLocalizer::getChildren() const
{
    return m_children;
}

void ClassLocalizer::orderChild(QString childName, QHash<QString, int> &toLoad, QString previous, bool ignorePrevious)
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
            //            if(Translator::getLinkType(childName) == POINTER && m_children[toLoad[childName]].getrequiredIncludes())
            //                m_children[toLoad[childName]].addAnticipatedDeclaration(missingInclude, path);

            //            else
            m_children[toLoad[childName]].addManualInclude(path);

            orderChild(missingInclude, toLoad, childName);
            toLoad.remove(missingInclude);
        }

        else if(!ignorePrevious)
        {
            Translator::addTranslated(missingInclude, true);
            m_children[toLoad[childName]].addAnticipatedDeclaration(missingInclude, path);
            orderChild(missingInclude, toLoad, childName, true);
        }
    }

    m_orderedChildren<<&m_children[toLoad[childName]];
}

bool ClassLocalizer::hasPointers(QString childName, QHash<QString, int> &toLoad)
{
    foreach(const ClassVariable &classVariable, m_orderedChildren[toLoad[childName]]->getClassVariables())
    {
        if(classVariable.variable.isContainer && Translator::isTranslated(classVariable.variable.containerShell.type) && Translator::getLinkType(classVariable.variable.containerShell.type) == SHARED_POINTER)
            return true;

        if(Translator::isTranslated(classVariable.variable.type) && Translator::getLinkType(classVariable.variable.type) == SHARED_POINTER)
            return true;
    }

    foreach(const InheritedClass &inheritedClass, m_orderedChildren[toLoad[childName]]->getInheritedClasses())
    {
        if(Translator::isTranslated(inheritedClass.name))
        {
            if(toLoad.contains(inheritedClass.name) && hasPointers(inheritedClass.name, toLoad))
                return true;

            else
                toLoad.remove(inheritedClass.name);
        }
    }

    return false;
}
