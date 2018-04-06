#include "PrismFightAddedMessage.h"

void PrismFightAddedMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismFightAddedMessage(param1);
}

void PrismFightAddedMessage::serializeAs_PrismFightAddedMessage(Writer *param1)
{
  this->fight->serializeAs_PrismFightersInformation(param1);
}

void PrismFightAddedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismFightAddedMessage(param1);
}

void PrismFightAddedMessage::deserializeAs_PrismFightAddedMessage(Reader *param1)
{
  this->fight = QSharedPointer<PrismFightersInformation>(new PrismFightersInformation() );
  this->fight->deserialize(param1);
}

PrismFightAddedMessage::PrismFightAddedMessage()
{
  m_type = MessageEnum::PRISMFIGHTADDEDMESSAGE;
}

