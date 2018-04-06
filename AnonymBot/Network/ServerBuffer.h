#ifndef SERVERBUFFER_H
#define SERVERBUFFER_H

#include "Public.h"
#include "Network/ServerMessages/AbstractServerMessage.h"
#include "System/Tools/IO/Reader.h"
#include "System/Tools/IO/Writer.h"

struct ServerMessageInfos
{
    ServerMessageEnum messageType;
    QByteArray messageData;
};

class ServerBuffer
{
public:
    ServerBuffer();

    void reset();

    static Writer writePacket(AbstractServerMessage &message);
    QList<ServerMessageInfos> readPacket(const QByteArray &packetData);

private:
    int m_remainingBytes;
    int m_part;
    ServerMessageInfos m_message;
};

#endif // SERVERBUFFER_H
