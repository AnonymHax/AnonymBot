#include "OrnamentGainedMessage.h"

void OrnamentGainedMessage::serialize(Writer *param1)
{
  this->serializeAs_OrnamentGainedMessage(param1);
}

void OrnamentGainedMessage::serializeAs_OrnamentGainedMessage(Writer *param1)
{
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentGainedMessage -"<<"Forbidden value (" << this->ornamentId << ") on element ornamentId.";
  }
  else
  {
    param1->writeShort((short)this->ornamentId);
    return;
  }
}

void OrnamentGainedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_OrnamentGainedMessage(param1);
}

void OrnamentGainedMessage::deserializeAs_OrnamentGainedMessage(Reader *param1)
{
  this->ornamentId = param1->readShort();
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentGainedMessage -"<<"Forbidden value (" << this->ornamentId << ") on element of OrnamentGainedMessage.ornamentId.";
  }
  else
  {
    return;
  }
}

OrnamentGainedMessage::OrnamentGainedMessage()
{
  m_type = MessageEnum::ORNAMENTGAINEDMESSAGE;
}

