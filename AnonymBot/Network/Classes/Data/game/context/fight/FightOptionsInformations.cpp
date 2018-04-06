#include "FightOptionsInformations.h"

void FightOptionsInformations::serialize(Writer *param1)
{
  this->serializeAs_FightOptionsInformations(param1);
}

void FightOptionsInformations::serializeAs_FightOptionsInformations(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->isSecret);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->isRestrictedToPartyOnly);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->isClosed);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 3, this->isAskingForHelp);
  param1->writeByte(_loc2_);
}

void FightOptionsInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightOptionsInformations(param1);
}

void FightOptionsInformations::deserializeAs_FightOptionsInformations(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->isSecret = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->isRestrictedToPartyOnly = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->isClosed = BooleanByteWrapper::getFlag(_loc2_, 2);
  this->isAskingForHelp = BooleanByteWrapper::getFlag(_loc2_, 3);
}

FightOptionsInformations::FightOptionsInformations()
{
  m_types<<ClassEnum::FIGHTOPTIONSINFORMATIONS;
}

bool FightOptionsInformations::operator==(const FightOptionsInformations &compared)
{
  if(isSecret == compared.isSecret)
  if(isRestrictedToPartyOnly == compared.isRestrictedToPartyOnly)
  if(isClosed == compared.isClosed)
  if(isAskingForHelp == compared.isAskingForHelp)
  return true;
  
  return false;
}

