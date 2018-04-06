#include "SequenceNumberMessage.h"

void SequenceNumberMessage::serialize(Writer *param1)
{
  this->serializeAs_SequenceNumberMessage(param1);
}

void SequenceNumberMessage::serializeAs_SequenceNumberMessage(Writer *param1)
{
  if(this->number < 0 || this->number > 65535)
  {
    qDebug()<<"ERREUR - SequenceNumberMessage -"<<"Forbidden value (" << this->number << ") on element number.";
  }
  else
  {
    param1->writeShort((short)this->number);
    return;
  }
}

void SequenceNumberMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SequenceNumberMessage(param1);
}

void SequenceNumberMessage::deserializeAs_SequenceNumberMessage(Reader *param1)
{
  this->number = param1->readUShort();
  if(this->number < 0 || this->number > 65535)
  {
    qDebug()<<"ERREUR - SequenceNumberMessage -"<<"Forbidden value (" << this->number << ") on element of SequenceNumberMessage.number.";
  }
  else
  {
    return;
  }
}

SequenceNumberMessage::SequenceNumberMessage()
{
  m_type = MessageEnum::SEQUENCENUMBERMESSAGE;
}

