#include "TaxCollectorStaticInformations.h"

void TaxCollectorStaticInformations::serialize(Writer *param1)
{
  this->serializeAs_TaxCollectorStaticInformations(param1);
}

void TaxCollectorStaticInformations::serializeAs_TaxCollectorStaticInformations(Writer *param1)
{
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  else
  {
    param1->writeVarShort((int)this->firstNameId);
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
    }
    else
    {
      param1->writeVarShort((int)this->lastNameId);
      this->guildIdentity->serializeAs_GuildInformations(param1);
      return;
    }
  }
}

void TaxCollectorStaticInformations::deserialize(Reader *param1)
{
  this->deserializeAs_TaxCollectorStaticInformations(param1);
}

void TaxCollectorStaticInformations::deserializeAs_TaxCollectorStaticInformations(Reader *param1)
{
  this->firstNameId = param1->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->firstNameId << ") on element of TaxCollectorStaticInformations.firstNameId.";
  }
  else
  {
    this->lastNameId = param1->readVarUhShort();
    if(this->lastNameId < 0)
    {
      qDebug()<<"ERREUR - TaxCollectorStaticInformations -"<<"Forbidden value (" << this->lastNameId << ") on element of TaxCollectorStaticInformations.lastNameId.";
    }
    else
    {
      this->guildIdentity = QSharedPointer<GuildInformations>(new GuildInformations() );
      this->guildIdentity->deserialize(param1);
      return;
    }
  }
}

TaxCollectorStaticInformations::TaxCollectorStaticInformations()
{
  m_types<<ClassEnum::TAXCOLLECTORSTATICINFORMATIONS;
}

bool TaxCollectorStaticInformations::operator==(const TaxCollectorStaticInformations &compared)
{
  if(firstNameId == compared.firstNameId)
  if(lastNameId == compared.lastNameId)
  if(guildIdentity == compared.guildIdentity)
  return true;
  
  return false;
}

