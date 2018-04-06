#include "IdolSelectErrorMessage.h"

void IdolSelectErrorMessage::serialize(Writer *param1)
{
  this->serializeAs_IdolSelectErrorMessage(param1);
}

void IdolSelectErrorMessage::serializeAs_IdolSelectErrorMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->activate);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->party);
  param1->writeByte(_loc2_);
  param1->writeByte(this->reason);
  if(this->idolId < 0)
  {
    qDebug()<<"ERREUR - IdolSelectErrorMessage -"<<"Forbidden value (" << this->idolId << ") on element idolId.";
  }
  else
  {
    param1->writeVarShort((int)this->idolId);
    return;
  }
}

void IdolSelectErrorMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdolSelectErrorMessage(param1);
}

void IdolSelectErrorMessage::deserializeAs_IdolSelectErrorMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->activate = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->party = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->reason = param1->readByte();
  if(this->reason < 0)
  {
    qDebug()<<"ERREUR - IdolSelectErrorMessage -"<<"Forbidden value (" << this->reason << ") on element of IdolSelectErrorMessage.reason.";
  }
  else
  {
    this->idolId = param1->readVarUhShort();
    if(this->idolId < 0)
    {
      qDebug()<<"ERREUR - IdolSelectErrorMessage -"<<"Forbidden value (" << this->idolId << ") on element of IdolSelectErrorMessage.idolId.";
    }
    else
    {
      return;
    }
  }
}

IdolSelectErrorMessage::IdolSelectErrorMessage()
{
  m_type = MessageEnum::IDOLSELECTERRORMESSAGE;
}

