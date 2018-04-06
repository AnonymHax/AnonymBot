#include "GameRolePlayAttackMonsterRequestMessage.h"

void GameRolePlayAttackMonsterRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayAttackMonsterRequestMessage(param1);
}

void GameRolePlayAttackMonsterRequestMessage::serializeAs_GameRolePlayAttackMonsterRequestMessage(Writer *param1)
{
  if(this->monsterGroupId < -9.007199254740992E15 || this->monsterGroupId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayAttackMonsterRequestMessage -"<<"Forbidden value (" << this->monsterGroupId << ") on element monsterGroupId.";
  }
  else
  {
    param1->writeDouble(this->monsterGroupId);
    return;
  }
}

void GameRolePlayAttackMonsterRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayAttackMonsterRequestMessage(param1);
}

void GameRolePlayAttackMonsterRequestMessage::deserializeAs_GameRolePlayAttackMonsterRequestMessage(Reader *param1)
{
  this->monsterGroupId = param1->readDouble();
  if(this->monsterGroupId < -9.007199254740992E15 || this->monsterGroupId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayAttackMonsterRequestMessage -"<<"Forbidden value (" << this->monsterGroupId << ") on element of GameRolePlayAttackMonsterRequestMessage.monsterGroupId.";
  }
  else
  {
    return;
  }
}

GameRolePlayAttackMonsterRequestMessage::GameRolePlayAttackMonsterRequestMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYATTACKMONSTERREQUESTMESSAGE;
}

