#include "InteractiveUseErrorMessage.h"

void InteractiveUseErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_InteractiveUseErrorMessage(param1);
}

void InteractiveUseErrorMessage::serializeAs_InteractiveUseErrorMessage(Writer *param1)
{
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseErrorMessage -"<<"Forbidden value (" << this->elemId << ") on element elemId.";
  }
  else
  {
    param1->writeVarInt((int)this->elemId);
    if(this->skillInstanceUid < 0)
    {
      qDebug()<<"ERREUR - InteractiveUseErrorMessage -"<<"Forbidden value (" << this->skillInstanceUid << ") on element skillInstanceUid.";
    }
    else
    {
      param1->writeVarInt((int)this->skillInstanceUid);
      return;
    }
  }
}

void InteractiveUseErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InteractiveUseErrorMessage(param1);
}

void InteractiveUseErrorMessage::deserializeAs_InteractiveUseErrorMessage(Reader *param1)
{
  this->elemId = param1->readVarUhInt();
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseErrorMessage -"<<"Forbidden value (" << this->elemId << ") on element of InteractiveUseErrorMessage.elemId.";
  }
  else
  {
    this->skillInstanceUid = param1->readVarUhInt();
    if(this->skillInstanceUid < 0)
    {
      qDebug()<<"ERREUR - InteractiveUseErrorMessage -"<<"Forbidden value (" << this->skillInstanceUid << ") on element of InteractiveUseErrorMessage.skillInstanceUid.";
    }
    else
    {
      return;
    }
  }
}

InteractiveUseErrorMessage::InteractiveUseErrorMessage()
{
  m_type = MessageEnum::INTERACTIVEUSEERRORMESSAGE;
}

