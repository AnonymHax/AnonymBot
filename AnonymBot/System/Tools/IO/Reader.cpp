#include "Reader.h"

int Reader::INT_SIZE = 32;
int Reader::SHORT_SIZE = 16;
int Reader::SHORT_MIN_VALUE = -32768;
int Reader::SHORT_MAX_VALUE = 32767;
int Reader::UNSIGNED_SHORT_MAX_VALUE = 65536;
int Reader::CHUNCK_BIT_SIZE = 7;
int Reader::MAX_ENCODING_LENGTH = qCeil(Reader::INT_SIZE / Reader::CHUNCK_BIT_SIZE);
int Reader::MASK_10000000 = 128;
int Reader::MASK_01111111 = 127;

Reader::Reader():
    m_isUsingFile(false)
{
    m_input = new QDataStream(&m_buffer, QIODevice::ReadOnly);
}

Reader::Reader(const char *buffer, int size):
    m_isUsingFile(false),
    m_buffer(QByteArray(buffer, size))
{
    m_input = new QDataStream(&m_buffer, QIODevice::ReadOnly);
}


Reader::Reader(const QByteArray &buffer):
    m_isUsingFile(false),
    m_buffer(buffer)
{
    m_input = new QDataStream(&m_buffer, QIODevice::ReadOnly);
}

Reader::Reader(const QString &path):
    m_isUsingFile(true)
{
    QFile *file = new QFile(path);

    if (!file->open(QIODevice::ReadOnly))
        qDebug()<<"ERREUR - Reader - N'arrive pas à ouvrir le chemin :"<<path;

    m_input = new QDataStream(file);
}

Reader::~Reader()
{
    if(m_isUsingFile)
        delete m_input->device();
    delete m_input;
}

void Reader::setBuffer(const char *buffer, int size)
{
    if(m_isUsingFile)
        delete m_input->device();
    m_isUsingFile = false;
    delete m_input;
    setBuffer(QByteArray(buffer, size));
}

void Reader::setBuffer(const QByteArray &buffer)
{
    if(m_isUsingFile)
        delete m_input->device();
    m_isUsingFile = false;
    delete m_input;
    m_buffer = buffer;
    m_input = new QDataStream(&m_buffer, QIODevice::ReadOnly);
}

void Reader::setBuffer(const QString &path)
{
    m_buffer.clear();
    if(m_isUsingFile)
        delete m_input->device();
    m_isUsingFile = true;

    QFile *file = new QFile(path);

    if (!file->open(QIODevice::ReadOnly))
        qDebug()<<"ERREUR - Reader - N'a pas pu ouvrir "<<path;

    m_input->setDevice(file);
}

void Reader::setPosition(int pos)
{
    m_input->device()->seek(pos);
}

int Reader::getPosition() const
{
    return m_input->device()->pos();
}

int Reader::getSize() const
{
    return m_input->device()->size();
}

int Reader::getAvailableBytes() const
{
    return m_input->device()->bytesAvailable();
}

short Reader::readShort()
{
    qint16 shortData;
    *m_input >> shortData;
    return shortData;
}

ushort Reader::readUShort()
{
    quint16 uShortData;
    *m_input >> uShortData;
    return uShortData;
}

char Reader::readByte()
{
    qint8 byteData;
    *m_input >> byteData;
    return byteData;
}

QByteArray Reader::readBytes(int length, int offset)
{
    QByteArray s;

    if(length == 0)
        length = m_input->device()->bytesAvailable();

    for (int i = offset; i < length; i++)
        s.append(readByte());

    return s;
}

uchar Reader::readUByte()
{
    quint8 uByteData;
    *m_input >> uByteData;
    return uByteData;
}


int Reader::readInt()
{
    qint32 intData;
    *m_input >> intData;
    return intData;
}

uint Reader::readUInt()
{
    quint32 UIntData;
    *m_input >> UIntData;
    return UIntData;
}

QString Reader::readUTF()
{
    ushort length = readUShort();
    QByteArray unicodeArray;
    for(quint16 index(0); index < length; index++)
        unicodeArray.append(readByte());
    return QString::fromUtf8(unicodeArray);
}

QString Reader::readUTFBytes(int size)
{
    QByteArray unicodeArray;

    if (!size)
    {
        do
            unicodeArray.append(readByte());
        while (unicodeArray[unicodeArray.size()-1] != '\0');
    }

    else
    {
        for (int i = 0; i < size; i++)
            unicodeArray.append(readByte());
    }

    return QString::fromUtf8(unicodeArray);
}

bool Reader::readBool()
{
    return readByte() == 1 ? true : false;
}


double Reader::readDouble()
{
    double doubleData;
    *m_input >> doubleData;
    return doubleData;
}

float Reader::readFloat()
{
    float floatData;
    *m_input >> floatData;
    return floatData;
}

