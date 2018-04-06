#include "AbstractGameData.h"

AbstractGameData::AbstractGameData():
    m_I18n(NULL)
{
}

AbstractGameData::~AbstractGameData()
{
}

QSharedPointer<AbstractGameData> AbstractGameData::readObject(const QByteArray &data, Field *field)
{
    QByteArray convertedData;
    QDataStream stream(data);
    stream >> convertedData;

    Reader reader(convertedData);

    return field->getClassDefinition(reader.readInt()).read(&reader, m_I18n);
}

QList<QByteArray> AbstractGameData::readVector(const QByteArray &data)
{
    QList<QByteArray> convertedData;
    QDataStream stream(data);
    stream >> convertedData;
    return convertedData;
}

uint AbstractGameData::readUInt(const QByteArray &data)
{
    uint convertedData;
    QDataStream stream(data);
    stream >> convertedData;
    return convertedData;
}

int AbstractGameData::readInt(const QByteArray &data)
{
    int convertedData;
    QDataStream stream(data);
    stream >> convertedData;
    return convertedData;
}

bool AbstractGameData::readBool(const QByteArray &data)
{
    bool convertedData;
    QDataStream stream(data);
    stream >> convertedData;
    return convertedData;
}

QString AbstractGameData::readUTF(const QByteArray &data)
{
    QString convertedData;
    QDataStream stream(data);
    stream >> convertedData;
    return convertedData;
}

double AbstractGameData::readDouble(const QByteArray &data)
{
    double convertedData;
    QDataStream stream(data);
    stream >> convertedData;
    return convertedData;
}
