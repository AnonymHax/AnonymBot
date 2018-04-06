#include "PrismsListRegisterMessage.h"

void PrismsListRegisterMessage::serialize(Writer *param1)
{
  this->serializeAs_PrismsListRegisterMessage(param1);
}

void PrismsListRegisterMessage::serializeAs_PrismsListRegisterMessage(Writer *param1)
{
  param1->writeByte(this->listen);
}

void PrismsListRegisterMessage::deserialize(Reader *param1)
{
  this->deserializeAs_PrismsListRegisterMessage(param1);
}

void PrismsListRegisterMessage::deserializeAs_PrismsListRegisterMessage(Reader *param1)
{
  this->listen = param1->readByte();
  if(this->listen < 0)
  {
    qDebug()<<"ERREUR - PrismsListRegisterMessage -"<<"Forbidden value (" << this->listen << ") on element of PrismsListRegisterMessage.listen.";
  }
  else
  {
    return;
  }
}

PrismsListRegisterMessage::PrismsListRegisterMessage()
{
  m_type = MessageEnum::PRISMSLISTREGISTERMESSAGE;
}

