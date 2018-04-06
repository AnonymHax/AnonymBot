#ifndef BUFFER_H
#define BUFFER_H

#include "Public.h"
#include "Network/DofusMessages/AbstractDofusMessage.h"
#include "IO/Reader.h"
#include "IO/Writer.h"

struct DofusMessageInfos
{
    DofusMessageEnum messageType;
    QByteArray messageData;
};

class DofusBuffer
{
public:
    DofusBuffer();

    void reset();

    Writer writePacket(AbstractDofusMessage &message);
    QList<DofusMessageInfos> readPacket(const QByteArray &packetData);

private:
    int m_remainingBytes;
    int m_part;
    DofusMessageInfos m_message;
};

#endif // BUFFER_H
