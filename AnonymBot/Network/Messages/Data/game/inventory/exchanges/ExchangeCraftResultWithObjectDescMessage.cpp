#include "ExchangeCraftResultWithObjectDescMessage.h"

void ExchangeCraftResultWithObjectDescMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeCraftResultWithObjectDescMessage(param1);
}

void ExchangeCraftResultWithObjectDescMessage::serializeAs_ExchangeCraftResultWithObjectDescMessage(Writer *param1)
{
  ExchangeCraftResultMessage::serializeAs_ExchangeCraftResultMessage(param1);
  this->objectInfo->serializeAs_ObjectItemNotInContainer(param1);
}

void ExchangeCraftResultWithObjectDescMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeCraftResultWithObjectDescMessage(param1);
}

void ExchangeCraftResultWithObjectDescMessage::deserializeAs_ExchangeCraftResultWithObjectDescMessage(Reader *param1)
{
  ExchangeCraftResultMessage::deserialize(param1);
  this->objectInfo = QSharedPointer<ObjectItemNotInContainer>(new ObjectItemNotInContainer() );
  this->objectInfo->deserialize(param1);
}

ExchangeCraftResultWithObjectDescMessage::ExchangeCraftResultWithObjectDescMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTRESULTWITHOBJECTDESCMESSAGE;
}

