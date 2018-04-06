#include "PartyMemberInformations.h"

void PartyMemberInformations::serialize(Writer *param1)
{
  this->serializeAs_PartyMemberInformations(param1);
}

void PartyMemberInformations::serializeAs_PartyMemberInformations(Writer *param1)
{
  CharacterBaseInformations::serializeAs_CharacterBaseInformations(param1);
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->lifePoints << ") on element lifePoints.";
  }
  else
  {
    param1->writeVarInt((int)this->lifePoints);
    if(this->maxLifePoints < 0)
    {
      qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->maxLifePoints << ") on element maxLifePoints.";
    }
    else
    {
      param1->writeVarInt((int)this->maxLifePoints);
      if(this->prospecting < 0)
      {
        qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->prospecting << ") on element prospecting.";
      }
      else
      {
        param1->writeVarShort((int)this->prospecting);
        if(this->regenRate < 0 || this->regenRate > 255)
        {
          qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->regenRate << ") on element regenRate.";
        }
        else
        {
          param1->writeByte(this->regenRate);
          if(this->initiative < 0)
          {
            qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->initiative << ") on element initiative.";
          }
          else
          {
            param1->writeVarShort((int)this->initiative);
            param1->writeByte(this->alignmentSide);
            if(this->worldX < -255 || this->worldX > 255)
            {
              qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
            }
            else
            {
              param1->writeShort((short)this->worldX);
              if(this->worldY < -255 || this->worldY > 255)
              {
                qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
              }
              else
              {
                param1->writeShort((short)this->worldY);
                param1->writeInt((int)this->mapId);
                if(this->subAreaId < 0)
                {
                  qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
                }
                else
                {
                  param1->writeVarShort((int)this->subAreaId);
                  param1->writeShort((short)this->status->getTypes().last());
                  this->status->serialize(param1);
                  param1->writeShort((short)this->companions.size());
                  uint _loc2_ = 0;
                  while(_loc2_ < this->companions.size())
                  {
                    qSharedPointerCast<PartyCompanionMemberInformations>(this->companions[_loc2_])->serializeAs_PartyCompanionMemberInformations(param1);
                    _loc2_++;
                  }
                  return;
                }
              }
            }
          }
        }
      }
    }
  }
}

void PartyMemberInformations::deserialize(Reader *param1)
{
  this->deserializeAs_PartyMemberInformations(param1);
}

void PartyMemberInformations::deserializeAs_PartyMemberInformations(Reader *param1)
{
  QSharedPointer<PartyCompanionMemberInformations> _loc5_ ;
  CharacterBaseInformations::deserialize(param1);
  this->lifePoints = param1->readVarUhInt();
  if(this->lifePoints < 0)
  {
    qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->lifePoints << ") on element of PartyMemberInformations.lifePoints.";
  }
  else
  {
    this->maxLifePoints = param1->readVarUhInt();
    if(this->maxLifePoints < 0)
    {
      qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->maxLifePoints << ") on element of PartyMemberInformations.maxLifePoints.";
    }
    else
    {
      this->prospecting = param1->readVarUhShort();
      if(this->prospecting < 0)
      {
        qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->prospecting << ") on element of PartyMemberInformations.prospecting.";
      }
      else
      {
        this->regenRate = param1->readUByte();
        if(this->regenRate < 0 || this->regenRate > 255)
        {
          qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->regenRate << ") on element of PartyMemberInformations.regenRate.";
        }
        else
        {
          this->initiative = param1->readVarUhShort();
          if(this->initiative < 0)
          {
            qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->initiative << ") on element of PartyMemberInformations.initiative.";
          }
          else
          {
            this->alignmentSide = param1->readByte();
            this->worldX = param1->readShort();
            if(this->worldX < -255 || this->worldX > 255)
            {
              qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->worldX << ") on element of PartyMemberInformations.worldX.";
            }
            else
            {
              this->worldY = param1->readShort();
              if(this->worldY < -255 || this->worldY > 255)
              {
                qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->worldY << ") on element of PartyMemberInformations.worldY.";
              }
              else
              {
                this->mapId = param1->readInt();
                this->subAreaId = param1->readVarUhShort();
                if(this->subAreaId < 0)
                {
                  qDebug()<<"ERREUR - PartyMemberInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of PartyMemberInformations.subAreaId.";
                }
                else
                {
                  uint _loc2_ = param1->readUShort();
                  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_loc2_));
                  this->status->deserialize(param1);
                  uint _loc3_ = param1->readUShort();
                  uint _loc4_ = 0;
                  while(_loc4_ < _loc3_)
                  {
                    _loc5_ = QSharedPointer<PartyCompanionMemberInformations>(new PartyCompanionMemberInformations() );
                    _loc5_->deserialize(param1);
                    this->companions.append(_loc5_);
                    _loc4_++;
                  }
                  return;
                }
              }
            }
          }
        }
      }
    }
  }
}

PartyMemberInformations::PartyMemberInformations()
{
  m_types<<ClassEnum::PARTYMEMBERINFORMATIONS;
}

bool PartyMemberInformations::operator==(const PartyMemberInformations &compared)
{
  if(lifePoints == compared.lifePoints)
  if(maxLifePoints == compared.maxLifePoints)
  if(prospecting == compared.prospecting)
  if(regenRate == compared.regenRate)
  if(initiative == compared.initiative)
  if(alignmentSide == compared.alignmentSide)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(status == compared.status)
  if(companions == compared.companions)
  return true;
  
  return false;
}

