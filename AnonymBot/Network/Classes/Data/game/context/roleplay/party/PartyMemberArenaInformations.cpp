#include "PartyMemberArenaInformations.h"

void PartyMemberArenaInformations::serialize(Writer *param1)
{
  this->serializeAs_PartyMemberArenaInformations(param1);
}

void PartyMemberArenaInformations::serializeAs_PartyMemberArenaInformations(Writer *param1)
{
  PartyMemberInformations::serializeAs_PartyMemberInformations(param1);
  if(this->rank < 0 || this->rank > 20000)
  {
    qDebug()<<"ERREUR - PartyMemberArenaInformations -"<<"Forbidden value (" << this->rank << ") on element rank.";
  }
  else
  {
    param1->writeVarShort((int)this->rank);
    return;
  }
}

void PartyMemberArenaInformations::deserialize(Reader *param1)
{
  this->deserializeAs_PartyMemberArenaInformations(param1);
}

void PartyMemberArenaInformations::deserializeAs_PartyMemberArenaInformations(Reader *param1)
{
  PartyMemberInformations::deserialize(param1);
  this->rank = param1->readVarUhShort();
  if(this->rank < 0 || this->rank > 20000)
  {
    qDebug()<<"ERREUR - PartyMemberArenaInformations -"<<"Forbidden value (" << this->rank << ") on element of PartyMemberArenaInformations.rank.";
  }
  else
  {
    return;
  }
}

PartyMemberArenaInformations::PartyMemberArenaInformations()
{
  m_types<<ClassEnum::PARTYMEMBERARENAINFORMATIONS;
}

bool PartyMemberArenaInformations::operator==(const PartyMemberArenaInformations &compared)
{
  if(rank == compared.rank)
  return true;
  
  return false;
}

