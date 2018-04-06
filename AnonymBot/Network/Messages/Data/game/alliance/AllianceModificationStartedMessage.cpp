#include "AllianceModificationStartedMessage.h"

void AllianceModificationStartedMessage::serialize(Writer *param1)
{
  this->serializeAs_AllianceModificationStartedMessage(param1);
}

void AllianceModificationStartedMessage::serializeAs_AllianceModificationStartedMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->canChangeName);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->canChangeTag);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->canChangeEmblem);
  param1->writeByte(_loc2_);
}

void AllianceModificationStartedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceModificationStartedMessage(param1);
}

void AllianceModificationStartedMessage::deserializeAs_AllianceModificationStartedMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->canChangeName = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->canChangeTag = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->canChangeEmblem = BooleanByteWrapper::getFlag(_loc2_, 2);
}

AllianceModificationStartedMessage::AllianceModificationStartedMessage()
{
  m_type = MessageEnum::ALLIANCEMODIFICATIONSTARTEDMESSAGE;
}

