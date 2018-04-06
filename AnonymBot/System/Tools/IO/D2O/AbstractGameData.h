#ifndef ABSTRACTGAMEDATA_H
#define ABSTRACTGAMEDATA_H

#include "Public.h"
#include "System/Tools/IO/Reader.h"
#include "System/Tools/IO/D2O/GameDataTypeDeclarator.h"
#include "System/Tools/IO/I18n/I18nFile.h"
#include "System/Tools/IO/D2O/Field.h"

class AbstractGameData
{
public:
    AbstractGameData();
    virtual ~AbstractGameData();

    virtual void loadData(const QList<Field*> &fields, I18nFile *I18n) = 0;

protected:
    QSharedPointer<AbstractGameData> readObject(const QByteArray &data, Field *field);
    QList<QByteArray> readVector(const QByteArray &data);
    uint readUInt(const QByteArray &data);
    int readInt(const QByteArray &data);
    bool readBool(const QByteArray &data);
    QString readUTF(const QByteArray &data);
    double readDouble(const QByteArray &data);

    I18nFile *m_I18n;
};

#endif // ABSTRACTGAMEDATA_H
