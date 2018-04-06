#include "HeaderSerializer.h"

HeaderSerializer::HeaderSerializer(const QString &output, const ClassInfos &classInfos):
    AbstractSerializer(output),
    m_classInfos(classInfos),
    m_hasConstructor(false),
    m_needsConstructor(false)
{
    foreach(const InheritedClass &inherited, m_classInfos.inheritedClasses)
    {
        if(!inherited.passedParameters.isEmpty())
        {
            m_needsConstructor = true;
            break;
        }
    }
}

void HeaderSerializer::serialize()
{
    m_content.clear();
    QTextStream out(&m_content);

    out<<"#ifndef "<<m_classInfos.name.toUpper()<<"_H\n";
    out<<"#define "<<m_classInfos.name.toUpper()<<"_H\n";

    if(!m_includes.isEmpty())
        out<<"\n";

    if(m_classInfos.isSingleton)
        out<<"#include \""<<SINGLETON_PATH<<"\"\n";

    foreach(const QString &include, m_includes)
        out<<"#include \""<<include<<"\"\n";

    out<<"\n";

    if(m_classInfos.isSingleton)
        out<<"class "<<m_classInfos.name<<"Singleton;\n\n";


    if(!m_implicitClasses.isEmpty())
    {
        foreach(const QString &implicitClass, m_implicitClasses)
            out<<"class "<<implicitClass<<";\n";

        out<<"\n";
    }

    out<<"class "<<m_classInfos.name;

    if(!m_classInfos.inheritedClasses.isEmpty())
    {
        out<<" : ";

        for(int i = 0; i < m_classInfos.inheritedClasses.size(); i++)
        {
            if(m_classInfos.inheritedClasses[i].inheritance == PUBLIC)
                out<<"public ";

            else if(m_classInfos.inheritedClasses[i].inheritance == PRIVATE)
                out<<"private " ;

            else
                out <<"protected ";

            out<<m_classInfos.inheritedClasses[i].name;

            if(i+1 != m_classInfos.inheritedClasses.size())
                out<<", ";
        }
    }

    out<<"\n{";

    if(m_classInfos.isSingleton)
        out<<"\n  friend Singleton<"<<m_classInfos.name<<">;\n";

    bool hasAlreadyWritten = false;
    bool publicAlreadyDeclared = false;
    bool privateAlreadyDeclared = false;
    bool protectedAlreadyDeclared = false;

    if(!m_hasConstructor && m_needsConstructor)
    {
        FunctionPrototype constructor;
        constructor.name = m_classInfos.name;
        m_prototypes.insert(0, constructor);
    }

    foreach(const FunctionPrototype &prototype, m_prototypes)
    {
        if(prototype.inheritance == PUBLIC)
        {
            hasAlreadyWritten = true;

            if(!publicAlreadyDeclared)
            {
                publicAlreadyDeclared = true;
                out<<"\npublic:";
            }

            writeFunctionPrototype(prototype, out);
        }
    }

    if(hasAlreadyWritten)
    {
        out<<"\n";
        hasAlreadyWritten = false;
    }

    foreach(const ClassVariable &variable, m_variables)
    {
        if(variable.inheritance == PUBLIC)
        {
            hasAlreadyWritten = true;

            if(!publicAlreadyDeclared)
            {
                publicAlreadyDeclared = true;
                out<<"\npublic:";
            }

            writeClassVariable(variable, out);
        }
    }

    if(hasAlreadyWritten)
    {
        out<<"\n";
        hasAlreadyWritten = false;
    }

    foreach(const FunctionPrototype &prototype, m_prototypes)
    {
        if(prototype.inheritance == PRIVATE)
        {
            hasAlreadyWritten = true;

            if(!privateAlreadyDeclared)
            {
                privateAlreadyDeclared = true;
                out<<"\nprivate:";
            }

            writeFunctionPrototype(prototype, out);
        }
    }

    if(hasAlreadyWritten)
    {
        out<<"\n";
        hasAlreadyWritten = false;
    }

    foreach(const ClassVariable &variable, m_variables)
    {
        if(variable.inheritance == PRIVATE)
        {
            hasAlreadyWritten = true;

            if(!privateAlreadyDeclared)
            {
                privateAlreadyDeclared = true;
                out<<"\nprivate:";
            }

            writeClassVariable(variable, out);
        }
    }


    if(hasAlreadyWritten)
    {
        out<<"\n";
        hasAlreadyWritten = false;
    }

    foreach(const FunctionPrototype &prototype, m_prototypes)
    {
        if(prototype.inheritance == PROTECTED)
        {
            hasAlreadyWritten = true;

            if(!protectedAlreadyDeclared)
            {
                protectedAlreadyDeclared = true;
                out<<"\nprotected:";
            }

            writeFunctionPrototype(prototype, out);
        }
    }

    if(hasAlreadyWritten)
    {
        out<<"\n";
        hasAlreadyWritten = false;
    }

    foreach(const ClassVariable &variable, m_variables)
    {
        if(variable.inheritance == PROTECTED)
        {
            hasAlreadyWritten = true;

            if(!protectedAlreadyDeclared)
            {
                protectedAlreadyDeclared = true;
                out<<"\nprotected:";
            }

            writeClassVariable(variable, out);
        }
    }

    out<<"};\n";

    if(m_classInfos.isSingleton)
    {
        out<<"\nclass "<<m_classInfos.name<<"Singleton : public Singleton<"<<m_classInfos.name<<">\n";
        out<<"{};\n";
    }

    out<<"\n#endif // "<<m_classInfos.name.toUpper()<<"_H";

    if(!m_hasConstructor && m_needsConstructor)
        m_prototypes.removeFirst();

    out.flush();
}

