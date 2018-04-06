#include "TeleportBuddiesMessage.h"

void TeleportBuddiesMessage::serialize(Writer *param1)
{
  this->serializeAs_TeleportBuddiesMessage(param1);
}

void TeleportBuddiesMessage::serializeAs_TeleportBuddiesMessage(Writer *param1)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportBuddiesMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    return;
  }
}

void TeleportBuddiesMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TeleportBuddiesMessage(param1);
}

void TeleportBuddiesMessage::deserializeAs_TeleportBuddiesMessage(Reader *param1)
{
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportBuddiesMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of TeleportBuddiesMessage.dungeonId.";
  }
  else
  {
    return;
  }
}

TeleportBuddiesMessage::TeleportBuddiesMessage()
{
  m_type = MessageEnum::TELEPORTBUDDIESMESSAGE;
}

