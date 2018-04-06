#include "PrismFightRemovedMessage.h"

void PrismFightRemovedMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismFightRemovedMessage(param1);
}

void PrismFightRemovedMessage::serializeAs_PrismFightRemovedMessage(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightRemovedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    return;
  }
}

void PrismFightRemovedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismFightRemovedMessage(param1);
}

void PrismFightRemovedMessage::deserializeAs_PrismFightRemovedMessage(Reader *param1)
{
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightRemovedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightRemovedMessage.subAreaId.";
  }
  else
  {
    return;
  }
}

PrismFightRemovedMessage::PrismFightRemovedMessage()
{
  m_type = MessageEnum::PRISMFIGHTREMOVEDMESSAGE;
}

