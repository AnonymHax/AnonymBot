#include "AllianceKickRequestMessage.h"

void AllianceKickRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceKickRequestMessage(param1);
}

void AllianceKickRequestMessage::serializeAs_AllianceKickRequestMessage(Writer *param1)
{
  if(this->kickedId < 0)
  {
    qDebug()<<"ERREUR - AllianceKickRequestMessage -"<<"Forbidden value (" << this->kickedId << ") on element kickedId.";
  }
  else
  {
    param1->writeVarInt((int)this->kickedId);
    return;
  }
}

void AllianceKickRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceKickRequestMessage(param1);
}

void AllianceKickRequestMessage::deserializeAs_AllianceKickRequestMessage(Reader *param1)
{
  this->kickedId = param1->readVarUhInt();
  if(this->kickedId < 0)
  {
    qDebug()<<"ERREUR - AllianceKickRequestMessage -"<<"Forbidden value (" << this->kickedId << ") on element of AllianceKickRequestMessage.kickedId.";
  }
  else
  {
    return;
  }
}

AllianceKickRequestMessage::AllianceKickRequestMessage()
{
  m_type = MessageEnum::ALLIANCEKICKREQUESTMESSAGE;
}

