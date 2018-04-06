#include "IdolSelectedMessage.h"

void IdolSelectedMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolSelectedMessage(param1);
}

void IdolSelectedMessage::serializeAs_IdolSelectedMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->activate);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->party);
  param1->writeByte(_loc2_);
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolSelectedMessage -"<<"Forbidden value (" << this->idolId << ") on element idolId.";
  }
  else
  {
    param1->writeVarShort((int)this->idolId);
    return;
  }
}

void IdolSelectedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolSelectedMessage(param1);
}

void IdolSelectedMessage::deserializeAs_IdolSelectedMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->activate = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->party = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->idolId = param1->readVarUhShort();
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolSelectedMessage -"<<"Forbidden value (" << this->idolId << ") on element of IdolSelectedMessage.idolId.";
  }
  else
  {
    return;
  }
}

IdolSelectedMessage::IdolSelectedMessage()
{
  m_type = MessageEnum::IDOLSELECTEDMESSAGE;
}

