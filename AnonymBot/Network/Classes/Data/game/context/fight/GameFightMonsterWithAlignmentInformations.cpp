#include "GameFightMonsterWithAlignmentInformations.h"

void GameFightMonsterWithAlignmentInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightMonsterWithAlignmentInformations(param1);
}

void GameFightMonsterWithAlignmentInformations::serializeAs_GameFightMonsterWithAlignmentInformations(Writer *param1)
{
  GameFightMonsterInformations::serializeAs_GameFightMonsterInformations(param1);
  this->alignmentInfos.serializeAs_ActorAlignmentInformations(param1);
}

void GameFightMonsterWithAlignmentInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightMonsterWithAlignmentInformations(param1);
}

void GameFightMonsterWithAlignmentInformations::deserializeAs_GameFightMonsterWithAlignmentInformations(Reader *param1)
{
  GameFightMonsterInformations::deserialize(param1);
  this->alignmentInfos = ActorAlignmentInformations();
  this->alignmentInfos.deserialize(param1);
}

GameFightMonsterWithAlignmentInformations::GameFightMonsterWithAlignmentInformations()
{
  m_types<<ClassEnum::GAMEFIGHTMONSTERWITHALIGNMENTINFORMATIONS;
}

bool GameFightMonsterWithAlignmentInformations::operator==(const GameFightMonsterWithAlignmentInformations &compared)
{
  if(alignmentInfos == compared.alignmentInfos)
  return true;
  
  return false;
}

