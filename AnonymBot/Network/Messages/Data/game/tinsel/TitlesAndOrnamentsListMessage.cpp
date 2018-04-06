#include "TitlesAndOrnamentsListMessage.h"

void TitlesAndOrnamentsListMessage::serialize(Writer *param1)
{
  this->serializeAs_TitlesAndOrnamentsListMessage(param1);
}

void TitlesAndOrnamentsListMessage::serializeAs_TitlesAndOrnamentsListMessage(Writer *param1)
{
  param1->writeShort((short)this->titles.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->titles.size())
  {
    if(this->titles[_loc2_] < 0)
    {
      qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->titles[_loc2_] << ") on element 1 (starting at 1) of titles.";
    }
    else
    {
      param1->writeVarShort((int)this->titles[_loc2_]);
      _loc2_++;
      continue;
    }
  }
  param1->writeShort((short)this->ornaments.size());
  uint _loc3_ = 0;
  while(_loc3_ < this->ornaments.size())
  {
    if(this->ornaments[_loc3_] < 0)
    {
      qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->ornaments[_loc3_] << ") on element 2 (starting at 1) of ornaments.";
    }
    else
    {
      param1->writeVarShort((int)this->ornaments[_loc3_]);
      _loc3_++;
      continue;
    }
  }
  if(this->activeTitle < 0)
  {
    qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->activeTitle << ") on element activeTitle.";
  }
  else
  {
    param1->writeVarShort((int)this->activeTitle);
    if(this->activeOrnament < 0)
    {
      qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->activeOrnament << ") on element activeOrnament.";
    }
    else
    {
      param1->writeVarShort((int)this->activeOrnament);
      return;
    }
  }
}

void TitlesAndOrnamentsListMessage::deserialize(Reader *param1)
{
  this->deserializeAs_TitlesAndOrnamentsListMessage(param1);
}

void TitlesAndOrnamentsListMessage::deserializeAs_TitlesAndOrnamentsListMessage(Reader *param1)
{
  uint _loc6_ = 0;
  uint _loc7_ = 0;
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc6_ = param1->readVarUhShort();
    if(_loc6_ < 0)
    {
      qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << _loc6_ << ") on elements of titles.";
    }
    else
    {
      this->titles.append(_loc6_);
      _loc3_++;
      continue;
    }
  }
  uint _loc4_ = param1->readUShort();
  uint _loc5_ = 0;
  while(_loc5_ < _loc4_)
  {
    _loc7_ = param1->readVarUhShort();
    if(_loc7_ < 0)
    {
      qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << _loc7_ << ") on elements of ornaments.";
    }
    else
    {
      this->ornaments.append(_loc7_);
      _loc5_++;
      continue;
    }
  }
  this->activeTitle = param1->readVarUhShort();
  if(this->activeTitle < 0)
  {
    qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->activeTitle << ") on element of TitlesAndOrnamentsListMessage.activeTitle.";
  }
  else
  {
    this->activeOrnament = param1->readVarUhShort();
    if(this->activeOrnament < 0)
    {
      qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->activeOrnament << ") on element of TitlesAndOrnamentsListMessage.activeOrnament.";
    }
    else
    {
      return;
    }
  }
}

TitlesAndOrnamentsListMessage::TitlesAndOrnamentsListMessage()
{
  m_type = MessageEnum::TITLESANDORNAMENTSLISTMESSAGE;
}

