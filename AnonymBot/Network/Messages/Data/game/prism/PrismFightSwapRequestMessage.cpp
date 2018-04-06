#include "PrismFightSwapRequestMessage.h"

void PrismFightSwapRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismFightSwapRequestMessage(param1);
}

void PrismFightSwapRequestMessage::serializeAs_PrismFightSwapRequestMessage(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightSwapRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PrismFightSwapRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
    }
    else
    {
      param1->writeVarLong((double)this->targetId);
      return;
    }
  }
}

void PrismFightSwapRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismFightSwapRequestMessage(param1);
}

void PrismFightSwapRequestMessage::deserializeAs_PrismFightSwapRequestMessage(Reader *param1)
{
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightSwapRequestMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightSwapRequestMessage.subAreaId.";
  }
  else
  {
    this->targetId = param1->readVarUhLong();
    if(this->targetId < 0 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PrismFightSwapRequestMessage -"<<"Forbidden value (" << this->targetId << ") on element of PrismFightSwapRequestMessage.targetId.";
    }
    else
    {
      return;
    }
  }
}

PrismFightSwapRequestMessage::PrismFightSwapRequestMessage()
{
  m_type = MessageEnum::PRISMFIGHTSWAPREQUESTMESSAGE;
}

