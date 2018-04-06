#include "GameFightRemoveTeamMemberMessage.h"

void GameFightRemoveTeamMemberMessage::serialize(Writer *param1)
{
  this->serializeAs_GameFightRemoveTeamMemberMessage(param1);
}

void GameFightRemoveTeamMemberMessage::serializeAs_GameFightRemoveTeamMemberMessage(Writer *param1)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightRemoveTeamMemberMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  else
  {
    param1->writeShort((short)this->fightId);
    param1->writeByte(this->teamId);
    if(this->charId < -9.007199254740992E15 || this->charId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GameFightRemoveTeamMemberMessage -"<<"Forbidden value (" << this->charId << ") on element charId.";
    }
    else
    {
      param1->writeDouble(this->charId);
      return;
    }
  }
}

void GameFightRemoveTeamMemberMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightRemoveTeamMemberMessage(param1);
}

void GameFightRemoveTeamMemberMessage::deserializeAs_GameFightRemoveTeamMemberMessage(Reader *param1)
{
  this->fightId = param1->readShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightRemoveTeamMemberMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameFightRemoveTeamMemberMessage.fightId.";
  }
  else
  {
    this->teamId = param1->readByte();
    if(this->teamId < 0)
    {
      qDebug()<<"ERREUR - GameFightRemoveTeamMemberMessage -"<<"Forbidden value (" << this->teamId << ") on element of GameFightRemoveTeamMemberMessage.teamId.";
    }
    else
    {
      this->charId = param1->readDouble();
      if(this->charId < -9.007199254740992E15 || this->charId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - GameFightRemoveTeamMemberMessage -"<<"Forbidden value (" << this->charId << ") on element of GameFightRemoveTeamMemberMessage.charId.";
      }
      else
      {
        return;
      }
    }
  }
}

GameFightRemoveTeamMemberMessage::GameFightRemoveTeamMemberMessage()
{
  m_type = MessageEnum::GAMEFIGHTREMOVETEAMMEMBERMESSAGE;
}

