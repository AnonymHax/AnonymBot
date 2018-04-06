#include "DareCreationRequestMessage.h"

void DareCreationRequestMessage::serialize(Writer *param1)
{
  this->serializeAs_DareCreationRequestMessage(param1);
}

void DareCreationRequestMessage::serializeAs_DareCreationRequestMessage(Writer *param1)
{
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->isPrivate);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->isForGuild);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->isForAlliance);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 3, this->needNotifications);
  param1->writeByte(_loc2_);
  if(this->subscriptionFee < 0)
  {
    qDebug()<<"ERREUR - DareCreationRequestMessage -"<<"Forbidden value (" << this->subscriptionFee << ") on element subscriptionFee.";
  }
  else
  {
    param1->writeInt((int)this->subscriptionFee);
    if(this->jackpot < 0)
    {
      qDebug()<<"ERREUR - DareCreationRequestMessage -"<<"Forbidden value (" << this->jackpot << ") on element jackpot.";
    }
    else
    {
      param1->writeInt((int)this->jackpot);
      if(this->maxCountWinners < 0 || this->maxCountWinners > 65535)
      {
        qDebug()<<"ERREUR - DareCreationRequestMessage -"<<"Forbidden value (" << this->maxCountWinners << ") on element maxCountWinners.";
      }
      else
      {
        param1->writeShort((short)this->maxCountWinners);
        if(this->delayBeforeStart < 0 || this->delayBeforeStart > 4.294967295E9)
        {
          qDebug()<<"ERREUR - DareCreationRequestMessage -"<<"Forbidden value (" << this->delayBeforeStart << ") on element delayBeforeStart.";
        }
        else
        {
          param1->writeUInt((uint)this->delayBeforeStart);
          if(this->duration < 0 || this->duration > 4.294967295E9)
          {
            qDebug()<<"ERREUR - DareCreationRequestMessage -"<<"Forbidden value (" << this->duration << ") on element duration.";
          }
          else
          {
            param1->writeUInt((uint)this->duration);
            param1->writeShort((short)this->criterions.size());
            uint _loc3_ = 0;
            while(_loc3_ < this->criterions.size())
            {
              (this->criterions[_loc3_]).serializeAs_DareCriteria(param1);
              _loc3_++;
            }
            return;
          }
        }
      }
    }
  }
}

void DareCreationRequestMessage::deserialize(Reader *param1)
{
  this->deserializeAs_DareCreationRequestMessage(param1);
}

void DareCreationRequestMessage::deserializeAs_DareCreationRequestMessage(Reader *param1)
{
  DareCriteria _loc5_ ;
  uint _loc2_ = param1->readByte();
  this->isPrivate = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->isForGuild = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->isForAlliance = BooleanByteWrapper::getFlag(_loc2_, 2);
  this->needNotifications = BooleanByteWrapper::getFlag(_loc2_, 3);
  this->subscriptionFee = param1->readInt();
  if(this->subscriptionFee < 0)
  {
    qDebug()<<"ERREUR - DareCreationRequestMessage -"<<"Forbidden value (" << this->subscriptionFee << ") on element of DareCreationRequestMessage.subscriptionFee.";
  }
  else
  {
    this->jackpot = param1->readInt();
    if(this->jackpot < 0)
    {
      qDebug()<<"ERREUR - DareCreationRequestMessage -"<<"Forbidden value (" << this->jackpot << ") on element of DareCreationRequestMessage.jackpot.";
    }
    else
    {
      this->maxCountWinners = param1->readUShort();
      if(this->maxCountWinners < 0 || this->maxCountWinners > 65535)
      {
        qDebug()<<"ERREUR - DareCreationRequestMessage -"<<"Forbidden value (" << this->maxCountWinners << ") on element of DareCreationRequestMessage.maxCountWinners.";
      }
      else
      {
        this->delayBeforeStart = param1->readUInt();
        if(this->delayBeforeStart < 0 || this->delayBeforeStart > 4.294967295E9)
        {
          qDebug()<<"ERREUR - DareCreationRequestMessage -"<<"Forbidden value (" << this->delayBeforeStart << ") on element of DareCreationRequestMessage.delayBeforeStart.";
        }
        else
        {
          this->duration = param1->readUInt();
          if(this->duration < 0 || this->duration > 4.294967295E9)
          {
            qDebug()<<"ERREUR - DareCreationRequestMessage -"<<"Forbidden value (" << this->duration << ") on element of DareCreationRequestMessage.duration.";
          }
          else
          {
            uint _loc3_ = param1->readUShort();
            uint _loc4_ = 0;
            while(_loc4_ < _loc3_)
            {
              _loc5_ = DareCriteria();
              _loc5_.deserialize(param1);
              this->criterions.append(_loc5_);
              _loc4_++;
            }
            return;
          }
        }
      }
    }
  }
}

DareCreationRequestMessage::DareCreationRequestMessage()
{
  m_type = MessageEnum::DARECREATIONREQUESTMESSAGE;
}

