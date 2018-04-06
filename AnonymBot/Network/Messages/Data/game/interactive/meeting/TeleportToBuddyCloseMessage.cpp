#include "TeleportToBuddyCloseMessage.h"

void TeleportToBuddyCloseMessage::serialize(Writer *param1)
{
  this->serializeAs_TeleportToBuddyCloseMessage(param1);
}

void TeleportToBuddyCloseMessage::serializeAs_TeleportToBuddyCloseMessage(Writer *param1)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyCloseMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    if(this->buddyId < 0 || this->buddyId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TeleportToBuddyCloseMessage -"<<"Forbidden value (" << this->buddyId << ") on element buddyId.";
    }
    else
    {
      param1->writeVarLong((double)this->buddyId);
      return;
    }
  }
}

void TeleportToBuddyCloseMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TeleportToBuddyCloseMessage(param1);
}

void TeleportToBuddyCloseMessage::deserializeAs_TeleportToBuddyCloseMessage(Reader *param1)
{
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyCloseMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of TeleportToBuddyCloseMessage.dungeonId.";
  }
  else
  {
    this->buddyId = param1->readVarUhLong();
    if(this->buddyId < 0 || this->buddyId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TeleportToBuddyCloseMessage -"<<"Forbidden value (" << this->buddyId << ") on element of TeleportToBuddyCloseMessage.buddyId.";
    }
    else
    {
      return;
    }
  }
}

TeleportToBuddyCloseMessage::TeleportToBuddyCloseMessage()
{
  m_type = MessageEnum::TELEPORTTOBUDDYCLOSEMESSAGE;
}

