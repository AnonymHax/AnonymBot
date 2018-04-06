#include "FightResultPvpData.h"

void FightResultPvpData::serialize(Writer *param1)
{
  this->serializeAs_FightResultPvpData(param1);
}

void FightResultPvpData::serializeAs_FightResultPvpData(Writer *param1)
{
  FightResultAdditionalData::serializeAs_FightResultAdditionalData(param1);
  if(this->grade < 0 || this->grade > 255)
  {
    qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->grade << ") on element grade.";
  }
  else
  {
    param1->writeByte(this->grade);
    if(this->minHonorForGrade < 0 || this->minHonorForGrade > 20000)
    {
      qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->minHonorForGrade << ") on element minHonorForGrade.";
    }
    else
    {
      param1->writeVarShort((int)this->minHonorForGrade);
      if(this->maxHonorForGrade < 0 || this->maxHonorForGrade > 20000)
      {
        qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->maxHonorForGrade << ") on element maxHonorForGrade.";
      }
      else
      {
        param1->writeVarShort((int)this->maxHonorForGrade);
        if(this->honor < 0 || this->honor > 20000)
        {
          qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->honor << ") on element honor.";
        }
        else
        {
          param1->writeVarShort((int)this->honor);
          param1->writeVarShort((int)this->honorDelta);
          return;
        }
      }
    }
  }
}

void FightResultPvpData::deserialize(Reader *param1)
{
  this->deserializeAs_FightResultPvpData(param1);
}

void FightResultPvpData::deserializeAs_FightResultPvpData(Reader *param1)
{
  FightResultAdditionalData::deserialize(param1);
  this->grade = param1->readUByte();
  if(this->grade < 0 || this->grade > 255)
  {
    qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->grade << ") on element of FightResultPvpData.grade.";
  }
  else
  {
    this->minHonorForGrade = param1->readVarUhShort();
    if(this->minHonorForGrade < 0 || this->minHonorForGrade > 20000)
    {
      qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->minHonorForGrade << ") on element of FightResultPvpData.minHonorForGrade.";
    }
    else
    {
      this->maxHonorForGrade = param1->readVarUhShort();
      if(this->maxHonorForGrade < 0 || this->maxHonorForGrade > 20000)
      {
        qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->maxHonorForGrade << ") on element of FightResultPvpData.maxHonorForGrade.";
      }
      else
      {
        this->honor = param1->readVarUhShort();
        if(this->honor < 0 || this->honor > 20000)
        {
          qDebug()<<"ERREUR - FightResultPvpData -"<<"Forbidden value (" << this->honor << ") on element of FightResultPvpData.honor.";
        }
        else
        {
          this->honorDelta = param1->readVarShort();
          return;
        }
      }
    }
  }
}

FightResultPvpData::FightResultPvpData()
{
  m_types<<ClassEnum::FIGHTRESULTPVPDATA;
}

bool FightResultPvpData::operator==(const FightResultPvpData &compared)
{
  if(grade == compared.grade)
  if(minHonorForGrade == compared.minHonorForGrade)
  if(maxHonorForGrade == compared.maxHonorForGrade)
  if(honor == compared.honor)
  if(honorDelta == compared.honorDelta)
  return true;
  
  return false;
}

