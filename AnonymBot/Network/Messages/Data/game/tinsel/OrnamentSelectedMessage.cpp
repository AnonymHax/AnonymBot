#include "OrnamentSelectedMessage.h"

void OrnamentSelectedMessage::serialize(Writer *param1)
{
  this->serializeAs_OrnamentSelectedMessage(param1);
}

void OrnamentSelectedMessage::serializeAs_OrnamentSelectedMessage(Writer *param1)
{
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentSelectedMessage -"<<"Forbidden value (" << this->ornamentId << ") on element ornamentId.";
  }
  else
  {
    param1->writeVarShort((int)this->ornamentId);
    return;
  }
}

void OrnamentSelectedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_OrnamentSelectedMessage(param1);
}

void OrnamentSelectedMessage::deserializeAs_OrnamentSelectedMessage(Reader *param1)
{
  this->ornamentId = param1->readVarUhShort();
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentSelectedMessage -"<<"Forbidden value (" << this->ornamentId << ") on element of OrnamentSelectedMessage.ornamentId.";
  }
  else
  {
    return;
  }
}

OrnamentSelectedMessage::OrnamentSelectedMessage()
{
  m_type = MessageEnum::ORNAMENTSELECTEDMESSAGE;
}

