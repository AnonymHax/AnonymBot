#include "JobMultiCraftAvailableSkillsMessage.h"

void JobMultiCraftAvailableSkillsMessage::serialize(Writer *param1)
{
  this->serializeAs_JobMultiCraftAvailableSkillsMessage(param1);
}

void JobMultiCraftAvailableSkillsMessage::serializeAs_JobMultiCraftAvailableSkillsMessage(Writer *param1)
{
  JobAllowMultiCraftRequestMessage::serializeAs_JobAllowMultiCraftRequestMessage(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobMultiCraftAvailableSkillsMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    param1->writeShort((short)this->skills.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->skills.size())
    {
      if(this->skills[_loc2_] < 0)
      {
        qDebug()<<"ERREUR - JobMultiCraftAvailableSkillsMessage -"<<"Forbidden value (" << this->skills[_loc2_] << ") on element 2 (starting at 1) of skills.";
      }
      else
      {
        param1->writeVarShort((int)this->skills[_loc2_]);
        _loc2_++;
        continue;
      }
    }
    return;
  }
}

void JobMultiCraftAvailableSkillsMessage::deserialize(Reader *param1)
{
  this->deserializeAs_JobMultiCraftAvailableSkillsMessage(param1);
}

void JobMultiCraftAvailableSkillsMessage::deserializeAs_JobMultiCraftAvailableSkillsMessage(Reader *param1)
{
  uint _loc4_ = 0;
  JobAllowMultiCraftRequestMessage::deserialize(param1);
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - JobMultiCraftAvailableSkillsMessage -"<<"Forbidden value (" << this->playerId << ") on element of JobMultiCraftAvailableSkillsMessage.playerId.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readVarUhShort();
      if(_loc4_ < 0)
      {
        qDebug()<<"ERREUR - JobMultiCraftAvailableSkillsMessage -"<<"Forbidden value (" << _loc4_ << ") on elements of skills.";
      }
      else
      {
        this->skills.append(_loc4_);
        _loc3_++;
        continue;
      }
    }
    return;
  }
}

JobMultiCraftAvailableSkillsMessage::JobMultiCraftAvailableSkillsMessage()
{
  m_type = MessageEnum::JOBMULTICRAFTAVAILABLESKILLSMESSAGE;
}

