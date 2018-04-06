#include "PrismFightStateUpdateMessage.h"

void PrismFightStateUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismFightStateUpdateMessage(param1);
}

void PrismFightStateUpdateMessage::serializeAs_PrismFightStateUpdateMessage(Writer *param1)
{
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - PrismFightStateUpdateMessage -"<<"Forbidden value (" << this->state << ") on element state.";
  }
  else
  {
    param1->writeByte(this->state);
    return;
  }
}

void PrismFightStateUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismFightStateUpdateMessage(param1);
}

void PrismFightStateUpdateMessage::deserializeAs_PrismFightStateUpdateMessage(Reader *param1)
{
  this->state = param1->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - PrismFightStateUpdateMessage -"<<"Forbidden value (" << this->state << ") on element of PrismFightStateUpdateMessage.state.";
  }
  else
  {
    return;
  }
}

PrismFightStateUpdateMessage::PrismFightStateUpdateMessage()
{
  m_type = MessageEnum::PRISMFIGHTSTATEUPDATEMESSAGE;
}

