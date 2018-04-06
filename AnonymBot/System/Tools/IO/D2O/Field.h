#pragma once

#include "System/Tools/IO/Reader.h"
#include "ClassDefinition.h"
#include <functional>

class I18nFile;

enum MemoryType
{
    _INT, _UINT, _DOUBLE, _BOOL, _STRING, _OBJECT, _ARRAY,
    LIST_INT, LIST_UINT, LIST_DOUBLE, LIST_BOOL, LIST_STRING, LIST_OBJECT,
    LISTLIST_INT, LISTLIST_UINT, LISTLIST_DOUBLE, LISTLIST_BOOL, LISTLIST_STRING, LISTLIST_OBJECT
};

class ClassDefinition;


class Field
{
public:
    Field(const QString &name, Reader *reader);

    void setClasses(QMap<int, ClassDefinition*> &classes, I18nFile *I18n);

    const QByteArray &getValue() const;
    MemoryType getType() const;
    const QString getName() const;
    ClassDefinition &getClassDefinition(int classId);

    void read(Reader *reader);

    QString toString() const;

private:
    MemoryType getType(const int &typeId);

    std::function<QByteArray (Reader*, const uint&)> getMethod(const int &methodType, Reader *reader);
    static QByteArray readObject(Reader *reader, const uint &dimention, Field *field);
    static QByteArray readVector(Reader *reader, const uint &dimention, Field *field);
    static QByteArray readInt(Reader *reader, const uint &dimention);
    static QByteArray readBoolean(Reader *reader, const uint &dimention);
    static QByteArray readUTF(Reader *reader, const uint &dimention);
    static QByteArray readDouble(Reader *reader, const uint &dimention);
    static QByteArray readI18nIndex(Reader *reader, const uint &dimention);
    static QByteArray readUInt(Reader *reader, const uint &dimention);

    std::function<QByteArray (Reader*, const uint&)> m_readMethod;
    QList< std::function<QByteArray (Reader*, const uint&)> > m_listMethod;
    QString m_name;
    QList<QString> m_listClasses;
    QByteArray m_value;
    MemoryType m_type;
    QList<int> m_typeId;
    QMap<int, ClassDefinition*> m_classes;
    I18nFile *m_I18n;
    const int m_nullId = -1431655766;
};
