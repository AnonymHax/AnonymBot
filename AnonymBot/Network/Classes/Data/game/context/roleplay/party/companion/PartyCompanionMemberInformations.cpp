#include "PartyCompanionMemberInformations.h"

void PartyCompanionMemberInformations::serialize(Writer *param1)
{
  this->serializeAs_PartyCompanionMemberInformations(param1);
}

void PartyCompanionMemberInformations::serializeAs_PartyCompanionMemberInformations(Writer *param1)
{
  PartyCompanionBaseInformations::serializeAs_PartyCompanionBaseInformations(param1);
  if(this->initiative < 0)
  {
    qDebug()<<"ERREUR - PartyCompanionMemberInformations -"<<"Forbidden value (" << this->initiative << ") on element initiative.";
  }
  else
  {
    param1->writeVarShort((int)this->initiative);
    if(this->lifePoints < 0)
    {
      qDebug()<<"ERREUR - PartyCompanionMemberInformations -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
    }
    else
    {
      param1->writeVarInt((int)this->lifePoints);
      if(this->maxLifePoints < 0)
      {
        qDebug()<<"ERREUR - PartyCompanionMemberInformations -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
      }
      else
      {
        param1->writeVarInt((int)this->maxLifePoints);
        if(this->prospecting < 0)
        {
          qDebug()<<"ERREUR - PartyCompanionMemberInformations -"<<"Forbidden value (" << this->prospecting << ") on element prospecting.";
        }
        else
        {
          param1->writeVarShort((int)this->prospecting);
          if(this->regenRate < 0 || this->regenRate > 255)
          {
            qDebug()<<"ERREUR - PartyCompanionMemberInformations -"<<"Forbidden value (" << this->regenRate << ") on element regenRate.";
          }
          else
          {
            param1->writeByte(this->regenRate);
            return;
          }
        }
      }
    }
  }
}

void PartyCompanionMemberInformations::deserialize(Reader *param1)
{
  this->deserializeAs_PartyCompanionMemberInformations(param1);
}

void PartyCompanionMemberInformations::deserializeAs_PartyCompanionMemberInformations(Reader *param1)
{
  PartyCompanionBaseInformations::deserialize(param1);
  this->initiative = param1->readVarUhShort();
  if(this->initiative < 0)
  {
    qDebug()<<"ERREUR - PartyCompanionMemberInformations -"<<"Forbidden value (" << this->initiative << ") on element of PartyCompanionMemberInformations.initiative.";
  }
  else
  {
    this->lifePoints = param1->readVarUhInt();
    if(this->lifePoints < 0)
    {
      qDebug()<<"ERREUR - PartyCompanionMemberInformations -"<<"Forbidden value (" << this->lifePoints << ") on element of PartyCompanionMemberInformations.lifePoints.";
    }
    else
    {
      this->maxLifePoints = param1->readVarUhInt();
      if(this->maxLifePoints < 0)
      {
        qDebug()<<"ERREUR - PartyCompanionMemberInformations -"<<"Forbidden value (" << this->maxLifePoints << ") on element of PartyCompanionMemberInformations.maxLifePoints.";
      }
      else
      {
        this->prospecting = param1->readVarUhShort();
        if(this->prospecting < 0)
        {
          qDebug()<<"ERREUR - PartyCompanionMemberInformations -"<<"Forbidden value (" << this->prospecting << ") on element of PartyCompanionMemberInformations.prospecting.";
        }
        else
        {
          this->regenRate = param1->readUByte();
          if(this->regenRate < 0 || this->regenRate > 255)
          {
            qDebug()<<"ERREUR - PartyCompanionMemberInformations -"<<"Forbidden value (" << this->regenRate << ") on element of PartyCompanionMemberInformations.regenRate.";
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

PartyCompanionMemberInformations::PartyCompanionMemberInformations()
{
  m_types<<ClassEnum::PARTYCOMPANIONMEMBERINFORMATIONS;
}

bool PartyCompanionMemberInformations::operator==(const PartyCompanionMemberInformations &compared)
{
  if(initiative == compared.initiative)
  if(lifePoints == compared.lifePoints)
  if(maxLifePoints == compared.maxLifePoints)
  if(prospecting == compared.prospecting)
  if(regenRate == compared.regenRate)
  return true;
  
  return false;
}

