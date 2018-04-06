#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "Public.h"

struct ConversionFunction
{
    QStringList parameters;
    QString originalName;
    QString translatedName;
    bool isSelfActionNotDetainedByClass = false;
    QString receiver;
};

struct ConversionVariable
{
    bool isTranslated = false;
    QString originalType;
    QString translatedType;
    LinkType link = NORMAL;
    QHash<QString, ConversionFunction> functions;
};

class ClassTranslator;
class MessageTranslator;

class Translator
{
    friend ClassTranslator;
    friend MessageTranslator;

public:
    Translator();

    static FunctionData translateFunction(FunctionData function, QList<ClassVariable> classVariables, ClassInfos classInfos);
    static Variable translateVariable(Variable variable);
    static ClassVariable translateClassVariable(ClassVariable variable);
    static QString translateInclude(QString include);
    static QString translateConversion(QString line);

    static bool isKnown(const QString &className);

    static void addTranslated(const QString &className, bool isPointer = false);
    static void addTranslated(const QString &originalName, const QString &translatedName, bool isPointer = false);
    static void addFunction(const QString &className, const ConversionFunction &funct);
    static bool isTranslated(const QString &className);
    static LinkType getLinkType(const QString &className);

    static void addConversionVariable(const QString &originalType, const QString &translatedType, LinkType type = NORMAL);

private:
    static void init();

    static QString processMethod(QString line, QString varName, QMultiHash<QString, QString> variables);
    static QString translateMethod(QString varName, QString contained, QString functName, QList<QString> parameters, QMultiHash<QString, QString> variables);

    static QString fixLink(QString line);
    static QString fixMissingTypeBug(QString line, QMultiHash<QString, QString> &variables);

    static QHash<QString, ConversionVariable> m_variables;
    static bool m_isInit;
};

#endif // TRANSLATOR_H
