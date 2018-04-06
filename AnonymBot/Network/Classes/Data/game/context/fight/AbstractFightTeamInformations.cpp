#include "AbstractFightTeamInformations.h"

void AbstractFightTeamInformations::serialize(Writer *param1)
{
  this->serializeAs_AbstractFightTeamInformations(param1);
}

void AbstractFightTeamInformations::serializeAs_AbstractFightTeamInformations(Writer *param1)
{
  param1->writeByte(this->teamId);
  if(this->leaderId < -9.007199254740992E15 || this->leaderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->leaderId << ") on element leaderId.";
  }
  else
  {
    param1->writeDouble(this->leaderId);
    param1->writeByte(this->teamSide);
    param1->writeByte(this->teamTypeId);
    if(this->nbWaves < 0)
    {
      qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->nbWaves << ") on element nbWaves.";
    }
    else
    {
      param1->writeByte(this->nbWaves);
      return;
    }
  }
}

void AbstractFightTeamInformations::deserialize(Reader *param1)
{
  this->deserializeAs_AbstractFightTeamInformations(param1);
}

void AbstractFightTeamInformations::deserializeAs_AbstractFightTeamInformations(Reader *param1)
{
  this->teamId = param1->readByte();
  if(this->teamId < 0)
  {
    qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->teamId << ") on element of AbstractFightTeamInformations.teamId.";
  }
  else
  {
    this->leaderId = param1->readDouble();
    if(this->leaderId < -9.007199254740992E15 || this->leaderId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->leaderId << ") on element of AbstractFightTeamInformations.leaderId.";
    }
    else
    {
      this->teamSide = param1->readByte();
      this->teamTypeId = param1->readByte();
      if(this->teamTypeId < 0)
      {
        qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->teamTypeId << ") on element of AbstractFightTeamInformations.teamTypeId.";
      }
      else
      {
        this->nbWaves = param1->readByte();
        if(this->nbWaves < 0)
        {
          qDebug()<<"ERREUR - AbstractFightTeamInformations -"<<"Forbidden value (" << this->nbWaves << ") on element of AbstractFightTeamInformations.nbWaves.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

AbstractFightTeamInformations::AbstractFightTeamInformations()
{
  m_types<<ClassEnum::ABSTRACTFIGHTTEAMINFORMATIONS;
}

bool AbstractFightTeamInformations::operator==(const AbstractFightTeamInformations &compared)
{
  if(teamId == compared.teamId)
  if(leaderId == compared.leaderId)
  if(teamSide == compared.teamSide)
  if(teamTypeId == compared.teamTypeId)
  if(nbWaves == compared.nbWaves)
  return true;
  
  return false;
}

