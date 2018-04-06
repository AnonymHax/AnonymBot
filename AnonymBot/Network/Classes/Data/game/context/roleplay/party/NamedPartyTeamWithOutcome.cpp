#include "NamedPartyTeamWithOutcome.h"

void NamedPartyTeamWithOutcome::serialize(Writer *param1)
{
  this->serializeAs_NamedPartyTeamWithOutcome(param1);
}

void NamedPartyTeamWithOutcome::serializeAs_NamedPartyTeamWithOutcome(Writer *param1)
{
  this->team.serializeAs_NamedPartyTeam(param1);
  param1->writeVarShort((int)this->outcome);
}

void NamedPartyTeamWithOutcome::deserialize(Reader *param1)
{
  this->deserializeAs_NamedPartyTeamWithOutcome(param1);
}

void NamedPartyTeamWithOutcome::deserializeAs_NamedPartyTeamWithOutcome(Reader *param1)
{
  this->team = NamedPartyTeam();
  this->team.deserialize(param1);
  this->outcome = param1->readVarUhShort();
  if(this->outcome < 0)
  {
    qDebug()<<"ERREUR - NamedPartyTeamWithOutcome -"<<"Forbidden value (" << this->outcome << ") on element of NamedPartyTeamWithOutcome.outcome.";
  }
  else
  {
    return;
  }
}

NamedPartyTeamWithOutcome::NamedPartyTeamWithOutcome()
{
  m_types<<ClassEnum::NAMEDPARTYTEAMWITHOUTCOME;
}

bool NamedPartyTeamWithOutcome::operator==(const NamedPartyTeamWithOutcome &compared)
{
  if(team == compared.team)
  if(outcome == compared.outcome)
  return true;
  
  return false;
}

