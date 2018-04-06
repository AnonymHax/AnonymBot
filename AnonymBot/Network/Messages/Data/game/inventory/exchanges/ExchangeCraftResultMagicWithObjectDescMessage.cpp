#include "ExchangeCraftResultMagicWithObjectDescMessage.h"

void ExchangeCraftResultMagicWithObjectDescMessage::serialize(Writer *param1)
{
  this->serializeAs_ExchangeCraftResultMagicWithObjectDescMessage(param1);
}

void ExchangeCraftResultMagicWithObjectDescMessage::serializeAs_ExchangeCraftResultMagicWithObjectDescMessage(Writer *param1)
{
  ExchangeCraftResultWithObjectDescMessage::serializeAs_ExchangeCraftResultWithObjectDescMessage(param1);
  param1->writeByte(this->magicPoolStatus);
}

void ExchangeCraftResultMagicWithObjectDescMessage::deserialize(Reader *param1)
{
  this->deserializeAs_ExchangeCraftResultMagicWithObjectDescMessage(param1);
}

void ExchangeCraftResultMagicWithObjectDescMessage::deserializeAs_ExchangeCraftResultMagicWithObjectDescMessage(Reader *param1)
{
  ExchangeCraftResultWithObjectDescMessage::deserialize(param1);
  this->magicPoolStatus = param1->readByte();
}

ExchangeCraftResultMagicWithObjectDescMessage::ExchangeCraftResultMagicWithObjectDescMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTRESULTMAGICWITHOBJECTDESCMESSAGE;
}

