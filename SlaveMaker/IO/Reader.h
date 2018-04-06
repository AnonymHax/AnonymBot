#ifndef READER_H
#define READER_H

#include "Public.h"

class Reader
{
public:
    Reader();
    Reader(const char *buffer, int size);
    Reader(const QByteArray &buffer);
    Reader(const QString &path);

    ~Reader();

    void setBuffer(const char *buffer, int size);
    void setBuffer(const QByteArray &buffer);
    void setBuffer(const QString &path);
    void setPosition(int pos);

    int getPosition() const;
    int getSize() const;
    int getAvailableBytes() const;

    short readShort();
    ushort readUShort();
    char readByte();
    uchar readUByte();
    QByteArray readBytes(int length = 0, int offset = 0);
    int readInt();
    uint readUInt();
    QString readUTF();
    QString readUTFBytes(int size = 0);
    bool readBool();
    double readDouble();
    float readFloat();
    int readVarInt();
    uint readVarUhInt();
    short readVarShort();
    ushort readVarUhShort();
    double readVarLong();
    double readVarUhLong();

private:


    QDataStream *m_input;
    QByteArray m_buffer;
    bool m_isUsingFile;

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

#endif // READER_H
