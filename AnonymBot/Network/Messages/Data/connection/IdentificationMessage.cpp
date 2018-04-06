#include "IdentificationMessage.h"

void IdentificationMessage::serialize(Writer *param1)
{
  this->serializeAs_IdentificationMessage(param1);
}

void IdentificationMessage::serializeAs_IdentificationMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->autoconnect);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->useCertificate);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->useLoginToken);
  param1->writeByte(_loc2_);
  this->version.serializeAs_VersionExtended(param1);
  param1->writeUTF(this->lang);
  param1->writeVarInt((int)this->credentials.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->credentials.size())
  {
    param1->writeByte(this->credentials[_loc3_]);
    _loc3_++;
  }
  param1->writeShort((short)this->serverId);
  if(this->sessionOptionalSalt < -9.007199254740992E15 || this->sessionOptionalSalt > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationMessage -"<<"Forbidden value (" << this->sessionOptionalSalt << ") on element sessionOptionalSalt.";
  }
  else
  {
    param1->writeVarLong((double)this->sessionOptionalSalt);
    param1->writeShort((short)this->failedAttempts.size());
    uint _loc4_ = 0;
    while(_loc4_ < this->failedAttempts.size())
    {
      if(this->failedAttempts[_loc4_] < 0)
      {
        qDebug()<<"ERREUR - IdentificationMessage -"<<"Forbidden value (" << this->failedAttempts[_loc4_] << ") on element 9 (starting at 1) of failedAttempts.";
      }
      else
      {
        param1->writeVarShort((int)this->failedAttempts[_loc4_]);
        _loc4_++;
        continue;
      }
    }
    return;
  }
}

void IdentificationMessage::deserialize(Reader *param1)
{
  this->deserializeAs_IdentificationMessage(param1);
}

void IdentificationMessage::deserializeAs_IdentificationMessage(Reader *param1)
{
  auto _loc7_ = 0;
  uint _loc8_ = 0;
  uint _loc2_ = param1->readByte();
  this->autoconnect = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->useCertificate = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->useLoginToken = BooleanByteWrapper::getFlag(_loc2_, 2);
  this->version = VersionExtended();
  this->version.deserialize(param1);
  this->lang = param1->readUTF();
  uint _loc3_ = param1->readVarInt();
  uint _loc4_ = 0;
  while(_loc4_ < _loc3_)
  {
    _loc7_ = param1->readByte();
    this->credentials.append(_loc7_);
    _loc4_++;
  }
  this->serverId = param1->readShort();
  this->sessionOptionalSalt = param1->readVarLong();
  if(this->sessionOptionalSalt < -9.007199254740992E15 || this->sessionOptionalSalt > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IdentificationMessage -"<<"Forbidden value (" << this->sessionOptionalSalt << ") on element of IdentificationMessage.sessionOptionalSalt.";
  }
  else
  {
    uint _loc5_ = param1->readUShort();
    uint _loc6_ = 0;
    while(_loc6_ < _loc5_)
    {
      _loc8_ = param1->readVarUhShort();
      if(_loc8_ < 0)
      {
        qDebug()<<"ERREUR - IdentificationMessage -"<<"Forbidden value (" << _loc8_ << ") on elements of failedAttempts.";
      }
      else
      {
        this->failedAttempts.append(_loc8_);
        _loc6_++;
        continue;
      }
    }
    return;
  }
}

IdentificationMessage::IdentificationMessage()
{
  m_type = MessageEnum::IDENTIFICATIONMESSAGE;
}

