#include "DareSubscribedMessage.h"

void DareSubscribedMessage::serialize(Writer *param1)
{
  this->serializeAs_DareSubscribedMessage(param1);
}

void DareSubscribedMessage::serializeAs_DareSubscribedMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->success);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->subscribe);
  param1->writeByte(_loc2_);
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareSubscribedMessage -"<<"Forbidden value (" << this->dareId << ") on element dareId.";
  }
  else
  {
    param1->writeDouble(this->dareId);
    this->dareVersatilesInfos.serializeAs_DareVersatileInformations(param1);
    return;
  }
}

void DareSubscribedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareSubscribedMessage(param1);
}

void DareSubscribedMessage::deserializeAs_DareSubscribedMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->success = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->subscribe = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->dareId = param1->readDouble();
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareSubscribedMessage -"<<"Forbidden value (" << this->dareId << ") on element of DareSubscribedMessage.dareId.";
  }
  else
  {
    this->dareVersatilesInfos = DareVersatileInformations();
    this->dareVersatilesInfos.deserialize(param1);
    return;
  }
}

DareSubscribedMessage::DareSubscribedMessage()
{
  m_type = MessageEnum::DARESUBSCRIBEDMESSAGE;
}

