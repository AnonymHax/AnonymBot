#include "TaxCollectorLootInformations.h"

void TaxCollectorLootInformations::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorLootInformations(param1);
}

void TaxCollectorLootInformations::serializeAs_TaxCollectorLootInformations(Writer *param1)
{
  TaxCollectorComplementaryInformations::serializeAs_TaxCollectorComplementaryInformations(param1);
  if(this->kamas < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->kamas << ") on element kamas.";
  }
  else
  {
    param1->writeVarInt((int)this->kamas);
    if(this->experience < 0 || this->experience > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->experience << ") on element experience.";
    }
    else
    {
      param1->writeVarLong((double)this->experience);
      if(this->pods < 0)
      {
        qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->pods << ") on element pods.";
      }
      else
      {
        param1->writeVarInt((int)this->pods);
        if(this->itemsValue < 0)
        {
          qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->itemsValue << ") on element itemsValue.";
        }
        else
        {
          param1->writeVarInt((int)this->itemsValue);
          return;
        }
      }
    }
  }
}

void TaxCollectorLootInformations::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorLootInformations(param1);
}

void TaxCollectorLootInformations::deserializeAs_TaxCollectorLootInformations(Reader *param1)
{
  TaxCollectorComplementaryInformations::deserialize(param1);
  this->kamas = param1->readVarUhInt();
  if(this->kamas < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->kamas << ") on element of TaxCollectorLootInformations.kamas.";
  }
  else
  {
    this->experience = param1->readVarUhLong();
    if(this->experience < 0 || this->experience > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->experience << ") on element of TaxCollectorLootInformations.experience.";
    }
    else
    {
      this->pods = param1->readVarUhInt();
      if(this->pods < 0)
      {
        qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->pods << ") on element of TaxCollectorLootInformations.pods.";
      }
      else
      {
        this->itemsValue = param1->readVarUhInt();
        if(this->itemsValue < 0)
        {
          qDebug()<<"ERREUR - TaxCollectorLootInformations -"<<"Forbidden value (" << this->itemsValue << ") on element of TaxCollectorLootInformations.itemsValue.";
        }
        else
        {
          return;
        }
      }
    }
  }
}

TaxCollectorLootInformations::TaxCollectorLootInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORLOOTINFORMATIONS;
}

bool TaxCollectorLootInformations::operator==(const TaxCollectorLootInformations &compared)
{
  if(kamas == compared.kamas)
  if(experience == compared.experience)
  if(pods == compared.pods)
  if(itemsValue == compared.itemsValue)
  return true;
  
  return false;
}

