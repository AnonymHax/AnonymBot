#include "TrustStatusMessage.h"

void TrustStatusMessage::serialize(Writer *param1)
{
  this->serializeAs_TrustStatusMessage(param1);
}

void TrustStatusMessage::serializeAs_TrustStatusMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->trusted);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->certified);
  param1->writeByte(_loc2_);
}

void TrustStatusMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TrustStatusMessage(param1);
}

void TrustStatusMessage::deserializeAs_TrustStatusMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->trusted = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->certified = BooleanByteWrapper::getFlag(_loc2_, 1);
}

TrustStatusMessage::TrustStatusMessage()
{
  m_type = MessageEnum::TRUSTSTATUSMESSAGE;
}

