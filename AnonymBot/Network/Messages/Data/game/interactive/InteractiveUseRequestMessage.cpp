#include "InteractiveUseRequestMessage.h"

void InteractiveUseRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_InteractiveUseRequestMessage(param1);
}

void InteractiveUseRequestMessage::serializeAs_InteractiveUseRequestMessage(Writer *param1)
{
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseRequestMessage -"<<"Forbidden value (" << this->elemId << ") on element elemId.";
  }
  else
  {
    param1->writeVarInt((int)this->elemId);
    if(this->skillInstanceUid < 0)
    {
      qDebug()<<"ERREUR - InteractiveUseRequestMessage -"<<"Forbidden value (" << this->skillInstanceUid << ") on element skillInstanceUid.";
    }
    else
    {
      param1->writeVarInt((int)this->skillInstanceUid);
      return;
    }
  }
}

void InteractiveUseRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_InteractiveUseRequestMessage(param1);
}

void InteractiveUseRequestMessage::deserializeAs_InteractiveUseRequestMessage(Reader *param1)
{
  this->elemId = param1->readVarUhInt();
  if(this->elemId < 0)
  {
    qDebug()<<"ERREUR - InteractiveUseRequestMessage -"<<"Forbidden value (" << this->elemId << ") on element of InteractiveUseRequestMessage.elemId.";
  }
  else
  {
    this->skillInstanceUid = param1->readVarUhInt();
    if(this->skillInstanceUid < 0)
    {
      qDebug()<<"ERREUR - InteractiveUseRequestMessage -"<<"Forbidden value (" << this->skillInstanceUid << ") on element of InteractiveUseRequestMessage.skillInstanceUid.";
    }
    else
    {
      return;
    }
  }
}

InteractiveUseRequestMessage::InteractiveUseRequestMessage()
{
  m_type = MessageEnum::INTERACTIVEUSEREQUESTMESSAGE;
  m_needsHash = true;
}

