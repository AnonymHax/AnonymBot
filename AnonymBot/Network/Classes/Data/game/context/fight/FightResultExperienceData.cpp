#include "FightResultExperienceData.h"

void FightResultExperienceData::serialize(Writer *param1)
{
  this->serializeAs_FightResultExperienceData(param1);
}

void FightResultExperienceData::serializeAs_FightResultExperienceData(Writer *param1)
{
  FightResultAdditionalData::serializeAs_FightResultAdditionalData(param1);
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->showExperience);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->showExperienceLevelFloor);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->showExperienceNextLevelFloor);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 3, this->showExperienceFightDelta);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 4, this->showExperienceForGuild);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 5, this->showExperienceForMount);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 6, this->isIncarnationExperience);
  param1->writeByte(_loc2_);
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experience << ") on element experience.";
  }
  else
  {
    param1->writeVarLong((double)this->experience);
    if(this->experienceLevelFloor < 0 || this->experienceLevelFloor > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceLevelFloor << ") on element experienceLevelFloor.";
    }
    else
    {
      param1->writeVarLong((double)this->experienceLevelFloor);
      if(this->experienceNextLevelFloor < 0 || this->experienceNextLevelFloor > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceNextLevelFloor << ") on element experienceNextLevelFloor.";
      }
      else
      {
        param1->writeVarLong((double)this->experienceNextLevelFloor);
        if(this->experienceFightDelta < 0 || this->experienceFightDelta > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceFightDelta << ") on element experienceFightDelta.";
        }
        else
        {
          param1->writeVarLong((double)this->experienceFightDelta);
          if(this->experienceForGuild < 0 || this->experienceForGuild > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceForGuild << ") on element experienceForGuild.";
          }
          else
          {
            param1->writeVarLong((double)this->experienceForGuild);
            if(this->experienceForMount < 0 || this->experienceForMount > 9.007199254740992E15)
            {
              qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceForMount << ") on element experienceForMount.";
            }
            else
            {
              param1->writeVarLong((double)this->experienceForMount);
              if(this->rerollExperienceMul < 0)
              {
                qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->rerollExperienceMul << ") on element rerollExperienceMul.";
              }
              else
              {
                param1->writeByte(this->rerollExperienceMul);
                return;
              }
            }
          }
        }
      }
    }
  }
}

void FightResultExperienceData::deserialize(Reader *param1)
{
  this->deserializeAs_FightResultExperienceData(param1);
}

void FightResultExperienceData::deserializeAs_FightResultExperienceData(Reader *param1)
{
  FightResultAdditionalData::deserialize(param1);
  uint _loc2_ = param1->readByte();
  this->showExperience = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->showExperienceLevelFloor = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->showExperienceNextLevelFloor = BooleanByteWrapper::getFlag(_loc2_, 2);
  this->showExperienceFightDelta = BooleanByteWrapper::getFlag(_loc2_, 3);
  this->showExperienceForGuild = BooleanByteWrapper::getFlag(_loc2_, 4);
  this->showExperienceForMount = BooleanByteWrapper::getFlag(_loc2_, 5);
  this->isIncarnationExperience = BooleanByteWrapper::getFlag(_loc2_, 6);
  this->experience = param1->readVarUhLong();
  if(this->experience < 0 || this->experience > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experience << ") on element of FightResultExperienceData.experience.";
  }
  else
  {
    this->experienceLevelFloor = param1->readVarUhLong();
    if(this->experienceLevelFloor < 0 || this->experienceLevelFloor > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceLevelFloor << ") on element of FightResultExperienceData.experienceLevelFloor.";
    }
    else
    {
      this->experienceNextLevelFloor = param1->readVarUhLong();
      if(this->experienceNextLevelFloor < 0 || this->experienceNextLevelFloor > 9.007199254740992E15)
      {
        qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceNextLevelFloor << ") on element of FightResultExperienceData.experienceNextLevelFloor.";
      }
      else
      {
        this->experienceFightDelta = param1->readVarUhLong();
        if(this->experienceFightDelta < 0 || this->experienceFightDelta > 9.007199254740992E15)
        {
          qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceFightDelta << ") on element of FightResultExperienceData.experienceFightDelta.";
        }
        else
        {
          this->experienceForGuild = param1->readVarUhLong();
          if(this->experienceForGuild < 0 || this->experienceForGuild > 9.007199254740992E15)
          {
            qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceForGuild << ") on element of FightResultExperienceData.experienceForGuild.";
          }
          else
          {
            this->experienceForMount = param1->readVarUhLong();
            if(this->experienceForMount < 0 || this->experienceForMount > 9.007199254740992E15)
            {
              qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->experienceForMount << ") on element of FightResultExperienceData.experienceForMount.";
            }
            else
            {
              this->rerollExperienceMul = param1->readByte();
              if(this->rerollExperienceMul < 0)
              {
                qDebug()<<"ERREUR - FightResultExperienceData -"<<"Forbidden value (" << this->rerollExperienceMul << ") on element of FightResultExperienceData.rerollExperienceMul.";
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
}

FightResultExperienceData::FightResultExperienceData()
{
  m_types<<ClassEnum::FIGHTRESULTEXPERIENCEDATA;
}

bool FightResultExperienceData::operator==(const FightResultExperienceData &compared)
{
  if(experience == compared.experience)
  if(showExperience == compared.showExperience)
  if(experienceLevelFloor == compared.experienceLevelFloor)
  if(showExperienceLevelFloor == compared.showExperienceLevelFloor)
  if(experienceNextLevelFloor == compared.experienceNextLevelFloor)
  if(showExperienceNextLevelFloor == compared.showExperienceNextLevelFloor)
  if(experienceFightDelta == compared.experienceFightDelta)
  if(showExperienceFightDelta == compared.showExperienceFightDelta)
  if(experienceForGuild == compared.experienceForGuild)
  if(showExperienceForGuild == compared.showExperienceForGuild)
  if(experienceForMount == compared.experienceForMount)
  if(showExperienceForMount == compared.showExperienceForMount)
  if(isIncarnationExperience == compared.isIncarnationExperience)
  if(rerollExperienceMul == compared.rerollExperienceMul)
  return true;
  
  return false;
}

