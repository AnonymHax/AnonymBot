#include "IdolSelectRequestMessage.h"

void IdolSelectRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolSelectRequestMessage(param1);
}

void IdolSelectRequestMessage::serializeAs_IdolSelectRequestMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->activate);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->party);
  param1->writeByte(_loc2_);
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolSelectRequestMessage -"<<"Forbidden value (" << this->idolId << ") on element idolId.";
  }
  else
  {
    param1->writeVarShort((int)this->idolId);
    return;
  }
}

void IdolSelectRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolSelectRequestMessage(param1);
}

void IdolSelectRequestMessage::deserializeAs_IdolSelectRequestMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->activate = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->party = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->idolId = param1->readVarUhShort();
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolSelectRequestMessage -"<<"Forbidden value (" << this->idolId << ") on element of IdolSelectRequestMessage.idolId.";
  }
  else
  {
    return;
  }
}

IdolSelectRequestMessage::IdolSelectRequestMessage()
{
  m_type = MessageEnum::IDOLSELECTREQUESTMESSAGE;
}

