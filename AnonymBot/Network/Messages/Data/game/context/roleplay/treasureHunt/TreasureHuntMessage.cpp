#include "TreasureHuntMessage.h"

void TreasureHuntMessage::serialize(Writer *param1)
{
  this->serializeAs_TreasureHuntMessage(param1);
}

void TreasureHuntMessage::serializeAs_TreasureHuntMessage(Writer *param1)
{
  param1->writeByte(this->questType);
  param1->writeInt((int)this->startMapId);
  param1->writeShort((short)this->knownStepsList.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->knownStepsList.size())
  {
    param1->writeShort((short)qSharedPointerCast<TreasureHuntStep>(this->knownStepsList[_loc2_])->getTypes().last());
    qSharedPointerCast<TreasureHuntStep>(this->knownStepsList[_loc2_])->serialize(param1);
    _loc2_++;
  }
  if(this->totalStepCount < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->totalStepCount << ") on element totalStepCount.";
  }
  else
  {
    param1->writeByte(this->totalStepCount);
    if(this->checkPointCurrent < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->checkPointCurrent << ") on element checkPointCurrent.";
    }
    else
    {
      param1->writeVarInt((int)this->checkPointCurrent);
      if(this->checkPointTotal < 0)
      {
        qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->checkPointTotal << ") on element checkPointTotal.";
      }
      else
      {
        param1->writeVarInt((int)this->checkPointTotal);
        param1->writeInt((int)this->availableRetryCount);
        param1->writeShort((short)this->flags.size());
        uint _loc3_ = 0;
        while(_loc3_ < this->flags.size())
        {
          (this->flags[_loc3_]).serializeAs_TreasureHuntFlag(param1);
          _loc3_++;
        }
        return;
      }
    }
  }
}

void TreasureHuntMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TreasureHuntMessage(param1);
}

void TreasureHuntMessage::deserializeAs_TreasureHuntMessage(Reader *param1)
{
  uint _loc6_ = 0;
  QSharedPointer<TreasureHuntStep> _loc7_ ;
  TreasureHuntFlag _loc8_ ;
  this->questType = param1->readByte();
  if(this->questType < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->questType << ") on element of TreasureHuntMessage.questType.";
  }
  else
  {
    this->startMapId = param1->readInt();
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc6_ = param1->readUShort();
      _loc7_ = qSharedPointerCast<TreasureHuntStep>(ClassManagerSingleton::get()->getClass(_loc6_));
      _loc7_->deserialize(param1);
      this->knownStepsList.append(_loc7_);
      _loc3_++;
    }
    this->totalStepCount = param1->readByte();
    if(this->totalStepCount < 0)
    {
      qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->totalStepCount << ") on element of TreasureHuntMessage.totalStepCount.";
    }
    else
    {
      this->checkPointCurrent = param1->readVarUhInt();
      if(this->checkPointCurrent < 0)
      {
        qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->checkPointCurrent << ") on element of TreasureHuntMessage.checkPointCurrent.";
      }
      else
      {
        this->checkPointTotal = param1->readVarUhInt();
        if(this->checkPointTotal < 0)
        {
          qDebug()<<"ERREUR - TreasureHuntMessage -"<<"Forbidden value (" << this->checkPointTotal << ") on element of TreasureHuntMessage.checkPointTotal.";
        }
        else
        {
          this->availableRetryCount = param1->readInt();
          uint _loc4_ = param1->readUShort();
          uint _loc5_ = 0;
          while(_loc5_ < _loc4_)
          {
            _loc8_ = TreasureHuntFlag();
            _loc8_.deserialize(param1);
            this->flags.append(_loc8_);
            _loc5_++;
          }
          return;
        }
      }
    }
  }
}

TreasureHuntMessage::TreasureHuntMessage()
{
  m_type = MessageEnum::TREASUREHUNTMESSAGE;
}

