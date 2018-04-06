#include "KohUpdateMessage.h"

void KohUpdateMessage::serialize(Writer *param1)
{
  this->serializeAs_KohUpdateMessage(param1);
}

void KohUpdateMessage::serializeAs_KohUpdateMessage(Writer *param1)
{
  param1->writeShort((short)this->alliances.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->alliances.size())
  {
    qSharedPointerCast<AllianceInformations>(this->alliances[_loc2_])->serializeAs_AllianceInformations(param1);
    _loc2_++;
  }
  param1->writeShort((short)this->allianceNbMembers.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->allianceNbMembers.size())
  {
    if(this->allianceNbMembers[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceNbMembers[_loc3_] << ") on element 2 (starting at 1) of allianceNbMembers.";
    }
    else
    {
      param1->writeVarShort((int)this->allianceNbMembers[_loc3_]);
      _loc3_++;
      continue;
    }
  }
  param1->writeShort((short)this->allianceRoundWeigth.size());
  uint _loc4_ = 0;
  while(_loc4_ < this->allianceRoundWeigth.size())
  {
    if(this->allianceRoundWeigth[_loc4_] < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceRoundWeigth[_loc4_] << ") on element 3 (starting at 1) of allianceRoundWeigth.";
    }
    else
    {
      param1->writeVarInt((int)this->allianceRoundWeigth[_loc4_]);
      _loc4_++;
      continue;
    }
  }
  param1->writeShort((short)this->allianceMatchScore.size());
  uint _loc5_ = 0;
  while(_loc5_ < this->allianceMatchScore.size())
  {
    if(this->allianceMatchScore[_loc5_] < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceMatchScore[_loc5_] << ") on element 4 (starting at 1) of allianceMatchScore.";
    }
    else
    {
      param1->writeByte(this->allianceMatchScore[_loc5_]);
      _loc5_++;
      continue;
    }
  }
  this->allianceMapWinner->serializeAs_BasicAllianceInformations(param1);
  if(this->allianceMapWinnerScore < 0)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceMapWinnerScore << ") on element allianceMapWinnerScore.";
  }
  else
  {
    param1->writeVarInt((int)this->allianceMapWinnerScore);
    if(this->allianceMapMyAllianceScore < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceMapMyAllianceScore << ") on element allianceMapMyAllianceScore.";
    }
    else
    {
      param1->writeVarInt((int)this->allianceMapMyAllianceScore);
      if(this->nextTickTime < 0 || this->nextTickTime > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->nextTickTime << ") on element nextTickTime.";
      }
      else
      {
        param1->writeDouble(this->nextTickTime);
        return;
      }
    }
  }
}

void KohUpdateMessage::deserialize(Reader *param1)
{
  this->deserializeAs_KohUpdateMessage(param1);
}

void KohUpdateMessage::deserializeAs_KohUpdateMessage(Reader *param1)
{
  QSharedPointer<AllianceInformations> _loc10_ ;
  uint _loc11_ = 0;
  uint _loc12_ = 0;
  uint _loc13_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc10_ = QSharedPointer<AllianceInformations>(new AllianceInformations() );
    _loc10_->deserialize(param1);
    this->alliances.append(_loc10_);
    _loc3_++;
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc11_ = param1->readVarUhShort();
    if(_loc11_ < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << _loc11_ << ") on elements of allianceNbMembers.";
    }
    else
    {
      this->allianceNbMembers.append(_loc11_);
      _loc5_++;
      continue;
    }
  }
  uint _loc6_ = param1->readUShort();
  uint _loc7_ = 0;
  while(_loc7_ < _loc6_)
  {
    _loc12_ = param1->readVarUhInt();
    if(_loc12_ < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << _loc12_ << ") on elements of allianceRoundWeigth.";
    }
    else
    {
      this->allianceRoundWeigth.append(_loc12_);
      _loc7_++;
      continue;
    }
  }
  uint _loc8_ = param1->readUShort();
  uint _loc9_ = 0;
  while(_loc9_ < _loc8_)
  {
    _loc13_ = param1->readByte();
    if(_loc13_ < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << _loc13_ << ") on elements of allianceMatchScore.";
    }
    else
    {
      this->allianceMatchScore.append(_loc13_);
      _loc9_++;
      continue;
    }
  }
  this->allianceMapWinner = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->allianceMapWinner->deserialize(param1);
  this->allianceMapWinnerScore = param1->readVarUhInt();
  if(this->allianceMapWinnerScore < 0)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceMapWinnerScore << ") on element of KohUpdateMessage.allianceMapWinnerScore.";
  }
  else
  {
    this->allianceMapMyAllianceScore = param1->readVarUhInt();
    if(this->allianceMapMyAllianceScore < 0)
    {
      qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->allianceMapMyAllianceScore << ") on element of KohUpdateMessage.allianceMapMyAllianceScore.";
    }
    else
    {
      this->nextTickTime = param1->readDouble();
      if(this->nextTickTime < 0 || this->nextTickTime > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->nextTickTime << ") on element of KohUpdateMessage.nextTickTime.";
      }
      else
      {
        return;
      }
    }
  }
}

KohUpdateMessage::KohUpdateMessage()
{
  m_type = MessageEnum::KOHUPDATEMESSAGE;
}

