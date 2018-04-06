#ifndef BUFFER_H
#define BUFFER_H

#include "Public.h"
#include "Network/Messages/MessageDeclarator.h"
#include "Network/Messages/MessageUtils.h"
#include "System/Tools/IO/Reader.h"
#include "System/Tools/IO/Writer.h"
#include "System/Tools/Security/AesManager.h"

struct MessageInfos
{
    MessageEnum messageType;
    QByteArray messageData;
};

class Buffer
{
public:
    Buffer();

    void reset();
    void generateRandomKey();

    Writer writePacket(MessageInfos &message);
    Writer writePacket(AbstractMessage &message);
    QList<MessageInfos> readPacket(QByteArray packetData);

private:
    AesManager m_hashManager;
    QByteArray m_key;
    int m_remainingBytes;
    QByteArray m_incompleteHeader;
    int m_part;
    MessageInfos m_message;
};

#endif // BUFFER_H
