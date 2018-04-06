#include "GuildFightPlayersHelpersJoinMessage.h"

void GuildFightPlayersHelpersJoinMessage::serialize(Writer *param1)
{
  this->serializeAs_GuildFightPlayersHelpersJoinMessage(param1);
}

void GuildFightPlayersHelpersJoinMessage::serializeAs_GuildFightPlayersHelpersJoinMessage(Writer *param1)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GuildFightPlayersHelpersJoinMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  else
  {
    param1->writeInt((int)this->fightId);
    this->playerInfo->serializeAs_CharacterMinimalPlusLookInformations(param1);
    return;
  }
}

void GuildFightPlayersHelpersJoinMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GuildFightPlayersHelpersJoinMessage(param1);
}

void GuildFightPlayersHelpersJoinMessage::deserializeAs_GuildFightPlayersHelpersJoinMessage(Reader *param1)
{
  this->fightId = param1->readInt();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GuildFightPlayersHelpersJoinMessage -"<<"Forbidden value (" << this->fightId << ") on element of GuildFightPlayersHelpersJoinMessage.fightId.";
  }
  else
  {
    this->playerInfo = QSharedPointer<CharacterMinimalPlusLookInformations>(new CharacterMinimalPlusLookInformations() );
    this->playerInfo->deserialize(param1);
    return;
  }
}

GuildFightPlayersHelpersJoinMessage::GuildFightPlayersHelpersJoinMessage()
{
  m_type = MessageEnum::GUILDFIGHTPLAYERSHELPERSJOINMESSAGE;
}

