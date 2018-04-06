#include "PrismInformation.h"

void PrismInformation::serialize(Writer *param1)
{
  this->serializeAs_PrismInformation(param1);
}

void PrismInformation::serializeAs_PrismInformation(Writer *param1)
{
  if(this->typeId < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->typeId << ") on element typeId.";
  }
  else
  {
    param1->writeByte(this->typeId);
    param1->writeByte(this->state);
    if(this->nextVulnerabilityDate < 0)
    {
      qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->nextVulnerabilityDate << ") on element nextVulnerabilityDate.";
    }
    else
    {
      param1->writeInt((int)this->nextVulnerabilityDate);
      if(this->placementDate < 0)
      {
        qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->placementDate << ") on element placementDate.";
      }
      else
      {
        param1->writeInt((int)this->placementDate);
        if(this->rewardTokenCount < 0)
        {
          qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->rewardTokenCount << ") on element rewardTokenCount.";
        }
        else
        {
          param1->writeVarInt((int)this->rewardTokenCount);
          return;
        }
      }
    }
  }
}

void PrismInformation::deserialize(Reader *param1)
{
  this->deserializeAs_PrismInformation(param1);
}

void PrismInformation::deserializeAs_PrismInformation(Reader *param1)
{
  this->typeId = param1->readByte();
  if(this->typeId < 0)
  {
    qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->typeId << ") on element of PrismInformation.typeId.";
  }
  else
  {
    this->state = param1->readByte();
    if(this->state < 0)
    {
      qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->state << ") on element of PrismInformation.state.";
    }
    else
    {
      this->nextVulnerabilityDate = param1->readInt();
      if(this->nextVulnerabilityDate < 0)
      {
        qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->nextVulnerabilityDate << ") on element of PrismInformation.nextVulnerabilityDate.";
      }
      else
      {
        this->placementDate = param1->readInt();
        if(this->placementDate < 0)
        {
          qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->placementDate << ") on element of PrismInformation.placementDate.";
        }
        else
        {
          this->rewardTokenCount = param1->readVarUhInt();
          if(this->rewardTokenCount < 0)
          {
            qDebug()<<"ERREUR - PrismInformation -"<<"Forbidden value (" << this->rewardTokenCount << ") on element of PrismInformation.rewardTokenCount.";
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

PrismInformation::PrismInformation()
{
  m_types<<ClassEnum::PRISMINFORMATION;
}

bool PrismInformation::operator==(const PrismInformation &compared)
{
  if(typeId == compared.typeId)
  if(state == compared.state)
  if(nextVulnerabilityDate == compared.nextVulnerabilityDate)
  if(placementDate == compared.placementDate)
  if(rewardTokenCount == compared.rewardTokenCount)
  return true;
  
  return false;
}

