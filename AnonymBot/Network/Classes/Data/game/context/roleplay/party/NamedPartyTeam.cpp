#include "NamedPartyTeam.h"

void NamedPartyTeam::serialize(Writer *param1)
{
  this->serializeAs_NamedPartyTeam(param1);
}

void NamedPartyTeam::serializeAs_NamedPartyTeam(Writer *param1)
{
  param1->writeByte(this->teamId);
  param1->writeUTF(this->partyName);
}

void NamedPartyTeam::deserialize(Reader *param1)
{
  this->deserializeAs_NamedPartyTeam(param1);
}

void NamedPartyTeam::deserializeAs_NamedPartyTeam(Reader *param1)
{
  this->teamId = param1->readByte();
  if(this->teamId < 0)
  {
    qDebug()<<"ERREUR - NamedPartyTeam -"<<"Forbidden value (" << this->teamId << ") on element of NamedPartyTeam.teamId.";
  }
  else
  {
    this->partyName = param1->readUTF();
    return;
  }
}

NamedPartyTeam::NamedPartyTeam()
{
  m_types<<ClassEnum::NAMEDPARTYTEAM;
}

bool NamedPartyTeam::operator==(const NamedPartyTeam &compared)
{
  if(teamId == compared.teamId)
  if(partyName == compared.partyName)
  return true;
  
  return false;
}

