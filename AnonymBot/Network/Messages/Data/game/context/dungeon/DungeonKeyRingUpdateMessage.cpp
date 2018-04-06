#include "DungeonKeyRingUpdateMessage.h"

void DungeonKeyRingUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_DungeonKeyRingUpdateMessage(param1);
}

void DungeonKeyRingUpdateMessage::serializeAs_DungeonKeyRingUpdateMessage(Writer *param1)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonKeyRingUpdateMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    param1->writeBool(this->available);
    return;
  }
}

void DungeonKeyRingUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DungeonKeyRingUpdateMessage(param1);
}

void DungeonKeyRingUpdateMessage::deserializeAs_DungeonKeyRingUpdateMessage(Reader *param1)
{
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonKeyRingUpdateMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of DungeonKeyRingUpdateMessage.dungeonId.";
  }
  else
  {
    this->available = param1->readBool();
    return;
  }
}

DungeonKeyRingUpdateMessage::DungeonKeyRingUpdateMessage()
{
  m_type = MessageEnum::DUNGEONKEYRINGUPDATEMESSAGE;
}

