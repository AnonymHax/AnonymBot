#include "DareReward.h"

void DareReward::serialize(Writer *param1)
{
  this->serializeAs_DareReward(param1);
}

void DareReward::serializeAs_DareReward(Writer *param1)
{
  param1->writeByte(this->type);
  if(this->monsterId < 0)
  {
    qDebug()<<"ERREUR - DareReward -"<<"Forbidden value (" << this->monsterId << ") on element monsterId.";
  }
  else
  {
    param1->writeVarShort((int)this->monsterId);
    if(this->kamas < 0 || this->kamas > 4.294967295E9)
    {
      qDebug()<<"ERREUR - DareReward -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
    }
    else
    {
      param1->writeUInt((uint)this->kamas);
      if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - DareReward -"<<"Forbidden value (" << this->dareId << ") on element dareId.";
      }
      else
      {
        param1->writeDouble(this->dareId);
        return;
      }
    }
  }
}

void DareReward::deserialize(Reader *param1)
{
  this->deserializeAs_DareReward(param1);
}

void DareReward::deserializeAs_DareReward(Reader *param1)
{
  this->type = param1->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - DareReward -"<<"Forbidden value (" << this->type << ") on element of DareReward.type.";
  }
  else
  {
    this->monsterId = param1->readVarUhShort();
    if(this->monsterId < 0)
    {
      qDebug()<<"ERREUR - DareReward -"<<"Forbidden value (" << this->monsterId << ") on element of DareReward.monsterId.";
    }
    else
    {
      this->kamas = param1->readUInt();
      if(this->kamas < 0 || this->kamas > 4.294967295E9)
      {
        qDebug()<<"ERREUR - DareReward -"<<"Forbidden value (" << this->kamas << ") on element of DareReward.kamas.";
      }
      else
      {
        this->dareId = param1->readDouble();
        if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - DareReward -"<<"Forbidden value (" << this->dareId << ") on element of DareReward.dareId.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

DareReward::DareReward()
{
  m_types<<ClassEnum::DAREREWARD;
}

bool DareReward::operator==(const DareReward &compared)
{
  if(type == compared.type)
  if(monsterId == compared.monsterId)
  if(kamas == compared.kamas)
  if(dareId == compared.dareId)
  return true;
  
  return false;
}

