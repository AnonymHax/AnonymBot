#include "OrnamentSelectRequestMessage.h"

void OrnamentSelectRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_OrnamentSelectRequestMessage(param1);
}

void OrnamentSelectRequestMessage::serializeAs_OrnamentSelectRequestMessage(Writer *param1)
{
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentSelectRequestMessage -"<<"Forbidden value (" << this->ornamentId << ") on element ornamentId.";
  }
  else
  {
    param1->writeVarShort((int)this->ornamentId);
    return;
  }
}

void OrnamentSelectRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_OrnamentSelectRequestMessage(param1);
}

void OrnamentSelectRequestMessage::deserializeAs_OrnamentSelectRequestMessage(Reader *param1)
{
  this->ornamentId = param1->readVarUhShort();
  if(this->ornamentId < 0)
  {
    qDebug()<<"ERREUR - OrnamentSelectRequestMessage -"<<"Forbidden value (" << this->ornamentId << ") on element of OrnamentSelectRequestMessage.ornamentId.";
  }
  else
  {
    return;
  }
}

OrnamentSelectRequestMessage::OrnamentSelectRequestMessage()
{
  m_type = MessageEnum::ORNAMENTSELECTREQUESTMESSAGE;
}