int Reader::readVarInt()
{
    char _loc4_ = 0;
    int _loc1_ = 0;
    int _loc2_ = 0;
    bool _loc3_ = false;

    while(_loc2_ < INT_SIZE)
    {
        _loc4_ = readByte();

        _loc3_ = (_loc4_ & MASK_10000000) == MASK_10000000;

        if(_loc2_ > 0)
            _loc1_ += ((_loc4_ & MASK_01111111) << _loc2_);

        else
            _loc1_ += (_loc4_ & MASK_01111111);

        _loc2_ += CHUNCK_BIT_SIZE;

        if(!_loc3_)
            return _loc1_;
    }

    qDebug()<<"ERREUR - Reader - readVarInt - Il y a trop de données";
}

uint Reader::readVarUhInt()
{
    return readVarInt();
}

short Reader::readVarShort()
{
    int _loc4_ = 0;
    int _loc1_ = 0;
    int _loc2_ = 0;
    bool _loc3_ = false;

    while(_loc2_ < SHORT_SIZE)
    {
        _loc4_ = readByte();
        _loc3_ = (_loc4_ & MASK_10000000) == MASK_10000000;

        if(_loc2_ > 0)
            _loc1_ += ((_loc4_ & MASK_01111111) << _loc2_);

        else
            _loc1_ += (_loc4_ & MASK_01111111);

        _loc2_ += CHUNCK_BIT_SIZE;

        if(!_loc3_)
        {
            if(_loc1_ > SHORT_MAX_VALUE)
                _loc1_ -= UNSIGNED_SHORT_MAX_VALUE;

            return _loc1_;
        }
    }

    qDebug()<<"ERREUR - Reader - readVarShort - Il y a trop de données";
}

ushort Reader::readVarUhShort()
{
    return readVarShort();
}

double Reader::readVarLong()
{
    uint _loc3_= 0;
    SpecialInt _loc2_;
    uint _loc4_ = 0;

    while(true)
    {
        _loc3_ = readUByte();

        if(_loc4_ == 28)
            break;

        if(_loc3_ >= 128)
        {
            _loc2_.low = _loc2_.low | (_loc3_ & 127) << _loc4_;
            _loc4_ = _loc4_ + 7;
            continue;
        }

        _loc2_.low = _loc2_.low | _loc3_ << _loc4_;
        return _loc2_.high * 4.294967296E9 + _loc2_.low;
    }

    if(_loc3_ >= 128)
    {
        _loc3_ = _loc3_ & 127;
        _loc2_.low = _loc2_.low | _loc3_ << _loc4_;
        _loc2_.high = _loc3_ >> 4;
        _loc4_ = 3;

        while(true)
        {
            _loc3_ = readUByte();

            if(_loc4_ < 32)
            {
                if(_loc3_ >= 128)
                    _loc2_.high = _loc2_.high | (_loc3_ & 127) << _loc4_;

                else
                    break;
            }

            _loc4_ += 7;
        }

        _loc2_.high = _loc2_.high | _loc3_ << _loc4_;

        return _loc2_.high * 4.294967296E9 + _loc2_.low;
    }

    _loc2_.low = _loc2_.low | _loc3_ << _loc4_;
    _loc2_.high = _loc3_ >> 4;
    return _loc2_.high * 4.294967296E9 + _loc2_.low;
}

double Reader::readVarUhLong()
{
    uint _loc3_ = 0;
    SpecialInt _loc2_;
    uint _loc4_ = 0;
    while(true)
    {
        _loc3_ = readUByte();
        if(_loc4_ == 28)
            break;

        if(_loc3_ >= 128)
        {
            _loc2_.low = _loc2_.low | (_loc3_ & 127) << _loc4_;
            _loc4_ = _loc4_ + 7;
            continue;
        }
        _loc2_.low = _loc2_.low | _loc3_ << _loc4_;
        return _loc2_.high * 4.294967296E9 + _loc2_.low;
    }

    if(_loc3_ >= 128)
    {
        _loc3_ = _loc3_ & 127;
        _loc2_.low = _loc2_.low | _loc3_ << _loc4_;
        _loc2_.high = _loc3_ >> 4;
        _loc4_ = 3;

        while(true)
        {
            _loc3_ = readUByte();

            if(_loc4_ < 32)
            {
                if(_loc3_ >= 128)
                    _loc2_.high = _loc2_.high | (_loc3_ & 127) << _loc4_;

                else
                    break;
            }

            _loc4_ += 7;
        }

        _loc2_.high = _loc2_.high | _loc3_ << _loc4_;
        return _loc2_.high * 4.294967296E9 + _loc2_.low;
    }

    _loc2_.low = _loc2_.low | _loc3_ << _loc4_;
    _loc2_.high = _loc3_ >> 4;
    return _loc2_.high * 4.294967296E9 + _loc2_.low;
}
