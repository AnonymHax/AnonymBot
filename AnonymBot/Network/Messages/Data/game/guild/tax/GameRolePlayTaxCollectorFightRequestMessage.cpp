#include "GameRolePlayTaxCollectorFightRequestMessage.h"

void GameRolePlayTaxCollectorFightRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayTaxCollectorFightRequestMessage(param1);
}

void GameRolePlayTaxCollectorFightRequestMessage::serializeAs_GameRolePlayTaxCollectorFightRequestMessage(Writer *param1)
{
  param1->writeInt((int)this->taxCollectorId);
}

void GameRolePlayTaxCollectorFightRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayTaxCollectorFightRequestMessage(param1);
}

void GameRolePlayTaxCollectorFightRequestMessage::deserializeAs_GameRolePlayTaxCollectorFightRequestMessage(Reader *param1)
{
  this->taxCollectorId = param1->readInt();
}

GameRolePlayTaxCollectorFightRequestMessage::GameRolePlayTaxCollectorFightRequestMessage()
{
  m_type = MessageEnum::GAMEROLEPLAYTAXCOLLECTORFIGHTREQUESTMESSAGE;
}

