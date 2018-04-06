#include "BasicAckMessage.h"

void BasicAckMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicAckMessage(param1);
}

void BasicAckMessage::serializeAs_BasicAckMessage(Writer *param1)
{
  if(this->seq < 0)
  {
    qDebug()<<"ERREUR - BasicAckMessage -"<<"Forbidden value (" << this->seq << ") on element seq.";
  }
  else
  {
    param1->writeVarInt((int)this->seq);
    if(this->lastPacketId < 0)
    {
      qDebug()<<"ERREUR - BasicAckMessage -"<<"Forbidden value (" << this->lastPacketId << ") on element lastPacketId.";
    }
    else
    {
      param1->writeVarShort((int)this->lastPacketId);
      return;
    }
  }
}

void BasicAckMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicAckMessage(param1);
}

void BasicAckMessage::deserializeAs_BasicAckMessage(Reader *param1)
{
  this->seq = param1->readVarUhInt();
  if(this->seq < 0)
  {
    qDebug()<<"ERREUR - BasicAckMessage -"<<"Forbidden value (" << this->seq << ") on element of BasicAckMessage.seq.";
  }
  else
  {
    this->lastPacketId = param1->readVarUhShort();
    if(this->lastPacketId < 0)
    {
      qDebug()<<"ERREUR - BasicAckMessage -"<<"Forbidden value (" << this->lastPacketId << ") on element of BasicAckMessage.lastPacketId.";
    }
    else
    {
      return;
    }
  }
}

BasicAckMessage::BasicAckMessage()
{
  m_type = MessageEnum::BASICACKMESSAGE;
}

