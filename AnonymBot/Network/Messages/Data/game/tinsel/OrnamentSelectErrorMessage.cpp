#include "OrnamentSelectErrorMessage.h"

void OrnamentSelectErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_OrnamentSelectErrorMessage(param1);
}

void OrnamentSelectErrorMessage::serializeAs_OrnamentSelectErrorMessage(Writer *param1)
{
  param1->writeByte(this->reason);
}

void OrnamentSelectErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_OrnamentSelectErrorMessage(param1);
}

void OrnamentSelectErrorMessage::deserializeAs_OrnamentSelectErrorMessage(Reader *param1)
{
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - OrnamentSelectErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of OrnamentSelectErrorMessage.reason.";
  }
  else
  {
    return;
  }
}

OrnamentSelectErrorMessage::OrnamentSelectErrorMessage()
{
  m_type = MessageEnum::ORNAMENTSELECTERRORMESSAGE;
}

