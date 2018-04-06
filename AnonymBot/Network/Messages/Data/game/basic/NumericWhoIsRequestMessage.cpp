#include "NumericWhoIsRequestMessage.h"

void NumericWhoIsRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_NumericWhoIsRequestMessage(param1);
}

void NumericWhoIsRequestMessage::serializeAs_NumericWhoIsRequestMessage(Writer *param1)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - NumericWhoIsRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    return;
  }
}

void NumericWhoIsRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_NumericWhoIsRequestMessage(param1);
}

void NumericWhoIsRequestMessage::deserializeAs_NumericWhoIsRequestMessage(Reader *param1)
{
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - NumericWhoIsRequestMessage -"<<"Forbidden value (" << this->playerId << ") on element of NumericWhoIsRequestMessage.playerId.";
  }
  else
  {
    return;
  }
}

NumericWhoIsRequestMessage::NumericWhoIsRequestMessage()
{
  m_type = MessageEnum::NUMERICWHOISREQUESTMESSAGE;
}