void HeaderSerializer::write()
{
    QDir().mkpath(m_output);

    QFile file(m_output+"/"+m_classInfos.name+".h");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug()<<"ERREUR - HeaderSerializer - Ouverture du fichier echouée"<<m_output;

    file.resize(0);

    QTextStream out(&file);

    out<<m_content;

    out.flush();

    file.close();
}

void HeaderSerializer::addInclude(const QString &include)
{
    if(!m_includes.contains(include))
        m_includes<<include;
}

void HeaderSerializer::addFunction(FunctionPrototype prototype)
{
    if(prototype.name == m_classInfos.name)
        m_hasConstructor = true;

    m_prototypes<<prototype;
}

void HeaderSerializer::addClassVariable(ClassVariable variable)
{
    m_variables<<variable;
}

void HeaderSerializer::addImplicitClass(const QString &implicitClass)
{
    m_implicitClasses<<implicitClass;
}

void HeaderSerializer::writeFunctionPrototype(FunctionPrototype prototype, QTextStream &out)
{
    out<<"\n  ";

    if(prototype.isVirtual)
        out<<"virtual ";

    if(prototype.isStatic)
        out<<"static ";

    if(!prototype.returnType.type.isEmpty())
    {
        if(prototype.returnType.link == SHARED_POINTER)
            out<<"QSharedPointer<";

        out<<prototype.returnType.type;

        if(prototype.returnType.link == REFERENCE)
            out<<"&";

        else if(prototype.returnType.link == POINTER)
            out<<"*";

        else if(prototype.returnType.link == SHARED_POINTER)
            out<<">";

        out<<" ";
    }

    out<<prototype.name<<"(";

    for(int i = 0; i < prototype.parameters.size(); i++)
    {
        if(prototype.parameters[i].isConstant)
            out<<"const ";

        if(prototype.parameters[i].link == SHARED_POINTER)
            out<<"QSharedPointer<";

        out<<prototype.parameters[i].type;

        if(prototype.parameters[i].isContainer)
        {
            out<<"<";

            if(prototype.parameters[i].containerShell.link == SHARED_POINTER)
                out<<"QSharedPointer<";

            out<<prototype.parameters[i].containerShell.type;

            if(prototype.parameters[i].containerShell.link == REFERENCE)
                out<<"&";

            else if(prototype.parameters[i].containerShell.link == POINTER)
                out<<"*";

            else if(prototype.parameters[i].containerShell.link == SHARED_POINTER)
                out<<">";

            out<<">";
        }

        out<<" ";

        if(prototype.parameters[i].link == REFERENCE)
            out<<"&";

        else if(prototype.parameters[i].link == POINTER)
            out<<"*";

        else if(prototype.parameters[i].link == SHARED_POINTER)
            out<<">";

        out<<prototype.parameters[i].name;

        if(i+1 != prototype.parameters.size())
            out<<", ";
    }

    out<<")";

    if(prototype.isConstant)
        out<<" const";

    out<<";";
}

void HeaderSerializer::writeClassVariable(ClassVariable variable, QTextStream &out)
{
    out<<"\n  ";

    if(variable.variable.isConstant)
        out<<"const ";

    if(variable.variable.link == SHARED_POINTER)
        out<<"QSharedPointer<";

    out<<variable.variable.type;

    if(variable.variable.isContainer)
    {
        out<<"<";

        if(variable.variable.containerShell.link == SHARED_POINTER)
            out<<"QSharedPointer<";

        out<<variable.variable.containerShell.type;

        if(variable.variable.containerShell.link == REFERENCE)
            out<<"&";

        else if(variable.variable.containerShell.link == POINTER)
            out<<"*";

        else if(variable.variable.containerShell.link == SHARED_POINTER)
            out<<">";

        out<<">";
    }


    if(variable.variable.link == POINTER)
        out<<"*";

    else if(variable.variable.link == REFERENCE)
        out<<"&";

    else if(variable.variable.link == SHARED_POINTER)
        out<<">";

    out<<" ";


    out<<variable.variable.name<<";";
}
