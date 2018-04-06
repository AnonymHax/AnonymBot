#include "Writer.h"

int Writer::INT_SIZE = 32;
int Writer::SHORT_SIZE = 16;
int Writer::SHORT_MIN_VALUE = -32768;
int Writer::SHORT_MAX_VALUE = 32767;
int Writer::UNSIGNED_SHORT_MAX_VALUE = 65536;
int Writer::CHUNCK_BIT_SIZE = 7;
int Writer::MAX_ENCODING_LENGTH = qCeil(Writer::INT_SIZE / Writer::CHUNCK_BIT_SIZE);
int Writer::MASK_10000000 = 128;
int Writer::MASK_01111111 = 127;

Writer::Writer()
{
    m_output = new QDataStream(&m_buffer, QIODevice::WriteOnly);
}

Writer::~Writer()
{
    delete m_output;
}

void Writer::reset()
{
    delete m_output;
    m_buffer.clear();
    m_output = new QDataStream(&m_buffer, QIODevice::WriteOnly);
}

int Writer::getPosition() const
{
    return m_output->device()->pos();
}

const QByteArray &Writer::getBuffer()
{
    return m_buffer;
}

int Writer::getSize()
{
    return m_buffer.size();
}

void Writer::writeByte(qint8 b)
{
    *m_output << b;
}

void Writer::writeBytes(const QByteArray &buffer)
{
    for (int i = 0; i < buffer.size(); i++)
        writeByte(buffer[i]);
}

void Writer::writeShort(qint16 s)
{
    *m_output << s;
}

void Writer::writeUShort(quint16 s)
{
    *m_output << s;
}

void Writer::writeInt(qint32 i)
{
    *m_output << i;
}

void Writer::writeUInt(quint32 i)
{
    *m_output << i;
}

void Writer::writeDouble(double d)
{
    *m_output << d;
}

void Writer::writeFloat(float f)
{
    *m_output << f;
}

void Writer::writeUTF(const QString unicodeData)
{
    writeUShort(unicodeData.toUtf8().size());
    writeUTFBytes(unicodeData);
}

void Writer::writeUTFBytes(const QString unicodeData)
{
    QByteArray utf8ByteArray = unicodeData.toUtf8();
    quint32 sizeToWrite = utf8ByteArray.size();
    m_output->writeRawData(utf8ByteArray.constData(), sizeToWrite);
}

void Writer::writeBool(bool b)
{
    *m_output << b;
}

void Writer::writeVarInt(int param1)
{
    int _loc5_ = 0;
    QByteArray _loc2_;

    if(param1 >= 0 && param1 <= MASK_01111111)
    {
        _loc2_[_loc2_.size()] = param1;
        writeBytes(_loc2_);
        return;
    }

    int _loc3_ = param1;
    QByteArray _loc4_;

    while(_loc3_ != 0)
    {
        _loc4_[_loc4_.size()] =  _loc3_ & MASK_01111111;
        _loc5_ = _loc4_[_loc4_.size() - 1];
        _loc3_ = (uint)_loc3_ >> CHUNCK_BIT_SIZE;

        if(_loc3_ > 0)
            _loc5_ = _loc5_ | MASK_10000000;

        _loc2_[_loc2_.size()] = _loc5_;
    }

    writeBytes(_loc2_);
}

void Writer::writeVarShort(quint16 param1)
{
    int _loc5_ = 0;
    if(param1 > SHORT_MAX_VALUE || param1 < SHORT_MIN_VALUE)
        qDebug()<<"ERREUR - Writer - Valeure interdite"<<param1;

    else
    {
        QByteArray _loc2_;

        if(param1 >= 0 && param1 <= MASK_01111111)
        {
            _loc2_[_loc2_.size()] = param1;
            writeBytes(_loc2_);
            return;
        }

        int _loc3_ = param1 & 65535;
        QByteArray _loc4_;

        while(_loc3_ != 0)
        {
            _loc4_[_loc4_.size()] = _loc3_ & MASK_01111111;
            _loc5_ = _loc4_[_loc4_.size()-1];
            _loc3_ = (uint)_loc3_ >> CHUNCK_BIT_SIZE;

            if(_loc3_ > 0)
                _loc5_ = _loc5_ | MASK_10000000;

            _loc2_[_loc2_.size()] = _loc5_;
        }

        writeBytes(_loc2_);
        return;
    }
}

void Writer::writeVarLong(double param1)
{
    uint _loc3_ = 0;
    SpecialInt _loc2_;
    _loc2_.low = param1;
    _loc2_.high = qFloor(param1/4.294967296E9);

    if(_loc2_.high == 0)
    {
        uint param2 = _loc2_.low;

        while(param2 >= 128)
        {
            writeByte(param2 & 127 | 128);
            param2 = param2 >> 7;
        }

        writeByte(param2);
    }

    else
    {
        _loc3_ = 0;

        while(_loc3_ < 4)
        {
            writeByte(_loc2_.low & 127 | 128);
            _loc2_.low = _loc2_.low >> 7;
            _loc3_++;
        }

        if((_loc2_.high & 268435455 << 3) == 0)
           writeByte(_loc2_.high << 4 | _loc2_.low);

        else
        {
            writeByte((_loc2_.high << 4 | _loc2_.low) & 127 | 128);
            uint param2 = _loc2_.high >> 3;

            while(param2 >= 128)
            {
                writeByte(param2 & 127 | 128);
                param2 = param2 >> 7;
            }

            writeByte(param2);
        }
    }
}

void Writer::setPosition(int i)
{
    m_output->device()->seek(i);
}
