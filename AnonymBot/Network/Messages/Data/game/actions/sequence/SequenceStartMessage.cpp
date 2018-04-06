#include "SequenceStartMessage.h"

void SequenceStartMessage::serialize(Writer *param1)
{
  this->serializeAs_SequenceStartMessage(param1);
}

void SequenceStartMessage::serializeAs_SequenceStartMessage(Writer *param1)
{
  param1->writeByte(this->sequenceType);
  if(this->authorId < -9.007199254740992E15 || this->authorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SequenceStartMessage -"<<"Forbidden value (" << this->authorId << ") on element authorId.";
  }
  else
  {
    param1->writeDouble(this->authorId);
    return;
  }
}

void SequenceStartMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SequenceStartMessage(param1);
}

void SequenceStartMessage::deserializeAs_SequenceStartMessage(Reader *param1)
{
  this->sequenceType = param1->readByte();
  this->authorId = param1->readDouble();
  if(this->authorId < -9.007199254740992E15 || this->authorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SequenceStartMessage -"<<"Forbidden value (" << this->authorId << ") on element of SequenceStartMessage.authorId.";
  }
  else
  {
    return;
  }
}

SequenceStartMessage::SequenceStartMessage()
{
  m_type = MessageEnum::SEQUENCESTARTMESSAGE;
}

