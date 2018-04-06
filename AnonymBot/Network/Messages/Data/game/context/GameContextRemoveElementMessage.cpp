#include "GameContextRemoveElementMessage.h"

void GameContextRemoveElementMessage::serialize(Writer *param1)
{
  this->serializeAs_GameContextRemoveElementMessage(param1);
}

void GameContextRemoveElementMessage::serializeAs_GameContextRemoveElementMessage(Writer *param1)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextRemoveElementMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    return;
  }
}

void GameContextRemoveElementMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameContextRemoveElementMessage(param1);
}

void GameContextRemoveElementMessage::deserializeAs_GameContextRemoveElementMessage(Reader *param1)
{
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextRemoveElementMessage -"<<"Forbidden value (" << this->id << ") on element of GameContextRemoveElementMessage.id.";
  }
  else
  {
    return;
  }
}

GameContextRemoveElementMessage::GameContextRemoveElementMessage()
{
  m_type = MessageEnum::GAMECONTEXTREMOVEELEMENTMESSAGE;
}

