#include "GuildFightPlayersEnemiesListMessage.h"

void GuildFightPlayersEnemiesListMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildFightPlayersEnemiesListMessage(param1);
}

void GuildFightPlayersEnemiesListMessage::serializeAs_GuildFightPlayersEnemiesListMessage(Writer *param1)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GuildFightPlayersEnemiesListMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  else
  {
    param1->writeInt((int)this->fightId);
    param1->writeShort((short)this->playerInfo.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->playerInfo.size())
    {
      qSharedPointerCast<CharacterMinimalPlusLookInformations>(this->playerInfo[_loc2_])->serializeAs_CharacterMinimalPlusLookInformations(param1);
      _loc2_++;
    }
    return;
  }
}

void GuildFightPlayersEnemiesListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildFightPlayersEnemiesListMessage(param1);
}

void GuildFightPlayersEnemiesListMessage::deserializeAs_GuildFightPlayersEnemiesListMessage(Reader *param1)
{
  QSharedPointer<CharacterMinimalPlusLookInformations> _loc4_ ;
  this->fightId = param1->readInt();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GuildFightPlayersEnemiesListMessage -"<<"Forbidden value (" << this->fightId << ") on element of GuildFightPlayersEnemiesListMessage.fightId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = QSharedPointer<CharacterMinimalPlusLookInformations>(new CharacterMinimalPlusLookInformations() );
      _loc4_->deserialize(param1);
      this->playerInfo.append(_loc4_);
      _loc3_++;
    }
    return;
  }
}

GuildFightPlayersEnemiesListMessage::GuildFightPlayersEnemiesListMessage()
{
  m_type = MessageEnum::GUILDFIGHTPLAYERSENEMIESLISTMESSAGE;
}

