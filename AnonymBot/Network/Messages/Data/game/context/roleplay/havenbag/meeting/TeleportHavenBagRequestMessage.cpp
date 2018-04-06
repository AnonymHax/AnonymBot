#include "TeleportHavenBagRequestMessage.h"

void TeleportHavenBagRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_TeleportHavenBagRequestMessage(param1);
}

void TeleportHavenBagRequestMessage::serializeAs_TeleportHavenBagRequestMessage(Writer *param1)
{
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportHavenBagRequestMessage -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
  }
  else
  {
    param1->writeVarLong((double)this->guestId);
    return;
  }
}

void TeleportHavenBagRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TeleportHavenBagRequestMessage(param1);
}

void TeleportHavenBagRequestMessage::deserializeAs_TeleportHavenBagRequestMessage(Reader *param1)
{
  this->guestId = param1->readVarUhLong();
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportHavenBagRequestMessage -"<<"Forbidden value (" << this->guestId << ") on element of TeleportHavenBagRequestMessage.guestId.";
  }
  else
  {
    return;
  }
}

TeleportHavenBagRequestMessage::TeleportHavenBagRequestMessage()
{
  m_type = MessageEnum::TELEPORTHAVENBAGREQUESTMESSAGE;
}

