#include "AccountCapabilitiesMessage.h"

void AccountCapabilitiesMessage::serialize(Writer *param1)
{
  this->serializeAs_AccountCapabilitiesMessage(param1);
}

void AccountCapabilitiesMessage::serializeAs_AccountCapabilitiesMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->tutorialAvailable);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->canCreateNewCharacter);
  param1->writeByte(_loc2_);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  else
  {
    param1->writeInt((int)this->accountId);
    if(this->breedsVisible < 0)
    {
      qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->breedsVisible << ") on element breedsVisible.";
    }
    else
    {
      param1->writeVarInt((int)this->breedsVisible);
      if(this->breedsAvailable < 0)
      {
        qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->breedsAvailable << ") on element breedsAvailable.";
      }
      else
      {
        param1->writeVarInt((int)this->breedsAvailable);
        param1->writeByte(this->status);
        return;
      }
    }
  }
}

void AccountCapabilitiesMessage::deserialize(Reader *param1)
{
  this->deserializeAs_AccountCapabilitiesMessage(param1);
}

void AccountCapabilitiesMessage::deserializeAs_AccountCapabilitiesMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->tutorialAvailable = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->canCreateNewCharacter = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->accountId = param1->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->accountId << ") on element of AccountCapabilitiesMessage.accountId.";
  }
  else
  {
    this->breedsVisible = param1->readVarUhInt();
    if(this->breedsVisible < 0)
    {
      qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->breedsVisible << ") on element of AccountCapabilitiesMessage.breedsVisible.";
    }
    else
    {
      this->breedsAvailable = param1->readVarUhInt();
      if(this->breedsAvailable < 0)
      {
        qDebug()<<"ERREUR - AccountCapabilitiesMessage -"<<"Forbidden value (" << this->breedsAvailable << ") on element of AccountCapabilitiesMessage.breedsAvailable.";
      }
      else
      {
        this->status = param1->readByte();
        return;
      }
    }
  }
}

AccountCapabilitiesMessage::AccountCapabilitiesMessage()
{
  m_type = MessageEnum::ACCOUNTCAPABILITIESMESSAGE;
}

