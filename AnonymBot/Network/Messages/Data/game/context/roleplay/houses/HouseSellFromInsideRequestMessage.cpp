#include "HouseSellFromInsideRequestMessage.h"

void HouseSellFromInsideRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_HouseSellFromInsideRequestMessage(param1);
}

void HouseSellFromInsideRequestMessage::serializeAs_HouseSellFromInsideRequestMessage(Writer *param1)
{
  HouseSellRequestMessage::serializeAs_HouseSellRequestMessage(param1);
}

void HouseSellFromInsideRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_HouseSellFromInsideRequestMessage(param1);
}

void HouseSellFromInsideRequestMessage::deserializeAs_HouseSellFromInsideRequestMessage(Reader *param1)
{
  HouseSellRequestMessage::deserialize(param1);
}

HouseSellFromInsideRequestMessage::HouseSellFromInsideRequestMessage()
{
  m_type = MessageEnum::HOUSESELLFROMINSIDEREQUESTMESSAGE;
}

