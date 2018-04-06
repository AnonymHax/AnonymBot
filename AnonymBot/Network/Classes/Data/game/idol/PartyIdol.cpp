#include "PartyIdol.h"

void PartyIdol::serialize(Writer *param1)
{
  this->serializeAs_PartyIdol(param1);
}

void PartyIdol::serializeAs_PartyIdol(Writer *param1)
{
  Idol::serializeAs_Idol(param1);
  param1->writeShort((short)this->ownersIds.size());
  uint _loc2_ = 0;
  while(_loc2_ < this->ownersIds.size())
  {
    if(this->ownersIds[_loc2_] < 0 || this->ownersIds[_loc2_] > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyIdol -"<<"Forbidden value (" << this->ownersIds[_loc2_] << ") on element 1 (starting at 1) of ownersIds.";
    }
    else
    {
      param1->writeVarLong((double)this->ownersIds[_loc2_]);
      _loc2_++;
      continue;
    }
  }
}

void PartyIdol::deserialize(Reader *param1)
{
  this->deserializeAs_PartyIdol(param1);
}

void PartyIdol::deserializeAs_PartyIdol(Reader *param1)
{
  auto _loc4_ = NULL;
  Idol::deserialize(param1);
  uint _loc2_ = param1->readUShort();
  uint _loc3_ = 0;
  while(_loc3_ < _loc2_)
  {
    _loc4_ = param1->readVarUhLong();
    if(_loc4_ < 0 || _loc4_ > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyIdol -"<<"Forbidden value (" << _loc4_ << ") on elements of ownersIds.";
    }
    else
    {
      this->ownersIds.append(_loc4_);
      _loc3_++;
      continue;
    }
  }
}

PartyIdol::PartyIdol()
{
  m_types<<ClassEnum::PARTYIDOL;
}

bool PartyIdol::operator==(const PartyIdol &compared)
{
  if(ownersIds == compared.ownersIds)
  return true;
  
  return false;
}

