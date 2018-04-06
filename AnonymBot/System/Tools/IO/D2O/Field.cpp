#include "Field.h"

Field::Field(const QString &name, Reader *reader):
    m_name(name)
{
    int readType = reader->readInt();
    m_readMethod = getMethod(readType, reader);
    m_type = getType(readType);
}

const QByteArray &Field::getValue() const
{
    return m_value;
}

MemoryType Field::getType() const
{
    return m_type;
}

const QString Field::getName() const
{
    return m_name;
}

ClassDefinition &Field::getClassDefinition(int classId)
{
    return *m_classes[classId];
}

void Field::setClasses(QMap<int, ClassDefinition*> &classes, I18nFile *I18n)
{
    m_classes = classes;
    m_I18n = I18n;
}

MemoryType Field::getType(const int &typeId)
{
    switch (typeId)
    {
    case -1:
        return _INT;

    case -2:
        return _BOOL;

    case -3:
        return _STRING;

    case -4:
        return _DOUBLE;

    case -5:
        return _INT;

    case -6:
        return _UINT;

    case -99:
        switch (m_typeId[0])
        {
        case -1:
            return LIST_INT;
        case -2:
            return LIST_BOOL;
        case -3:
            return LIST_STRING;
        case -4:
            return LIST_DOUBLE;
        case -5:
            return LIST_INT;
        case -6:
            return LIST_UINT;
        case -99:
            switch (m_typeId[1])
            {
            case -1:
                return LISTLIST_INT;
            case -2:
                return LISTLIST_BOOL;
            case -3:
                return LISTLIST_STRING;
            case -4:
                return LISTLIST_DOUBLE;
            case -5:
                return LISTLIST_INT;
            case -6:
                return LISTLIST_UINT;
            case -99:
                return LIST_OBJECT;
            default:
                return LISTLIST_OBJECT;
            }
        default:
            return LIST_OBJECT;
        }

    default :
        return _OBJECT;
    }
}

std::function<QByteArray (Reader*, const uint&)> Field::getMethod(const int &methodType, Reader *reader)
{
    switch (methodType)
    {
    case -1:
        return readInt;

    case -2:
        return readBoolean;

    case -3:
        return readUTF;

    case -4:
        return readDouble;

    case -5:
        return readI18nIndex;

    case -6:
        return readUInt;

    case -99: {
        m_listClasses.push_back(reader->readUTF());
        m_typeId.push_back(reader->readInt());
        m_listMethod.insert(0,getMethod(m_typeId.last(), reader));
        return std::function<QByteArray (Reader*, const uint&)>  (std::bind(readVector, std::placeholders::_1, std::placeholders::_2, this));  }

    default: {
        if (methodType > 0)
            return std::function<QByteArray (Reader*, const uint&)>  (std::bind(readObject, std::placeholders::_1, std::placeholders::_2, this));
        qDebug()<<"Unknown type :"<<methodType; }
    }
}

void Field::read(Reader *reader)
{
    m_value = m_readMethod(reader, 0);
}

QByteArray Field::readObject(Reader *reader, const uint &dimention, Field *field)
{
    int startIndex = reader->getPosition();
    int classId = reader->readInt();
    field->getClassDefinition(classId).read(reader, field->m_I18n);
    int endIndex = reader->getPosition();

    reader->setPosition(startIndex);

    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readBytes(endIndex-startIndex);
    return buffer.data();
}

QByteArray Field::readVector(Reader *reader, const uint &dimention, Field *field)
{
    int listCount = reader->readUInt();
    QList<QByteArray> list;
    for (int i = 0; i < listCount; i++)
        list.append(field->m_listMethod[(int)dimention](reader, dimention + 1));

    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<list;
    return buffer.data();
}

QByteArray Field::readInt(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readUInt();
    return buffer.data();
}

QByteArray Field::readBoolean(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readBool();
    return buffer.data();
}

QByteArray Field::readUTF(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readUTF();
    return buffer.data();
}

QByteArray Field::readDouble(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readDouble();
    return buffer.data();
}

QByteArray Field::readI18nIndex(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readUInt();
    return buffer.data();
}

QByteArray Field::readUInt(Reader *reader, const uint &dimention)
{
    QBuffer buffer;
    QDataStream stream(&buffer);
    buffer.open(QIODevice::WriteOnly);
    stream<<reader->readUInt();
    return buffer.data();
}


QString Field::toString() const
{
    return getName();
    //return QString::Format("{0} AS {1}", getName(), getType()->Name);
}
