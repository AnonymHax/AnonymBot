#include "SourceSerializer.h"

SourceSerializer::SourceSerializer(const QString &output, const ClassInfos &classInfos):
    AbstractSerializer(output),
    m_header(output, classInfos),
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

void SourceSerializer::serialize()
{
    m_header.serialize();

    m_content.clear();
    QTextStream out(&m_content);



    out<<"#include \""<<m_classInfos.name+".h"<<"\"\n";

    foreach(const QString &include, m_includes)
        out<<"#include \""<<include<<"\"\n";

    out<<"\n";

    if(!m_hasConstructor && m_needsConstructor)
    {
        FunctionData constructor;
        constructor.prototype.name = m_classInfos.name;
        m_functions.insert(0, constructor);
    }

    foreach(const FunctionData &funct, m_functions)
    {
        if(!funct.prototype.returnType.type.isEmpty())
        {
            if(funct.prototype.returnType.link == SHARED_POINTER)
                out<<"QSharedPointer<";

            out<<funct.prototype.returnType.type;

            if(funct.prototype.returnType.link == REFERENCE)
                out<<"&";

            else if(funct.prototype.returnType.link == POINTER)
                out<<"*";

            else if(funct.prototype.returnType.link == SHARED_POINTER)
                out<<">";

            out<<" ";
        }

        out<<m_classInfos.name<<"::"<<
             funct.prototype.name<<"(";


        for(int i = 0; i < funct.prototype.parameters.size(); i++)
        {
            if(funct.prototype.parameters[i].isConstant)
                out<<"const ";

            if(funct.prototype.parameters[i].link == SHARED_POINTER)
                out<<"QSharedPointer<";

            out<<funct.prototype.parameters[i].type;

            if(funct.prototype.parameters[i].isContainer)
            {
                out<<"<";

                if(funct.prototype.parameters[i].containerShell.link == SHARED_POINTER)
                    out<<"QSharedPointer<";

                out<<funct.prototype.parameters[i].containerShell.type;

                if(funct.prototype.parameters[i].containerShell.link == REFERENCE)
                    out<<"&";

                else if(funct.prototype.parameters[i].containerShell.link == POINTER)
                    out<<"*";

                else if(funct.prototype.parameters[i].containerShell.link == SHARED_POINTER)
                    out<<">";

                out<<">";
            }

            out<<" ";

            if(funct.prototype.parameters[i].link == REFERENCE)
                out<<"&";

            else if(funct.prototype.parameters[i].link == POINTER)
                out<<"*";

            else if(funct.prototype.parameters[i].link == SHARED_POINTER)
                out<<">";

            out<<funct.prototype.parameters[i].name;

            if(i+1 != funct.prototype.parameters.size())
                out<<", ";
        }

        out<<")";

        if(funct.prototype.isConstant)
            out<<" const";

        if(funct.prototype.name == m_classInfos.name)
        {
            bool isFirst = true;

            foreach(const InheritedClass &inherited, m_classInfos.inheritedClasses)
            {
                if(!inherited.passedParameters.isEmpty())
                {
                    out<<"\n    ";

                    if(isFirst)
                    {
                        isFirst = false;
                        out<<":";
                    }

                    else
                        out<<",";

                    out<<inherited.name+"(";

                    bool isFirstP = true;

                    foreach(const QString &passedParam, inherited.passedParameters)
                    {
                        if(isFirstP)
                            isFirstP = false;

                        else
                            out<<", ";

                        out<<passedParam;
                    }

                    out<<")";
                }
            }
        }

        out<<"\n";

        out<<"{\n";

        if(!funct.content.isEmpty())
            out<<"  ";

        int brackets = 1;

        for(int i = 0; i < funct.content.size(); i++)
        {
            out<<funct.content[i];

            //Brackets
            if(i+1 != funct.content.size() && funct.content[i+1] == '}')
                brackets --;

            if(funct.content[i] == '{')
                brackets ++;

            if(i+1 != funct.content.size() && funct.content[i] == '\n')
            {
                for(int j = 0; j < brackets; j++)
                    out<<"  ";
            }
        }

        if(!funct.content.isEmpty() && funct.content.at(funct.content.size()-1) != '\n')
            out<<"\n";

        out<<"}\n";
        out<<"\n";
    }

    if(!m_hasConstructor && m_needsConstructor)
        m_functions.removeFirst();

    out.flush();
}

void SourceSerializer::write()
{
    QDir().mkpath(m_output);

    QFile file(m_output+"/"+m_classInfos.name+".cpp");

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        qDebug()<<"ERREUR - SourceSerializer - Ouverture du fichier echouée"<<m_output;

    file.resize(0);

    QTextStream out(&file);

    out<<m_content;

    out.flush();

    file.close();

    m_header.write();
}

void SourceSerializer::addInclude(const QString &include)
{
    if(!m_includes.contains(include))
        m_includes<<include;
}

void SourceSerializer::addFunction(FunctionData function)
{
    m_header.addFunction(function.prototype);
    m_functions<<function;
}

HeaderSerializer &SourceSerializer::getHeader()
{
    return m_header;
}
