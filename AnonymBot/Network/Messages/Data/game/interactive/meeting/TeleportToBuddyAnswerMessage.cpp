#include "TeleportToBuddyAnswerMessage.h"

void TeleportToBuddyAnswerMessage::serialize(Writer *param1)
{
  this->serializeAs_TeleportToBuddyAnswerMessage(param1);
}

void TeleportToBuddyAnswerMessage::serializeAs_TeleportToBuddyAnswerMessage(Writer *param1)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyAnswerMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    if(this->buddyId < 0 || this->buddyId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TeleportToBuddyAnswerMessage -"<<"Forbidden value (" << this->buddyId << ") on element buddyId.";
    }
    else
    {
      param1->writeVarLong((double)this->buddyId);
      param1->writeBool(this->accept);
      return;
    }
  }
}

void TeleportToBuddyAnswerMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TeleportToBuddyAnswerMessage(param1);
}

void TeleportToBuddyAnswerMessage::deserializeAs_TeleportToBuddyAnswerMessage(Reader *param1)
{
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyAnswerMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of TeleportToBuddyAnswerMessage.dungeonId.";
  }
  else
  {
    this->buddyId = param1->readVarUhLong();
    if(this->buddyId < 0 || this->buddyId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TeleportToBuddyAnswerMessage -"<<"Forbidden value (" << this->buddyId << ") on element of TeleportToBuddyAnswerMessage.buddyId.";
    }
    else
    {
      this->accept = param1->readBool();
      return;
    }
  }
}

TeleportToBuddyAnswerMessage::TeleportToBuddyAnswerMessage()
{
  m_type = MessageEnum::TELEPORTTOBUDDYANSWERMESSAGE;
}

