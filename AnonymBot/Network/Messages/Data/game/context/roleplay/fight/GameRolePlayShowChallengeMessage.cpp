#include "GameRolePlayShowChallengeMessage.h"

void GameRolePlayShowChallengeMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayShowChallengeMessage(param1);
}

void GameRolePlayShowChallengeMessage::serializeAs_GameRolePlayShowChallengeMessage(Writer *param1)
{
  this->commonsInfos->serializeAs_FightCommonInformations(param1);
}

void GameRolePlayShowChallengeMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayShowChallengeMessage(param1);
}

void GameRolePlayShowChallengeMessage::deserializeAs_GameRolePlayShowChallengeMessage(Reader *param1)
{
  this->commonsInfos = QSharedPointer<FightCommonInformations>(new FightCommonInformations() );
  this->commonsInfos->deserialize(param1);
}

GameRolePlayShowChallengeMessage::GameRolePlayShowChallengeMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYSHOWCHALLENGEMESSAGE;
}

