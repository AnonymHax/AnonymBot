#include "BasicStatMessage.h"

void BasicStatMessage::serialize(Writer *param1)
{
  this->serializeAs_BasicStatMessage(param1);
}

void BasicStatMessage::serializeAs_BasicStatMessage(Writer *param1)
{
  if(this->timeSpent < 0 || this->timeSpent > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BasicStatMessage -"<<"Forbidden value (" << this->timeSpent << ") on element timeSpent.";
  }
  else
  {
    param1->writeDouble(this->timeSpent);
    param1->writeVarShort((int)this->statId);
    return;
  }
}

void BasicStatMessage::deserialize(Reader *param1)
{
  this->deserializeAs_BasicStatMessage(param1);
}

void BasicStatMessage::deserializeAs_BasicStatMessage(Reader *param1)
{
  this->timeSpent = param1->readDouble();
  if(this->timeSpent < 0 || this->timeSpent > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - BasicStatMessage -"<<"Forbidden value (" << this->timeSpent << ") on element of BasicStatMessage.timeSpent.";
  }
  else
  {
    this->statId = param1->readVarUhShort();
    if(this->statId < 0)
    {
      qDebug()<<"ERREUR - BasicStatMessage -"<<"Forbidden value (" << this->statId << ") on element of BasicStatMessage.statId.";
    }
    else
    {
      return;
    }
  }
}

BasicStatMessage::BasicStatMessage()
{
  m_type = MessageEnum::BASICSTATMESSAGE;
}

