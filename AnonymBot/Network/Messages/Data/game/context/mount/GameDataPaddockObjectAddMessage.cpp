#include "GameDataPaddockObjectAddMessage.h"

void GameDataPaddockObjectAddMessage::serialize(Writer *param1)
{
  this->serializeAs_GameDataPaddockObjectAddMessage(param1);
}

void GameDataPaddockObjectAddMessage::serializeAs_GameDataPaddockObjectAddMessage(Writer *param1)
{
  this->paddockItemDescription.serializeAs_PaddockItem(param1);
}

void GameDataPaddockObjectAddMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameDataPaddockObjectAddMessage(param1);
}

void GameDataPaddockObjectAddMessage::deserializeAs_GameDataPaddockObjectAddMessage(Reader *param1)
{
  this->paddockItemDescription = PaddockItem();
  this->paddockItemDescription.deserialize(param1);
}

GameDataPaddockObjectAddMessage::GameDataPaddockObjectAddMessage()
{
  m_type = MessageEnum::GAMEDATAPADDOCKOBJECTADDMESSAGE;
}

