#include "GameDataPaddockObjectListAddMessage.h"

void GameDataPaddockObjectListAddMessage::serialize(Writer *param1)
{
  this->serializeAs_GameDataPaddockObjectListAddMessage(param1);
}

void GameDataPaddockObjectListAddMessage::serializeAs_GameDataPaddockObjectListAddMessage(Writer *param1)
{
  param1->writeShort((short)this->paddockItemDescription.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->paddockItemDescription.size())
  {
    (this->paddockItemDescription[_loc2_]).serializeAs_PaddockItem(param1);
    _loc2_++;
  }
}

void GameDataPaddockObjectListAddMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameDataPaddockObjectListAddMessage(param1);
}

void GameDataPaddockObjectListAddMessage::deserializeAs_GameDataPaddockObjectListAddMessage(Reader *param1)
{
  PaddockItem _loc4_ ;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = PaddockItem();
    _loc4_.deserialize(param1);
    this->paddockItemDescription.append(_loc4_);
    _loc3_++;
  }
}

GameDataPaddockObjectListAddMessage::GameDataPaddockObjectListAddMessage()
{
  m_type = MessageEnum::GAMEDATAPADDOCKOBJECTLISTADDMESSAGE;
}

