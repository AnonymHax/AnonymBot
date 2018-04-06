#include "GameRolePlayCharacterInformations.h"

void GameRolePlayCharacterInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayCharacterInformations(param1);
}

void GameRolePlayCharacterInformations::serializeAs_GameRolePlayCharacterInformations(Writer *param1)
{
  GameRolePlayHumanoidInformations::serializeAs_GameRolePlayHumanoidInformations(param1);
  this->alignmentInfos.serializeAs_ActorAlignmentInformations(param1);
}

void GameRolePlayCharacterInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayCharacterInformations(param1);
}

void GameRolePlayCharacterInformations::deserializeAs_GameRolePlayCharacterInformations(Reader *param1)
{
  GameRolePlayHumanoidInformations::deserialize(param1);
  this->alignmentInfos = ActorAlignmentInformations();
  this->alignmentInfos.deserialize(param1);
}

GameRolePlayCharacterInformations::GameRolePlayCharacterInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYCHARACTERINFORMATIONS;
}

bool GameRolePlayCharacterInformations::operator==(const GameRolePlayCharacterInformations &compared)
{
  if(alignmentInfos == compared.alignmentInfos)
  return true;
  
  return false;
}

