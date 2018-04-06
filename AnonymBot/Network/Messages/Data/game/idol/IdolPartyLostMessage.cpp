#include "IdolPartyLostMessage.h"

void IdolPartyLostMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolPartyLostMessage(param1);
}

void IdolPartyLostMessage::serializeAs_IdolPartyLostMessage(Writer *param1)
{
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolPartyLostMessage -"<<"Forbidden value (" << this->idolId << ") on element idolId.";
  }
  else
  {
    param1->writeVarShort((int)this->idolId);
    return;
  }
}

void IdolPartyLostMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolPartyLostMessage(param1);
}

void IdolPartyLostMessage::deserializeAs_IdolPartyLostMessage(Reader *param1)
{
  this->idolId = param1->readVarUhShort();
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolPartyLostMessage -"<<"Forbidden value (" << this->idolId << ") on element of IdolPartyLostMessage.idolId.";
  }
  else
  {
    return;
  }
}

IdolPartyLostMessage::IdolPartyLostMessage()
{
  m_type = MessageEnum::IDOLPARTYLOSTMESSAGE;
}

