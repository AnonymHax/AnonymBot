#include "BasicAllianceInformations.h"

void BasicAllianceInformations::serialize(Writer *param1)
{
  this->serializeAs_BasicAllianceInformations(param1);
}

void BasicAllianceInformations::serializeAs_BasicAllianceInformations(Writer *param1)
{
  AbstractSocialGroupInfos::serializeAs_AbstractSocialGroupInfos(param1);
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - BasicAllianceInformations -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
  }
  else
  {
    param1->writeVarInt((int)this->allianceId);
    param1->writeUTF(this->allianceTag);
    return;
  }
}

void BasicAllianceInformations::deserialize(Reader *param1)
{
  this->deserializeAs_BasicAllianceInformations(param1);
}

void BasicAllianceInformations::deserializeAs_BasicAllianceInformations(Reader *param1)
{
  AbstractSocialGroupInfos::deserialize(param1);
  this->allianceId = param1->readVarUhInt();
  if(this->allianceId < 0)
  {
    qDebug()<<"ERREUR - BasicAllianceInformations -"<<"Forbidden value (" << this->allianceId << ") on element of BasicAllianceInformations.allianceId.";
  }
  else
  {
    this->allianceTag = param1->readUTF();
    return;
  }
}

BasicAllianceInformations::BasicAllianceInformations()
{
  m_types<<ClassEnum::BASICALLIANCEINFORMATIONS;
}

bool BasicAllianceInformations::operator==(const BasicAllianceInformations &compared)
{
  if(allianceId == compared.allianceId)
  if(allianceTag == compared.allianceTag)
  return true;
  
  return false;
}

