#include "Buffer.h"

Buffer::Buffer():
    m_part(0),
    m_remainingBytes(0)
{
}

void Buffer::reset()
{
    m_key.clear();
    m_message.messageData.clear();
    m_remainingBytes = 0;
}

void Buffer::generateRandomKey()
{
    m_key.clear();

    for(int i = 0; i < 8; i++)
        m_key.insert(i, 128);
}

Writer Buffer::writePacket(AbstractMessage &message)
{
    Writer temp;
    message.serialize(&temp);

    if(message.needHash() && !m_key.isEmpty())
        temp.writeBytes(m_hashManager.hashFunction(temp.getBuffer(), m_key));

    MessageInfos messageInfos;
    messageInfos.messageData = temp.getBuffer();
    messageInfos.messageType = message.getType();

    return writePacket(messageInfos);
}

Writer Buffer::writePacket(MessageInfos &message)
{
    qDebug()<<"-----------PACKET ENVOYE----------";

    ushort messageType = (ushort)message.messageType;

    int lengthType = 0; // On r�cup�re le lengthType en fonction de la taille.

    if (message.messageData.size() > 65535)
        lengthType = 3;

    else if (message.messageData.size() > 255)
        lengthType = 2;

    else if (message.messageData.size() > 0)
        lengthType = 1;


    ushort header = (ushort)(messageType << 2 | lengthType); // On cr�e le header

    Writer writer;
    writer.writeUShort(header); // On l'�crit

    // On �crit la longueur du message en fonction du lengthType

    if (lengthType == 1)
        writer.writeByte((char)(message.messageData.size()));

    else if (lengthType == 2)
        writer.writeUShort((ushort)(message.messageData.size()));

    else if (lengthType == 3)
    {
        uint size = writer.getSize();

        writer.writeByte(size >> 16);
        writer.writeByte(size >> 8);
        writer.writeByte(size - 256 * (size >> 8) - 256*256*(size >> 16));
    }

    writer.writeBytes(message.messageData); // Et on �crit le bytes de notre writer temporaire.

    qDebug()<<"Packet -"<<MessageUtils::getName(message.messageType)<<
              "- ID :"<<messageType<<
              "- Taille :"<<message.messageData.size()<<
              "- Type :" <<lengthType;

    return writer;
}

QList<MessageInfos> Buffer::readPacket(QByteArray packetData)
{
    QList<MessageInfos> messages;
    int messageTotalLength = 0;

    if (m_remainingBytes > 0)
    {
        m_part++;

        if (packetData.size() - m_remainingBytes >= 0)
        {
            m_message.messageData += packetData.mid(0,m_remainingBytes);
            messageTotalLength = m_remainingBytes;
            m_remainingBytes = 0;
            messages<<m_message;
        }

        else
        {
            m_message.messageData+= packetData.mid(0, packetData.size());
            messageTotalLength = packetData.size();
            m_remainingBytes -= packetData.size();
        }

        qDebug()<<"Packet -"<<MessageUtils::getName(m_message.messageType)<<
                  "- ID :"<<(int)m_message.messageType<<
                  "- Partie :"<<m_part;

        if (m_remainingBytes == 0)
        {
            qDebug()<<"-----------PACKET RECONSTITUE-------";
            qDebug()<<"Packet "<<messages.size()<<"-"<<MessageUtils::getName(m_message.messageType)<<
                      "- ID :"<<(int)m_message.messageType<<
                      "- Taille :"<<m_message.messageData.size();
        }
    }

    if (m_remainingBytes == 0 && messageTotalLength != packetData.size())
    {
        qDebug()<<"-----------PACKET(S) RECU ("<<packetData.size() - messageTotalLength<<")----------";

        while (messageTotalLength < packetData.size())
        {
            if(!m_incompleteHeader.isEmpty())
            {
                packetData.insert(0, m_incompleteHeader);
                m_incompleteHeader.clear();
            }

            QByteArray header = packetData.mid(messageTotalLength,2+3);
            int messageLength = 0;
            ushort hiheader = Reader(header, 2).readUShort();
            ushort packetID = hiheader >> 2;
            ushort lengthType = hiheader & 3;

            if(header.size() == 1 || (header.size() >=2 && header.size()-2 < lengthType))
            {
                qDebug()<<"Packet "<<messages.size()<<"-"<<MessageUtils::getName((MessageEnum)packetID)<<
                          "-  ID :"<<packetID<<" - Header incomplet - Partie 0";

                m_incompleteHeader = header;
                break;
            }

            else
            {
                Reader reader(packetData.mid(2+messageTotalLength,lengthType).data(),lengthType);

                if (lengthType == 1)
                    messageLength =  reader.readUByte();

                else if (lengthType == 2)
                    messageLength =  reader.readUShort();

                else if (lengthType == 3)
                    messageLength = (uint)(((reader.readUByte() & 255) << 16) + ((reader.readUByte() & 255) << 8) + (reader.readUByte() & 255));

                m_message.messageType = (MessageEnum)packetID;

                if (0 > packetData.size() - (messageTotalLength+messageLength+2+lengthType))
                {
                    m_part = 1;
                    m_remainingBytes = messageLength - (packetData.size() - (messageTotalLength+2+lengthType));
                    m_message.messageData =
                            packetData.mid(2+lengthType+messageTotalLength, packetData.size()-(messageTotalLength+2+lengthType));
                    messageTotalLength = packetData.size();

                    qDebug()<<"Packet "<<messages.size()+1<<"-"<<MessageUtils::getName((MessageEnum)packetID)<<
                              "- ID :"<<packetID<<
                              "- Taille Totale :"<<messageLength<<
                              "- Type :" <<lengthType<<
                              "- Partie :"<<m_part<<
                              "- Taille :"<<packetData.size();
                }

                else
                {
                    m_message.messageData = packetData.mid(2+lengthType+messageTotalLength, messageLength);
                    messages<<m_message;
                    messageTotalLength+=messageLength+2+lengthType;

                    qDebug()<<"Packet "<<messages.size()<<"-"<<MessageUtils::getName((MessageEnum)packetID)<<
                              "-  ID :"<<packetID<<
                              "- Taille :"<<messageLength<<
                              "- Type :" <<lengthType;
                }
            }
        }
    }

    return messages;
}
