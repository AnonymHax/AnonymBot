#include "StartupActionFinishedMessage.h"

void StartupActionFinishedMessage::serialize(Writer *param1)
{
  this->serializeAs_StartupActionFinishedMessage(param1);
}

void StartupActionFinishedMessage::serializeAs_StartupActionFinishedMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->success);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->automaticAction);
  param1->writeByte(_loc2_);
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - StartupActionFinishedMessage -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  else
  {
    param1->writeInt((int)this->actionId);
    return;
  }
}

void StartupActionFinishedMessage::deserialize(Reader *param1)
{
  this->deserializeAs_StartupActionFinishedMessage(param1);
}

void StartupActionFinishedMessage::deserializeAs_StartupActionFinishedMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->success = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->automaticAction = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->actionId = param1->readInt();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - StartupActionFinishedMessage -"<<"Forbidden value (" << this->actionId << ") on element of StartupActionFinishedMessage.actionId.";
  }
  else
  {
    return;
  }
}

StartupActionFinishedMessage::StartupActionFinishedMessage()
{
  m_type = MessageEnum::STARTUPACTIONFINISHEDMESSAGE;
}

