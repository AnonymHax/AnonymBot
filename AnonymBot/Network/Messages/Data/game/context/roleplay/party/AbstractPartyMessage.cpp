#include "AbstractPartyMessage.h"

void AbstractPartyMessage::serialize(Writer *param1)
{
  this->serializeAs_AbstractPartyMessage(param1);
}

void AbstractPartyMessage::serializeAs_AbstractPartyMessage(Writer *param1)
{
  if(this->partyId < 0)
  {
    qDebug()<<"ERREUR - AbstractPartyMessage -"<<"Forbidden value (" << this->partyId << ") on element partyId.";
  }
  else
  {
    param1->writeVarInt((int)this->partyId);
    return;
  }
}

void AbstractPartyMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AbstractPartyMessage(param1);
}

void AbstractPartyMessage::deserializeAs_AbstractPartyMessage(Reader *param1)
{
  this->partyId = param1->readVarUhInt();
  if(this->partyId < 0)
  {
    qDebug()<<"ERREUR - AbstractPartyMessage -"<<"Forbidden value (" << this->partyId << ") on element of AbstractPartyMessage.partyId.";
  }
  else
  {
    return;
  }
}

AbstractPartyMessage::AbstractPartyMessage()
{
  m_type = MessageEnum::ABSTRACTPARTYMESSAGE;
}

