#include "TaxCollectorBasicInformations.h"

void TaxCollectorBasicInformations::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorBasicInformations(param1);
}

void TaxCollectorBasicInformations::serializeAs_TaxCollectorBasicInformations(Writer *param1)
{
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  else
  {
    param1->writeVarShort((int)this->firstNameId);
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
    }
    else
    {
      param1->writeVarShort((int)this->lastNameId);
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
      }
      else
      {
        param1->writeShort((short)this->worldX);
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
        }
        else
        {
          param1->writeShort((short)this->worldY);
          param1->writeInt((int)this->mapId);
          if(this->subAreaId < 0)
          {
            qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
          }
          else
          {
            param1->writeVarShort((int)this->subAreaId);
            return;
          }
        }
      }
    }
  }
}

void TaxCollectorBasicInformations::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorBasicInformations(param1);
}

void TaxCollectorBasicInformations::deserializeAs_TaxCollectorBasicInformations(Reader *param1)
{
  this->firstNameId = param1->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->firstNameId << ") on element of TaxCollectorBasicInformations.firstNameId.";
  }
  else
  {
    this->lastNameId = param1->readVarUhShort();
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of TaxCollectorBasicInformations.lastNameId.";
    }
    else
    {
      this->worldX = param1->readShort();
      if(this->worldX < -255 || this->worldX > 255)
      {
        qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->worldX << ") on element of TaxCollectorBasicInformations.worldX.";
      }
      else
      {
        this->worldY = param1->readShort();
        if(this->worldY < -255 || this->worldY > 255)
        {
          qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->worldY << ") on element of TaxCollectorBasicInformations.worldY.";
        }
        else
        {
          this->mapId = param1->readInt();
          this->subAreaId = param1->readVarUhShort();
          if(this->subAreaId < 0)
          {
            qDebug()<<"ERREUR - TaxCollectorBasicInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of TaxCollectorBasicInformations.subAreaId.";
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

TaxCollectorBasicInformations::TaxCollectorBasicInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORBASICINFORMATIONS;
}

bool TaxCollectorBasicInformations::operator==(const TaxCollectorBasicInformations &compared)
{
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  return true;
  
  return false;
}

