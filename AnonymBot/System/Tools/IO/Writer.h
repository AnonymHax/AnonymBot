#ifndef WRITER_H
#define WRITER_H

#include "Public.h"

class Writer
{
public:
    Writer();
    ~Writer();

    void reset();
    void setPosition(int);
    int getPosition() const;
    const QByteArray &getBuffer();
    int getSize();

    void writeByte(qint8);
    void writeBytes(const QByteArray &buffer);
    void writeShort(qint16);
    void writeUShort(quint16);
    void writeInt(qint32);
    void writeUInt(quint32);
    void writeDouble(double);
    void writeFloat(float);
    void writeUTF(const QString unicodeData);
    void writeUTFBytes(const QString unicodeData);
    void writeBool(bool);
    void writeVarInt(int);
    void writeVarShort(quint16);
    void writeVarLong(double);

private:
    QDataStream *m_output;
    QByteArray m_buffer;

    static int INT_SIZE;
    static int SHORT_SIZE;
    static int SHORT_MIN_VALUE;
    static int SHORT_MAX_VALUE;
    static int UNSIGNED_SHORT_MAX_VALUE;
    static int CHUNCK_BIT_SIZE;
    static int MAX_ENCODING_LENGTH;
    static int MASK_10000000;
    static int MASK_01111111;
};

#endif // WRITER_H

