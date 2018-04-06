#include "PlayerStatusExtended.h"

void PlayerStatusExtended::serialize(Writer *param1)
{
  this->serializeAs_PlayerStatusExtended(param1);
}

void PlayerStatusExtended::serializeAs_PlayerStatusExtended(Writer *param1)
{
  PlayerStatus::serializeAs_PlayerStatus(param1);
  param1->writeUTF(this->message);
}

void PlayerStatusExtended::deserialize(Reader *param1)
{
  this->deserializeAs_PlayerStatusExtended(param1);
}

void PlayerStatusExtended::deserializeAs_PlayerStatusExtended(Reader *param1)
{
  PlayerStatus::deserialize(param1);
  this->message = param1->readUTF();
}

PlayerStatusExtended::PlayerStatusExtended()
{
  m_types<<ClassEnum::PLAYERSTATUSEXTENDED;
}

bool PlayerStatusExtended::operator==(const PlayerStatusExtended &compared)
{
  if(message == compared.message)
  return true;
  
  return false;
}

