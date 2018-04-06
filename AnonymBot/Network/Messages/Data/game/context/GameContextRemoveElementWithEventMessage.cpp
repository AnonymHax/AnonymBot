#include "GameContextRemoveElementWithEventMessage.h"

void GameContextRemoveElementWithEventMessage::serialize(Writer *param1)
{
  this->serializeAs_GameContextRemoveElementWithEventMessage(param1);
}

void GameContextRemoveElementWithEventMessage::serializeAs_GameContextRemoveElementWithEventMessage(Writer *param1)
{
  GameContextRemoveElementMessage::serializeAs_GameContextRemoveElementMessage(param1);
  if(this->elementEventId < 0)
  {
    qDebug()<<"ERREUR - GameContextRemoveElementWithEventMessage -"<<"Forbidden value (" << this->elementEventId << ") on element elementEventId.";
  }
  else
  {
    param1->writeByte(this->elementEventId);
    return;
  }
}

void GameContextRemoveElementWithEventMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameContextRemoveElementWithEventMessage(param1);
}

void GameContextRemoveElementWithEventMessage::deserializeAs_GameContextRemoveElementWithEventMessage(Reader *param1)
{
  GameContextRemoveElementMessage::deserialize(param1);
  this->elementEventId = param1->readByte();
  if(this->elementEventId < 0)
  {
    qDebug()<<"ERREUR - GameContextRemoveElementWithEventMessage -"<<"Forbidden value (" << this->elementEventId << ") on element of GameContextRemoveElementWithEventMessage.elementEventId.";
  }
  else
  {
    return;
  }
}

GameContextRemoveElementWithEventMessage::GameContextRemoveElementWithEventMessage()
{
  m_type = MessageEnum::GAMECONTEXTREMOVEELEMENTWITHEVENTMESSAGE;
}

