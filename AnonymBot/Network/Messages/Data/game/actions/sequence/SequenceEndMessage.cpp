#include "SequenceEndMessage.h"

void SequenceEndMessage::serialize(Writer *param1)
{
  this->serializeAs_SequenceEndMessage(param1);
}

void SequenceEndMessage::serializeAs_SequenceEndMessage(Writer *param1)
{
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - SequenceEndMessage -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  else
  {
    param1->writeVarShort((int)this->actionId);
    if(this->authorId < -9.007199254740992E15 || this->authorId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - SequenceEndMessage -"<<"Forbidden value (" << this->authorId << ") on element authorId.";
    }
    else
    {
      param1->writeDouble(this->authorId);
      param1->writeByte(this->sequenceType);
      return;
    }
  }
}

void SequenceEndMessage::deserialize(Reader *param1)
{
  this->deserializeAs_SequenceEndMessage(param1);
}

void SequenceEndMessage::deserializeAs_SequenceEndMessage(Reader *param1)
{
  this->actionId = param1->readVarUhShort();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - SequenceEndMessage -"<<"Forbidden value (" << this->actionId << ") on element of SequenceEndMessage.actionId.";
  }
  else
  {
    this->authorId = param1->readDouble();
    if(this->authorId < -9.007199254740992E15 || this->authorId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - SequenceEndMessage -"<<"Forbidden value (" << this->authorId << ") on element of SequenceEndMessage.authorId.";
    }
    else
    {
      this->sequenceType = param1->readByte();
      return;
    }
  }
}

SequenceEndMessage::SequenceEndMessage()
{
  m_type = MessageEnum::SEQUENCEENDMESSAGE;
}

