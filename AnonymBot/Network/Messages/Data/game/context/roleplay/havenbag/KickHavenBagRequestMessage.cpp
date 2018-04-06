#include "KickHavenBagRequestMessage.h"

void KickHavenBagRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_KickHavenBagRequestMessage(param1);
}

void KickHavenBagRequestMessage::serializeAs_KickHavenBagRequestMessage(Writer *param1)
{
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - KickHavenBagRequestMessage -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
  }
  else
  {
    param1->writeVarLong((double)this->guestId);
    return;
  }
}

void KickHavenBagRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_KickHavenBagRequestMessage(param1);
}

void KickHavenBagRequestMessage::deserializeAs_KickHavenBagRequestMessage(Reader *param1)
{
  this->guestId = param1->readVarUhLong();
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - KickHavenBagRequestMessage -"<<"Forbidden value (" << this->guestId << ") on element of KickHavenBagRequestMessage.guestId.";
  }
  else
  {
    return;
  }
}

KickHavenBagRequestMessage::KickHavenBagRequestMessage()
{
  m_type = MessageEnum::KICKHAVENBAGREQUESTMESSAGE;
}

