#include "PartyCompanionBaseInformations.h"

void PartyCompanionBaseInformations::serialize(Writer *param1)
{
  this->serializeAs_PartyCompanionBaseInformations(param1);
}

void PartyCompanionBaseInformations::serializeAs_PartyCompanionBaseInformations(Writer *param1)
{
  if(this->indexId < 0)
  {
    qDebug()<<"ERREUR - PartyCompanionBaseInformations -"<<"Forbidden value (" << this->indexId << ") on element indexId.";
  }
  else
  {
    param1->writeByte(this->indexId);
    if(this->companionGenericId < 0)
    {
      qDebug()<<"ERREUR - PartyCompanionBaseInformations -"<<"Forbidden value (" << this->companionGenericId << ") on element companionGenericId.";
    }
    else
    {
      param1->writeByte(this->companionGenericId);
      this->entityLook->serializeAs_EntityLook(param1);
      return;
    }
  }
}

void PartyCompanionBaseInformations::deserialize(Reader *param1)
{
  this->deserializeAs_PartyCompanionBaseInformations(param1);
}

void PartyCompanionBaseInformations::deserializeAs_PartyCompanionBaseInformations(Reader *param1)
{
  this->indexId = param1->readByte();
  if(this->indexId < 0)
  {
    qDebug()<<"ERREUR - PartyCompanionBaseInformations -"<<"Forbidden value (" << this->indexId << ") on element of PartyCompanionBaseInformations.indexId.";
  }
  else
  {
    this->companionGenericId = param1->readByte();
    if(this->companionGenericId < 0)
    {
      qDebug()<<"ERREUR - PartyCompanionBaseInformations -"<<"Forbidden value (" << this->companionGenericId << ") on element of PartyCompanionBaseInformations.companionGenericId.";
    }
    else
    {
      this->entityLook = QSharedPointer<EntityLook>(new EntityLook() );
      this->entityLook->deserialize(param1);
      return;
    }
  }
}

PartyCompanionBaseInformations::PartyCompanionBaseInformations()
{
  m_types<<ClassEnum::PARTYCOMPANIONBASEINFORMATIONS;
}

bool PartyCompanionBaseInformations::operator==(const PartyCompanionBaseInformations &compared)
{
  if(indexId == compared.indexId)
  if(companionGenericId == compared.companionGenericId)
  if(entityLook == compared.entityLook)
  return true;
  
  return false;
}

