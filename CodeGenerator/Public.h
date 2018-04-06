#ifndef PUBLIC_H
#define PUBLIC_H

#include <iostream>

#include <QTime>
#include <QDebug>
#include <QStringListModel>
#include <QTextStream>
#include <QFile>
#include <QDirIterator>

#define INVALID -1

#define PUBLIC_PATH "Public.h"
#define READER_PATH "System/Tools/IO/Reader.h"
#define WRITER_PATH "System/Tools/IO/Writer.h"
#define SINGLETON_PATH "System/Tools/Singleton.h"
#define BOOLEANBYTEWRAPPER_PATH "System/Tools/IO/BooleanByteWrapper.h"
#define I18N_PATH "System/Tools/IO/I18n/I18nFile.h"
#define FIELD_PATH "System/Tools/IO/D2o/Field.h"

#define MESSAGE_PATH "Network/Messages/Data"
#define MESSAGE_UTILS_PATH "Network/Messages"
#define MESSAGE_BASE_NAME "AbstractMessage"
#define MESSAGE_DECLARATOR_NAME "MessageDeclarator"
#define MESSAGE_ENUM_NAME "MessageEnum"
#define MESSAGE_UTILS_NAME "MessageUtils"

#define CLASS_PATH "Network/Classes/Data"
#define CLASS_UTILS_PATH "Network/Classes"
#define CLASS_BASE_NAME "AbstractClass"
#define CLASS_MANAGER_NAME "ClassManager"
#define CLASS_DECLARATOR_NAME "ClassDeclarator"
#define CLASS_ENUM_NAME "ClassEnum"

#define ENUM_PATH "Network/Enum/Data"
#define ENUM_UTILS_PATH "Network/Enum"
#define ENUM_DECLARATOR_NAME "EnumDeclarator"

#define DATA_PATH "System/Tools/IO/D2O/Data"
#define DATA_UTILS_PATH "System/Tools/IO/D2O"
#define DATA_BASE_NAME "AbstractGameData"
#define DATA_DECLARATOR_NAME "GameDataDeclarator"
#define DATA_TYPE_DECLARATOR_NAME "GameDataTypeDeclarator"
#define DATA_CONVERTER_NAME "GameDataConverter"
#define DATA_ENUM_NAME "GameDataEnum"
#define DATA_ENUM_TYPE_NAME "GameDataTypeEnum"

#define DOFUS_MESSAGE_PATH "com/ankamagames/dofus/network/messages"
#define DOFUS_CLASS_PATH "com/ankamagames/dofus/network/types"
#define DOFUS_ENUM_PATH "com/ankamagames/dofus/network/enums"
#define DOFUS_PROTOCOLTYPEMANAGER_PATH "com/ankamagames/dofus/network/ProtocolTypeManager.py"
#define DOFUS_DATA_PATH "com/ankamagames/dofus/datacenter"

enum InheritanceType
{
    PUBLIC, PRIVATE, PROTECTED
};

enum LinkType
{
    NORMAL, POINTER, REFERENCE, SINGLETON, STATIC, ENUM, SHARED_POINTER
};

struct ContainerShell
{
    LinkType link = NORMAL;
    QString type;
};

struct Variable : ContainerShell
{
    QString name;
    QString value;
    bool isConstant = false;
    bool isContainer = false;
    ContainerShell containerShell;
};

struct ClassVariable
{
    InheritanceType inheritance = PUBLIC;
    Variable variable;
};

struct FunctionPrototype
{
    InheritanceType inheritance = PUBLIC;
    ContainerShell returnType;
    QString name;
    QList<Variable> parameters;
    bool isConstant = false;
    bool isVirtual = false;
    bool isStatic = false;
};

struct InheritedClass
{
    InheritanceType inheritance = PUBLIC;
    QString name;
    QStringList passedParameters;
};

struct ClassInfos
{
    QList<InheritedClass> inheritedClasses;
    QString name;
    bool isSingleton = false;
};

struct FunctionData
{
    FunctionPrototype prototype;
    QString content;
};

#endif // PUBLIC_H
