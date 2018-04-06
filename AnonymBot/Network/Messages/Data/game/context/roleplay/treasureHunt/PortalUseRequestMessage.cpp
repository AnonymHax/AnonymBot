#include "PortalUseRequestMessage.h"

void PortalUseRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PortalUseRequestMessage(param1);
}

void PortalUseRequestMessage::serializeAs_PortalUseRequestMessage(Writer *param1)
{
  if(this->portalId < 0)
  {
    qDebug()<<"ERREUR - PortalUseRequestMessage -"<<"Forbidden value (" << this->portalId << ") on element portalId.";
  }
  else
  {
    param1->writeVarInt((int)this->portalId);
    return;
  }
}

void PortalUseRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PortalUseRequestMessage(param1);
}

void PortalUseRequestMessage::deserializeAs_PortalUseRequestMessage(Reader *param1)
{
  this->portalId = param1->readVarUhInt();
  if(this->portalId < 0)
  {
    qDebug()<<"ERREUR - PortalUseRequestMessage -"<<"Forbidden value (" << this->portalId << ") on element of PortalUseRequestMessage.portalId.";
  }
  else
  {
    return;
  }
}

PortalUseRequestMessage::PortalUseRequestMessage()
{
  m_type = MessageEnum::PORTALUSEREQUESTMESSAGE;
}

