#include "InteractiveUseEndedMessage.h"

void InteractiveUseEndedMessage::serialize(Writer *param1)
{
  this->serializeAs_InteractiveUseEndedMessage(param1);
}

void InteractiveUseEndedMessage::serializeAs_InteractiveUseEndedMessage(Writer *param1)
{
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseEndedMessage -"<<"Forbidden value (" << this->elemId << ") on element elemId.";
  }
  else
  {
    param1->writeVarInt((int)this->elemId);
    if(this->skillId < 0)
    {
      qDebug()<<"ERREUR - InteractiveUseEndedMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
    }
    else
    {
      param1->writeVarShort((int)this->skillId);
      return;
    }
  }
}

void InteractiveUseEndedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InteractiveUseEndedMessage(param1);
}

void InteractiveUseEndedMessage::deserializeAs_InteractiveUseEndedMessage(Reader *param1)
{
  this->elemId = param1->readVarUhInt();
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseEndedMessage -"<<"Forbidden value (" << this->elemId << ") on element of InteractiveUseEndedMessage.elemId.";
  }
  else
  {
    this->skillId = param1->readVarUhShort();
    if(this->skillId < 0)
    {
      qDebug()<<"ERREUR - InteractiveUseEndedMessage -"<<"Forbidden value (" << this->skillId << ") on element of InteractiveUseEndedMessage.skillId.";
    }
    else
    {
      return;
    }
  }
}

InteractiveUseEndedMessage::InteractiveUseEndedMessage()
{
  m_type = MessageEnum::INTERACTIVEUSEENDEDMESSAGE;
}

