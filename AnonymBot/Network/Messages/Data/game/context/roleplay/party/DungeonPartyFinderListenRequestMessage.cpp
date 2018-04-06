#include "DungeonPartyFinderListenRequestMessage.h"

void DungeonPartyFinderListenRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_DungeonPartyFinderListenRequestMessage(param1);
}

void DungeonPartyFinderListenRequestMessage::serializeAs_DungeonPartyFinderListenRequestMessage(Writer *param1)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderListenRequestMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  else
  {
    param1->writeVarShort((int)this->dungeonId);
    return;
  }
}

void DungeonPartyFinderListenRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DungeonPartyFinderListenRequestMessage(param1);
}

void DungeonPartyFinderListenRequestMessage::deserializeAs_DungeonPartyFinderListenRequestMessage(Reader *param1)
{
  this->dungeonId = param1->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderListenRequestMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of DungeonPartyFinderListenRequestMessage.dungeonId.";
  }
  else
  {
    return;
  }
}

DungeonPartyFinderListenRequestMessage::DungeonPartyFinderListenRequestMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERLISTENREQUESTMESSAGE;
}

