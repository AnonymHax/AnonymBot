#include "AllianceFactSheetInformations.h"

void AllianceFactSheetInformations::serialize(Writer *param1)
{
  this->serializeAs_AllianceFactSheetInformations(param1);
}

void AllianceFactSheetInformations::serializeAs_AllianceFactSheetInformations(Writer *param1)
{
  AllianceInformations::serializeAs_AllianceInformations(param1);
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformations -"<<"Forbidden value (" << this->creationDate << ") on element creationDate.";
  }
  else
  {
    param1->writeInt((int)this->creationDate);
    return;
  }
}

void AllianceFactSheetInformations::deserialize(Reader *param1)
{
  this->deserializeAs_AllianceFactSheetInformations(param1);
}

void AllianceFactSheetInformations::deserializeAs_AllianceFactSheetInformations(Reader *param1)
{
  AllianceInformations::deserialize(param1);
  this->creationDate = param1->readInt();
  if(this->creationDate < 0)
  {
    qDebug()<<"ERREUR - AllianceFactSheetInformations -"<<"Forbidden value (" << this->creationDate << ") on element of AllianceFactSheetInformations.creationDate.";
  }
  else
  {
    return;
  }
}

AllianceFactSheetInformations::AllianceFactSheetInformations()
{
  m_types<<ClassEnum::ALLIANCEFACTSHEETINFORMATIONS;
}

bool AllianceFactSheetInformations::operator==(const AllianceFactSheetInformations &compared)
{
  if(creationDate == compared.creationDate)
  return true;
  
  return false;
}

