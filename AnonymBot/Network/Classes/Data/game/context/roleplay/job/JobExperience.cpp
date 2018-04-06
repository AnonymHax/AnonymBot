#include "JobExperience.h"

void JobExperience::serialize(Writer *param1)
{
  this->serializeAs_JobExperience(param1);
}

void JobExperience::serializeAs_JobExperience(Writer *param1)
{
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobId << ") on element jobId.";
  }
  else
  {
    param1->writeByte(this->jobId);
    if(this->jobLevel < 0 || this->jobLevel > 255)
    {
      qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobLevel << ") on element jobLevel.";
    }
    else
    {
      param1->writeByte(this->jobLevel);
      if(this->jobXP < 0 || this->jobXP > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXP << ") on element jobXP.";
      }
      else
      {
        param1->writeVarLong((double)this->jobXP);
        if(this->jobXpLevelFloor < 0 || this->jobXpLevelFloor > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXpLevelFloor << ") on element jobXpLevelFloor.";
        }
        else
        {
          param1->writeVarLong((double)this->jobXpLevelFloor);
          if(this->jobXpNextLevelFloor < 0 || this->jobXpNextLevelFloor > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXpNextLevelFloor << ") on element jobXpNextLevelFloor.";
          }
          else
          {
            param1->writeVarLong((double)this->jobXpNextLevelFloor);
            return;
          }
        }
      }
    }
  }
}

void JobExperience::deserialize(Reader *param1)
{
  this->deserializeAs_JobExperience(param1);
}

void JobExperience::deserializeAs_JobExperience(Reader *param1)
{
  this->jobId = param1->readByte();
  if(this->jobId < 0)
  {
    qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobId << ") on element of JobExperience.jobId.";
  }
  else
  {
    this->jobLevel = param1->readUByte();
    if(this->jobLevel < 0 || this->jobLevel > 255)
    {
      qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobLevel << ") on element of JobExperience.jobLevel.";
    }
    else
    {
      this->jobXP = param1->readVarUhLong();
      if(this->jobXP < 0 || this->jobXP > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXP << ") on element of JobExperience.jobXP.";
      }
      else
      {
        this->jobXpLevelFloor = param1->readVarUhLong();
        if(this->jobXpLevelFloor < 0 || this->jobXpLevelFloor > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXpLevelFloor << ") on element of JobExperience.jobXpLevelFloor.";
        }
        else
        {
          this->jobXpNextLevelFloor = param1->readVarUhLong();
          if(this->jobXpNextLevelFloor < 0 || this->jobXpNextLevelFloor > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - JobExperience -"<<"Forbidden value (" << this->jobXpNextLevelFloor << ") on element of JobExperience.jobXpNextLevelFloor.";
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

JobExperience::JobExperience()
{
  m_types<<ClassEnum::JOBEXPERIENCE;
}

bool JobExperience::operator==(const JobExperience &compared)
{
  if(jobId == compared.jobId)
  if(jobLevel == compared.jobLevel)
  if(jobXP == compared.jobXP)
  if(jobXpLevelFloor == compared.jobXpLevelFloor)
  if(jobXpNextLevelFloor == compared.jobXpNextLevelFloor)
  return true;
  
  return false;
}

