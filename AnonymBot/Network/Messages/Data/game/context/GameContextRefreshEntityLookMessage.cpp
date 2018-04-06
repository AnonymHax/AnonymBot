#include "GameContextRefreshEntityLookMessage.h"

void GameContextRefreshEntityLookMessage::serialize(Writer *param1)
{
  this->serializeAs_GameContextRefreshEntityLookMessage(param1);
}

void GameContextRefreshEntityLookMessage::serializeAs_GameContextRefreshEntityLookMessage(Writer *param1)
{
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextRefreshEntityLookMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeDouble(this->id);
    this->look->serializeAs_EntityLook(param1);
    return;
  }
}

void GameContextRefreshEntityLookMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameContextRefreshEntityLookMessage(param1);
}

void GameContextRefreshEntityLookMessage::deserializeAs_GameContextRefreshEntityLookMessage(Reader *param1)
{
  this->id = param1->readDouble();
  if(this->id < -9.007199254740992E15 || this->id > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameContextRefreshEntityLookMessage -"<<"Forbidden value (" << this->id << ") on element of GameContextRefreshEntityLookMessage.id.";
  }
  else
  {
    this->look = QSharedPointer<EntityLook>(new EntityLook() );
    this->look->deserialize(param1);
    return;
  }
}

GameContextRefreshEntityLookMessage::GameContextRefreshEntityLookMessage()
{
  m_type = MessageEnum::GAMECONTEXTREFRESHENTITYLOOKMESSAGE;
}

