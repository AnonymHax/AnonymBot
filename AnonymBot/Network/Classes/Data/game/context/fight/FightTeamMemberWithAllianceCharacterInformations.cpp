#include "FightTeamMemberWithAllianceCharacterInformations.h"

void FightTeamMemberWithAllianceCharacterInformations::serialize(Writer *param1)
{
  this->serializeAs_FightTeamMemberWithAllianceCharacterInformations(param1);
}

void FightTeamMemberWithAllianceCharacterInformations::serializeAs_FightTeamMemberWithAllianceCharacterInformations(Writer *param1)
{
  FightTeamMemberCharacterInformations::serializeAs_FightTeamMemberCharacterInformations(param1);
  this->allianceInfos->serializeAs_BasicAllianceInformations(param1);
}

void FightTeamMemberWithAllianceCharacterInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightTeamMemberWithAllianceCharacterInformations(param1);
}

void FightTeamMemberWithAllianceCharacterInformations::deserializeAs_FightTeamMemberWithAllianceCharacterInformations(Reader *param1)
{
  FightTeamMemberCharacterInformations::deserialize(param1);
  this->allianceInfos = QSharedPointer<BasicAllianceInformations>(new BasicAllianceInformations() );
  this->allianceInfos->deserialize(param1);
}

FightTeamMemberWithAllianceCharacterInformations::FightTeamMemberWithAllianceCharacterInformations()
{
  m_types<<ClassEnum::FIGHTTEAMMEMBERWITHALLIANCECHARACTERINFORMATIONS;
}

bool FightTeamMemberWithAllianceCharacterInformations::operator==(const FightTeamMemberWithAllianceCharacterInformations &compared)
{
  if(allianceInfos == compared.allianceInfos)
  return true;
  
  return false;
}

