#include "TeleportToBuddyOfferMessage.h"

void TeleportToBuddyOfferMessage::serialize(Writer *param1)
{
  this->serializeAs_TeleportToBuddyOfferMessage(param1);
}

void TeleportToBuddyOfferMessage::serializeAs_TeleportToBuddyOfferMessage(Writer *param1)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    if(this->buddyId < 0 || this->buddyId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->buddyId << ") on element buddyId.";
    }
    else
    {
      param1->writeVarLong((double)this->buddyId);
      if(this->timeLeft < 0)
      {
        qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->timeLeft << ") on element timeLeft.";
      }
      else
      {
        param1->writeVarInt((int)this->timeLeft);
        return;
      }
    }
  }
}

void TeleportToBuddyOfferMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TeleportToBuddyOfferMessage(param1);
}

void TeleportToBuddyOfferMessage::deserializeAs_TeleportToBuddyOfferMessage(Reader *param1)
{
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of TeleportToBuddyOfferMessage.dungeonId.";
  }
  else
  {
    this->buddyId = param1->readVarUhLong();
    if(this->buddyId < 0 || this->buddyId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->buddyId << ") on element of TeleportToBuddyOfferMessage.buddyId.";
    }
    else
    {
      this->timeLeft = param1->readVarUhInt();
      if(this->timeLeft < 0)
      {
        qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->timeLeft << ") on element of TeleportToBuddyOfferMessage.timeLeft.";
      }
      else
      {
        return;
      }
    }
  }
}

TeleportToBuddyOfferMessage::TeleportToBuddyOfferMessage()
{
  m_type = MessageEnum::TELEPORTTOBUDDYOFFERMESSAGE;
}

