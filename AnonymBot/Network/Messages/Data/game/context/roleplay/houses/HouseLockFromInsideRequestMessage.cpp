#include "HouseLockFromInsideRequestMessage.h"

void HouseLockFromInsideRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseLockFromInsideRequestMessage(param1);
}

void HouseLockFromInsideRequestMessage::serializeAs_HouseLockFromInsideRequestMessage(Writer *param1)
{
  LockableChangeCodeMessage::serializeAs_LockableChangeCodeMessage(param1);
}

void HouseLockFromInsideRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseLockFromInsideRequestMessage(param1);
}

void HouseLockFromInsideRequestMessage::deserializeAs_HouseLockFromInsideRequestMessage(Reader *param1)
{
  LockableChangeCodeMessage::deserialize(param1);
}

HouseLockFromInsideRequestMessage::HouseLockFromInsideRequestMessage()
{
  m_type = MessageEnum::HOUSELOCKFROMINSIDEREQUESTMESSAGE;
}

