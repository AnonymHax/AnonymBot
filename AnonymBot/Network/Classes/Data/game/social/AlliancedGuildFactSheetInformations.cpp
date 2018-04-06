#include "AlliancedGuildFactSheetInformations.h"

void AlliancedGuildFactSheetInformations::serialize(Writer *param1)
{
  this->serializeAs_AlliancedGuildFactSheetInformations(param1);
}

void AlliancedGuildFactSheetInformations::serializeAs_AlliancedGuildFactSheetInformations(Writer *param1)
{
  GuildInformations::serializeAs_GuildInformations(param1);
  this->allianceInfos->serializeAs_BasicNamedAllianceInformations(param1);
}

void AlliancedGuildFactSheetInformations::deserialize(Reader *param1)
{
  this->deserializeAs_AlliancedGuildFactSheetInformations(param1);
}

void AlliancedGuildFactSheetInformations::deserializeAs_AlliancedGuildFactSheetInformations(Reader *param1)
{
  GuildInformations::deserialize(param1);
  this->allianceInfos = QSharedPointer<BasicNamedAllianceInformations>(new BasicNamedAllianceInformations() );
  this->allianceInfos->deserialize(param1);
}

AlliancedGuildFactSheetInformations::AlliancedGuildFactSheetInformations()
{
  m_types<<ClassEnum::ALLIANCEDGUILDFACTSHEETINFORMATIONS;
}

bool AlliancedGuildFactSheetInformations::operator==(const AlliancedGuildFactSheetInformations &compared)
{
  if(allianceInfos == compared.allianceInfos)
  return true;
  
  return false;
}

