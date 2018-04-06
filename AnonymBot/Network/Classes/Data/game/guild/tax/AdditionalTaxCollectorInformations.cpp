#include "AdditionalTaxCollectorInformations.h"

void AdditionalTaxCollectorInformations::serialize(Writer *param1)
{
  this->serializeAs_AdditionalTaxCollectorInformations(param1);
}

void AdditionalTaxCollectorInformations::serializeAs_AdditionalTaxCollectorInformations(Writer *param1)
{
  param1->writeUTF(this->collectorCallerName);
  if(this->date < 0)
  {
    qDebug()<<"ERREUR - AdditionalTaxCollectorInformations -"<<"Forbidden value (" << this->date << ") on element date.";
  }
  else
  {
    param1->writeInt((int)this->date);
    return;
  }
}

void AdditionalTaxCollectorInformations::deserialize(Reader *param1)
{
  this->deserializeAs_AdditionalTaxCollectorInformations(param1);
}

void AdditionalTaxCollectorInformations::deserializeAs_AdditionalTaxCollectorInformations(Reader *param1)
{
  this->collectorCallerName = param1->readUTF();
  this->date = param1->readInt();
  if(this->date < 0)
  {
    qDebug()<<"ERREUR - AdditionalTaxCollectorInformations -"<<"Forbidden value (" << this->date << ") on element of AdditionalTaxCollectorInformations.date.";
  }
  else
  {
    return;
  }
}

AdditionalTaxCollectorInformations::AdditionalTaxCollectorInformations()
{
  m_types<<ClassEnum::ADDITIONALTAXCOLLECTORINFORMATIONS;
}

bool AdditionalTaxCollectorInformations::operator==(const AdditionalTaxCollectorInformations &compared)
{
  if(collectorCallerName == compared.collectorCallerName)
  if(date == compared.date)
  return true;
  
  return false;
}

