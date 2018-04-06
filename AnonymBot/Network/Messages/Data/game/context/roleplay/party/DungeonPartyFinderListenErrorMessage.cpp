#include "DungeonPartyFinderListenErrorMessage.h"

void DungeonPartyFinderListenErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_DungeonPartyFinderListenErrorMessage(param1);
}

void DungeonPartyFinderListenErrorMessage::serializeAs_DungeonPartyFinderListenErrorMessage(Writer *param1)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderListenErrorMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    return;
  }
}

void DungeonPartyFinderListenErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DungeonPartyFinderListenErrorMessage(param1);
}

void DungeonPartyFinderListenErrorMessage::deserializeAs_DungeonPartyFinderListenErrorMessage(Reader *param1)
{
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderListenErrorMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of DungeonPartyFinderListenErrorMessage.dungeonId.";
  }
  else
  {
    return;
  }
}

DungeonPartyFinderListenErrorMessage::DungeonPartyFinderListenErrorMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERLISTENERRORMESSAGE;
}

