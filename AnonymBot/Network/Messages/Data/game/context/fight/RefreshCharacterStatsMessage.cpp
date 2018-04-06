#include "RefreshCharacterStatsMessage.h"

void RefreshCharacterStatsMessage::serialize(Writer *param1)
{
  this->serializeAs_RefreshCharacterStatsMessage(param1);
}

void RefreshCharacterStatsMessage::serializeAs_RefreshCharacterStatsMessage(Writer *param1)
{
  if(this->fighterId < -9.007199254740992E15 || this->fighterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - RefreshCharacterStatsMessage -"<<"Forbidden value (" << this->fighterId << ") on element fighterId.";
  }
  else
  {
    param1->writeDouble(this->fighterId);
    this->stats->serializeAs_GameFightMinimalStats(param1);
    return;
  }
}

void RefreshCharacterStatsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_RefreshCharacterStatsMessage(param1);
}

void RefreshCharacterStatsMessage::deserializeAs_RefreshCharacterStatsMessage(Reader *param1)
{
  this->fighterId = param1->readDouble();
  if(this->fighterId < -9.007199254740992E15 || this->fighterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - RefreshCharacterStatsMessage -"<<"Forbidden value (" << this->fighterId << ") on element of RefreshCharacterStatsMessage.fighterId.";
  }
  else
  {
    this->stats = QSharedPointer<GameFightMinimalStats>(new GameFightMinimalStats() );
    this->stats->deserialize(param1);
    return;
  }
}

RefreshCharacterStatsMessage::RefreshCharacterStatsMessage()
{
  m_type = MessageEnum::REFRESHCHARACTERSTATSMESSAGE;
}

