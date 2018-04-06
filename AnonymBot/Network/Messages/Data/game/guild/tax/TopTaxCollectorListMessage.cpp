#include "TopTaxCollectorListMessage.h"

void TopTaxCollectorListMessage::serialize(Writer *param1)
{
  this->serializeAs_TopTaxCollectorListMessage(param1);
}

void TopTaxCollectorListMessage::serializeAs_TopTaxCollectorListMessage(Writer *param1)
{
  AbstractTaxCollectorListMessage::serializeAs_AbstractTaxCollectorListMessage(param1);
  param1->writeBool(this->isDungeon);
}

void TopTaxCollectorListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TopTaxCollectorListMessage(param1);
}

void TopTaxCollectorListMessage::deserializeAs_TopTaxCollectorListMessage(Reader *param1)
{
  AbstractTaxCollectorListMessage::deserialize(param1);
  this->isDungeon = param1->readBool();
}

TopTaxCollectorListMessage::TopTaxCollectorListMessage()
{
  m_type = MessageEnum::TOPTAXCOLLECTORLISTMESSAGE;
}

