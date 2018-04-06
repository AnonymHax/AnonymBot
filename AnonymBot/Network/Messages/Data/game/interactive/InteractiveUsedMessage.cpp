#include "InteractiveUsedMessage.h"

void InteractiveUsedMessage::serialize(Writer *param1)
{
  this->serializeAs_InteractiveUsedMessage(param1);
}

void InteractiveUsedMessage::serializeAs_InteractiveUsedMessage(Writer *param1)
{
  if(this->entityId < 0 || this->entityId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->entityId << ") on element entityId.";
  }
  else
  {
    param1->writeVarLong((double)this->entityId);
    if(this->elemId < 0)
    {
      qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->elemId << ") on element elemId.";
    }
    else
    {
      param1->writeVarInt((int)this->elemId);
      if(this->skillId < 0)
      {
        qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->skillId << ") on element skillId.";
      }
      else
      {
        param1->writeVarShort((int)this->skillId);
        if(this->duration < 0)
        {
          qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->duration << ") on element duration.";
        }
        else
        {
          param1->writeVarShort((int)this->duration);
          param1->writeBool(this->canMove);
          return;
        }
      }
    }
  }
}

void InteractiveUsedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InteractiveUsedMessage(param1);
}

void InteractiveUsedMessage::deserializeAs_InteractiveUsedMessage(Reader *param1)
{
  this->entityId = param1->readVarUhLong();
  if(this->entityId < 0 || this->entityId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->entityId << ") on element of InteractiveUsedMessage.entityId.";
  }
  else
  {
    this->elemId = param1->readVarUhInt();
    if(this->elemId < 0)
    {
      qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->elemId << ") on element of InteractiveUsedMessage.elemId.";
    }
    else
    {
      this->skillId = param1->readVarUhShort();
      if(this->skillId < 0)
      {
        qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->skillId << ") on element of InteractiveUsedMessage.skillId.";
      }
      else
      {
        this->duration = param1->readVarUhShort();
        if(this->duration < 0)
        {
          qDebug()<<"ERREUR - InteractiveUsedMessage -"<<"Forbidden value (" << this->duration << ") on element of InteractiveUsedMessage.duration.";
        }
        else
        {
          this->canMove = param1->readBool();
          return;
        }
      }
    }
  }
}

InteractiveUsedMessage::InteractiveUsedMessage()
{
  m_type = MessageEnum::INTERACTIVEUSEDMESSAGE;
}

