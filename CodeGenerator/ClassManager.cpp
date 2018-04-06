#include "ClassManager.h"

ClassManager::ClassManager(const QString &input, const QString &output, ClassLocalizer *localizer):
    AbstractParser(input),
    AbstractSerializer(output),
    m_localizer(localizer),
    m_splitter(input+"/"+DOFUS_PROTOCOLTYPEMANAGER_PATH)
{
}

ClassManager::~ClassManager()
{
    if(m_source)
        delete m_source;
}

void ClassManager::parse()
{
    m_splitter.parse();

    QString content;
    foreach(const FunctionData &funct, m_splitter.getFunctions())
    {
        if(funct.prototype.name == "register")
        {
            content = funct.content;
            break;
        }
    }

    QTextStream in(&content, QIODevice::ReadOnly);


    QString line;

    do
    {
        line = in.readLine();
        line = line.simplified();

        if(line.contains("StoreDataManager.getInstance().registerClass(new "))
        {
            line.remove("StoreDataManager.getInstance().registerClass(new ");
            line.remove("(),true,true);");

            if(!m_derivableChildren.contains(line))
                m_derivableChildren<<line;
        }

    } while(!line.isNull());

    m_localizer->setDerivableChildren(m_derivableChildren);
}

void ClassManager::serialize()
{
    ClassInfos classInfos;
    classInfos.name = CLASS_MANAGER_NAME;
    classInfos.isSingleton = true;

    m_source = new SourceSerializer(m_output+"/"+CLASS_UTILS_PATH, classInfos);

    m_source->getHeader().addInclude(QString(CLASS_UTILS_PATH)+"/"+QString(CLASS_BASE_NAME)+".h");

    foreach(const QString &include, m_splitter.getIncludes())
    {
        QString translated = Translator::translateInclude(include);
        if(!translated.isEmpty())
            m_source->addInclude(translated);
    }

    FunctionData getClass;
    getClass.prototype.name = "getClass";
    getClass.prototype.returnType.type = CLASS_BASE_NAME;
    getClass.prototype.returnType.link = SHARED_POINTER;
    Variable parameter;
    parameter.type = "int";
    parameter.name = "classId";
    getClass.prototype.parameters<<parameter;

    QTextStream out(&getClass.content, QIODevice::WriteOnly);

    out<<"switch(classId)\n";
    out<<"{\n";

    QHash<QString, int> table;

    foreach(const ClassTranslator &child, m_localizer->getChildren())
        table[child.getName()] = child.getId();

    out<<"default:\n";
    out<<"{\n";
    out<<"qDebug()<<\"ERREUR - ClassManager - Ne connait de classe possedant l'id\"<<"<<parameter.name<<";\n";
    out<<"return QSharedPointer<"+QString(CLASS_BASE_NAME)+">();\n";
    out<<"}\n\n";

    foreach(const QString &derivableChild, m_derivableChildren)
    {
        if(table.contains(derivableChild))
        {
            out<<"case "<<table[derivableChild]<<":\n";
            out<<"  return QSharedPointer<"+QString(CLASS_BASE_NAME)+">(new "<<derivableChild<<"());\n";
            out<<"\n";
        }

        else
            qDebug()<<"ERREUR - ClassManager - Ne connait pas la classe"<<derivableChild;
    }

    out<<"}\n";

    m_source->addFunction(getClass);

    m_source->serialize();
}

void ClassManager::write()
{
    m_source->write();
}
