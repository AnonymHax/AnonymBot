#include "PartyInvitationMemberInformations.h"

void PartyInvitationMemberInformations::serialize(Writer *param1)
{
  this->serializeAs_PartyInvitationMemberInformations(param1);
}

void PartyInvitationMemberInformations::serializeAs_PartyInvitationMemberInformations(Writer *param1)
{
  CharacterBaseInformations::serializeAs_CharacterBaseInformations(param1);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  else
  {
    param1->writeShort((short)this->worldX);
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
    }
    else
    {
      param1->writeShort((short)this->worldY);
      param1->writeInt((int)this->mapId);
      if(this->subAreaId < 0)
      {
        qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
      }
      else
      {
        param1->writeVarShort((int)this->subAreaId);
        param1->writeShort((short)this->companions.size());
        uint _loc2_ = 0;
        while(_loc2_ < this->companions.size())
        {
          qSharedPointerCast<PartyCompanionBaseInformations>(this->companions[_loc2_])->serializeAs_PartyCompanionBaseInformations(param1);
          _loc2_++;
        }
        return;
      }
    }
  }
}

void PartyInvitationMemberInformations::deserialize(Reader *param1)
{
  this->deserializeAs_PartyInvitationMemberInformations(param1);
}

void PartyInvitationMemberInformations::deserializeAs_PartyInvitationMemberInformations(Reader *param1)
{
  QSharedPointer<PartyCompanionBaseInformations> _loc4_ ;
  CharacterBaseInformations::deserialize(param1);
  this->worldX = param1->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->worldX << ") on element of PartyInvitationMemberInformations.worldX.";
  }
  else
  {
    this->worldY = param1->readShort();
    if(this->worldY < -255 || this->worldY > 255)
    {
      qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->worldY << ") on element of PartyInvitationMemberInformations.worldY.";
    }
    else
    {
      this->mapId = param1->readInt();
      this->subAreaId = param1->readVarUhShort();
      if(this->subAreaId < 0)
      {
        qDebug()<<"ERREUR - PartyInvitationMemberInformations -"<<"Forbidden value (" << this->subAreaId << ") on element of PartyInvitationMemberInformations.subAreaId.";
      }
      else
      {
        uint _loc2_ = param1->readUShort();
        uint _loc3_ = 0;
        while(_loc3_ < _loc2_)
        {
          _loc4_ = QSharedPointer<PartyCompanionBaseInformations>(new PartyCompanionBaseInformations() );
          _loc4_->deserialize(param1);
          this->companions.append(_loc4_);
          _loc3_++;
        }
        return;
      }
    }
  }
}

PartyInvitationMemberInformations::PartyInvitationMemberInformations()
{
  m_types<<ClassEnum::PARTYINVITATIONMEMBERINFORMATIONS;
}

bool PartyInvitationMemberInformations::operator==(const PartyInvitationMemberInformations &compared)
{
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(subAreaId == compared.subAreaId)
  if(companions == compared.companions)
  return true;
  
  return false;
}

