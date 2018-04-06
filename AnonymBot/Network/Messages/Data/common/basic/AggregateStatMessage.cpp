#include "AggregateStatMessage.h"

void AggregateStatMessage::serialize(Writer *param1)
{
  this->serializeAs_AggregateStatMessage(param1);
}

void AggregateStatMessage::serializeAs_AggregateStatMessage(Writer *param1)
{
  param1->writeVarShort((int)this->statId);
}

void AggregateStatMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AggregateStatMessage(param1);
}

void AggregateStatMessage::deserializeAs_AggregateStatMessage(Reader *param1)
{
  this->statId = param1->readVarUhShort();
  if(this->statId < 0)
  {
    qDebug()<<"ERREUR - AggregateStatMessage -"<<"Forbidden value (" << this->statId << ") on element of AggregateStatMessage.statId.";
  }
  else
  {
    return;
  }
}

AggregateStatMessage::AggregateStatMessage()
{
  m_type = MessageEnum::AGGREGATESTATMESSAGE;
}

