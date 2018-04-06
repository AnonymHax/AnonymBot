#include "ClassDefinition.h"
#include "System/Tools/IO/D2O/GameDataConverter.h"

ClassDefinition::ClassDefinition(const QString &className):
    m_className(className)
{
}

void ClassDefinition::addField(const QString &fieldName, Reader *reader)
{
    m_fields<<new Field(fieldName, reader);
}

ClassDefinition::~ClassDefinition()
{
    foreach(Field *field, m_fields)
        delete field;
}

void ClassDefinition::setField(QMap<int, ClassDefinition*> &classes, I18nFile *I18n)
{
    for (int i = 0; i < m_fields.size(); i++)
        m_fields[i]->setClasses(classes, I18n);
}

QSharedPointer<AbstractGameData> ClassDefinition::read(Reader *reader, I18nFile *I18n)
{
    foreach (Field *field, m_fields)
        field->read(reader);

    QSharedPointer<AbstractGameData> gameData = GameDataConverter::getClass(m_className);

    if(gameData != NULL)
        gameData->loadData(m_fields, I18n);

    return gameData;
}
