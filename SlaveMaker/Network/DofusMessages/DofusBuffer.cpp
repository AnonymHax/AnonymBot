#include "DofusBuffer.h"

DofusBuffer::DofusBuffer():
    m_part(0),
    m_remainingBytes(0)
{
}

void DofusBuffer::reset()
{
    m_message.messageData.clear();
    m_remainingBytes = 0;
}

Writer DofusBuffer::writePacket(AbstractDofusMessage &message)
{
    qDebug()<<"-----------PACKET ENVOYE----------";
    ushort messageType = (ushort)message.getType();

    Writer temp;
    message.serialize(&temp);

    int lengthType = 0; // On r�cup�re le lengthType en fonction de la taille.

    if (temp.getSize() > 65535)
        lengthType = 3;

    else if (temp.getSize() > 255)
        lengthType = 2;

    else if (temp.getSize() > 0)
        lengthType = 1;


    ushort header = (ushort)(messageType << 2 | lengthType); // On cr�e le header

    Writer writer;
    writer.writeUShort(header); // On l'�crit

    // On �crit la longueur du message en fonction du lengthType

    if (lengthType == 1)
        writer.writeByte((char)(temp.getSize()));

    else if (lengthType == 2)
        writer.writeUShort((ushort)(temp.getSize()));

    else if (lengthType == 3)
    {
        uint size = temp.getSize();

        writer.writeByte(size >> 16);
        writer.writeByte(size >> 8);
        writer.writeByte(size - 256 * (size >> 8) - 256*256*(size >> 16));
    }

    writer.writeBytes(temp.getBuffer()); // Et on �crit le bytes de notre writer temporaire.

    qDebug()<<"Packet -  PacketID : "<<messageType<<
              "  Message's Length : "<<temp.getSize()<<
              "  LengType : " <<lengthType;

    return writer;
}

QList<DofusMessageInfos> DofusBuffer::readPacket(const QByteArray &packetData)
{
    QList<DofusMessageInfos> messages;
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

        qDebug()<<"Packet - ID : "<<(int)m_message.messageType<<
                  "Part : "<<m_part;

        if (m_remainingBytes == 0)
        {
            qDebug()<<"-----------PACKET RECONSTITUE-------";
            qDebug()<<"Packet "<<messages.size()<<"- PacketID : "<<(int)m_message.messageType<<
                      "  Message's Length : "<<m_message.messageData.size();
        }
    }

    if (m_remainingBytes == 0 && messageTotalLength != packetData.size())
    {
        qDebug()<<"-----------PACKET(S) RECU ("<<packetData.size() - messageTotalLength<<")----------";

        while (messageTotalLength < packetData.size())
        {
            int messageLength = 0;
            ushort hiheader = Reader(packetData.mid(messageTotalLength,2), 2).readUShort();
            ushort packetID = hiheader >> 2;
            ushort lengthType = hiheader & 3;

            Reader reader(packetData.mid(2+messageTotalLength,lengthType).data(),lengthType);

            if (lengthType == 1)
                messageLength =  reader.readUByte();

            else if (lengthType == 2)
                messageLength =  reader.readUShort();

            else if (lengthType == 3)
                messageLength = (uint)(((reader.readUByte() & 255) << 16) + ((reader.readUByte() & 255) << 8) + (reader.readUByte() & 255));

            m_message.messageType = (DofusMessageEnum)packetID;

            if (0 > packetData.size() - (messageTotalLength+messageLength+2+lengthType))
            {
                m_part = 1;
                m_remainingBytes = messageLength - (packetData.size() - (messageTotalLength+2+lengthType));
                m_message.messageData =
                        packetData.mid(2+lengthType+messageTotalLength, packetData.size()-(messageTotalLength+2+lengthType));
                messageTotalLength = packetData.size();

                qDebug()<<"Packet "<<messages.size()+1<<"-  PacketID : "<<packetID<<
                          "  Message's Length : "<<messageLength<<
                          "  LengType : " <<lengthType<<
                          "  Part :"<<m_part<<
                          "  PacketData Size"<<packetData.size();
            }

            else
            {
                m_message.messageData = packetData.mid(2+lengthType+messageTotalLength, messageLength);
                messages<<m_message;
                messageTotalLength+=messageLength+2+lengthType;

                qDebug()<<"Packet "<<messages.size()<<"-  PacketID : "<<packetID<<
                          "  Message's Length : "<<messageLength<<
                          "  LengType : " <<lengthType;
            }
        }
    }

    return messages;
}
