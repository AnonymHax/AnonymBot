#include "PrismSubareaEmptyInfo.h"

void PrismSubareaEmptyInfo::serialize(Writer *param1)
{
  this->serializeAs_PrismSubareaEmptyInfo(param1);
}

void PrismSubareaEmptyInfo::serializeAs_PrismSubareaEmptyInfo(Writer *param1)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSubareaEmptyInfo -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  else
  {
    param1->writeVarShort((int)this->subAreaId);
    if(this->allianceId < 0)
    {
      qDebug()<<"ERREUR - PrismSubareaEmptyInfo -"<<"Forbidden value (" << this->allianceId << ") on element allianceId.";
    }
    else
    {
      param1->writeVarInt((int)this->allianceId);
      return;
    }
  }
}

void PrismSubareaEmptyInfo::deserialize(Reader *param1)
{
  this->deserializeAs_PrismSubareaEmptyInfo(param1);
}

void PrismSubareaEmptyInfo::deserializeAs_PrismSubareaEmptyInfo(Reader *param1)
{
  this->subAreaId = param1->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSubareaEmptyInfo -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismSubareaEmptyInfo.subAreaId.";
  }
  else
  {
    this->allianceId = param1->readVarUhInt();
    if(this->allianceId < 0)
    {
      qDebug()<<"ERREUR - PrismSubareaEmptyInfo -"<<"Forbidden value (" << this->allianceId << ") on element of PrismSubareaEmptyInfo.allianceId.";
    }
    else
    {
      return;
    }
  }
}

PrismSubareaEmptyInfo::PrismSubareaEmptyInfo()
{
  m_types<<ClassEnum::PRISMSUBAREAEMPTYINFO;
}

bool PrismSubareaEmptyInfo::operator==(const PrismSubareaEmptyInfo &compared)
{
  if(subAreaId == compared.subAreaId)
  if(allianceId == compared.allianceId)
  return true;
  
  return false;
}

