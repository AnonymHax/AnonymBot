#include "CompassResetMessage.h"

void CompassResetMessage::serialize(Writer *param1)
{
  this->serializeAs_CompassResetMessage(param1);
}

void CompassResetMessage::serializeAs_CompassResetMessage(Writer *param1)
{
  param1->writeByte(this->type);
}

void CompassResetMessage::deserialize(Reader *param1)
{
  this->deserializeAs_CompassResetMessage(param1);
}

void CompassResetMessage::deserializeAs_CompassResetMessage(Reader *param1)
{
  this->type = param1->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - CompassResetMessage -"<<"Forbidden value (" << this->type << ") on element of CompassResetMessage.type.";
  }
  else
  {
    return;
  }
}

CompassResetMessage::CompassResetMessage()
{
  m_type = MessageEnum::COMPASSRESETMESSAGE;
}

