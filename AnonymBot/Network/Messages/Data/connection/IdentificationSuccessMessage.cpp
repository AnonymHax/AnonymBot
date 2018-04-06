#include "IdentificationSuccessMessage.h"

void IdentificationSuccessMessage::serialize(Writer *param1)
{
  this->serializeAs_IdentificationSuccessMessage(param1);
}

void IdentificationSuccessMessage::serializeAs_IdentificationSuccessMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->hasRights);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->wasAlreadyConnected);
  param1->writeByte(_loc2_);
  param1->writeUTF(this->login);
  param1->writeUTF(this->nickname);
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  else
  {
    param1->writeInt((int)this->accountId);
    if(this->communityId < 0)
    {
      qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->communityId << ") on element communityId.";
    }
    else
    {
      param1->writeByte(this->communityId);
      param1->writeUTF(this->secretQuestion);
      if(this->accountCreation < 0 || this->accountCreation > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->accountCreation << ") on element accountCreation.";
      }
      else
      {
        param1->writeDouble(this->accountCreation);
        if(this->subscriptionElapsedDuration < 0 || this->subscriptionElapsedDuration > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->subscriptionElapsedDuration << ") on element subscriptionElapsedDuration.";
        }
        else
        {
          param1->writeDouble(this->subscriptionElapsedDuration);
          if(this->subscriptionEndDate < 0 || this->subscriptionEndDate > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->subscriptionEndDate << ") on element subscriptionEndDate.";
          }
          else
          {
            param1->writeDouble(this->subscriptionEndDate);
            if(this->havenbagAvailableRoom < 0 || this->havenbagAvailableRoom > 255)
            {
              qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->havenbagAvailableRoom << ") on element havenbagAvailableRoom.";
            }
            else
            {
              param1->writeByte(this->havenbagAvailableRoom);
              return;
            }
          }
        }
      }
    }
  }
}

void IdentificationSuccessMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdentificationSuccessMessage(param1);
}

void IdentificationSuccessMessage::deserializeAs_IdentificationSuccessMessage(Reader *param1)
{
  uint _loc2_ = param1->readByte();
  this->hasRights = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->wasAlreadyConnected = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->login = param1->readUTF();
  this->nickname = param1->readUTF();
  this->accountId = param1->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->accountId << ") on element of IdentificationSuccessMessage.accountId.";
  }
  else
  {
    this->communityId = param1->readByte();
    if(this->communityId < 0)
    {
      qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->communityId << ") on element of IdentificationSuccessMessage.communityId.";
    }
    else
    {
      this->secretQuestion = param1->readUTF();
      this->accountCreation = param1->readDouble();
      if(this->accountCreation < 0 || this->accountCreation > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->accountCreation << ") on element of IdentificationSuccessMessage.accountCreation.";
      }
      else
      {
        this->subscriptionElapsedDuration = param1->readDouble();
        if(this->subscriptionElapsedDuration < 0 || this->subscriptionElapsedDuration > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->subscriptionElapsedDuration << ") on element of IdentificationSuccessMessage.subscriptionElapsedDuration.";
        }
        else
        {
          this->subscriptionEndDate = param1->readDouble();
          if(this->subscriptionEndDate < 0 || this->subscriptionEndDate > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->subscriptionEndDate << ") on element of IdentificationSuccessMessage.subscriptionEndDate.";
          }
          else
          {
            this->havenbagAvailableRoom = param1->readUByte();
            if(this->havenbagAvailableRoom < 0 || this->havenbagAvailableRoom > 255)
            {
              qDebug()<<"ERREUR - IdentificationSuccessMessage -"<<"Forbidden value (" << this->havenbagAvailableRoom << ") on element of IdentificationSuccessMessage.havenbagAvailableRoom.";
            }
            else
            {
              return;
            }
          }
        }
      }
    }
  }
}

IdentificationSuccessMessage::IdentificationSuccessMessage()
{
  m_type = MessageEnum::IDENTIFICATIONSUCCESSMESSAGE;
}

