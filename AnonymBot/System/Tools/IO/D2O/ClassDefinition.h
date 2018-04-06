#pragma once

#include "System/Tools/IO/Reader.h"

class Field;
class I18nFile;
class AbstractGameData;

class ClassDefinition
{
public:
    ClassDefinition(const QString &className);
    ~ClassDefinition();

    void addField(const QString &fieldName, Reader *reader);

    void setField(QMap<int, ClassDefinition *> &classes, I18nFile *I18n);

    QSharedPointer<AbstractGameData> read(Reader *reader, I18nFile *I18n);


private:    
    QString m_className;
    QList<Field*> m_fields;
};
