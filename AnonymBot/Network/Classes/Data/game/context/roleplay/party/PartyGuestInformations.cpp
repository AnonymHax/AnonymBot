#include "PartyGuestInformations.h"

void PartyGuestInformations::serialize(Writer *param1)
{
  this->serializeAs_PartyGuestInformations(param1);
}

void PartyGuestInformations::serializeAs_PartyGuestInformations(Writer *param1)
{
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyGuestInformations -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
  }
  else
  {
    param1->writeVarLong((double)this->guestId);
    if(this->hostId < 0 || this->hostId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyGuestInformations -"<<"Forbidden value (" << this->hostId << ") on element hostId.";
    }
    else
    {
      param1->writeVarLong((double)this->hostId);
      param1->writeUTF(this->name);
      this->guestLook->serializeAs_EntityLook(param1);
      param1->writeByte(this->breed);
      param1->writeBool(this->sex);
      param1->writeShort((short)this->status->getTypes().last());
      this->status->serialize(param1);
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

void PartyGuestInformations::deserialize(Reader *param1)
{
  this->deserializeAs_PartyGuestInformations(param1);
}

void PartyGuestInformations::deserializeAs_PartyGuestInformations(Reader *param1)
{
  QSharedPointer<PartyCompanionBaseInformations> _loc5_ ;
  this->guestId = param1->readVarUhLong();
  if(this->guestId < 0 || this->guestId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PartyGuestInformations -"<<"Forbidden value (" << this->guestId << ") on element of PartyGuestInformations.guestId.";
  }
  else
  {
    this->hostId = param1->readVarUhLong();
    if(this->hostId < 0 || this->hostId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - PartyGuestInformations -"<<"Forbidden value (" << this->hostId << ") on element of PartyGuestInformations.hostId.";
    }
    else
    {
      this->name = param1->readUTF();
      this->guestLook = QSharedPointer<EntityLook>(new EntityLook() );
      this->guestLook->deserialize(param1);
      this->breed = param1->readByte();
      this->sex = param1->readBool();
      uint _loc2_ = param1->readUShort();
      this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_loc2_));
      this->status->deserialize(param1);
      uint _loc3_ = param1->readUShort();
      uint _loc4_ = 0;
      while(_loc4_ < _loc3_)
      {
        _loc5_ = QSharedPointer<PartyCompanionBaseInformations>(new PartyCompanionBaseInformations() );
        _loc5_->deserialize(param1);
        this->companions.append(_loc5_);
        _loc4_++;
      }
      return;
    }
  }
}

PartyGuestInformations::PartyGuestInformations()
{
  m_types<<ClassEnum::PARTYGUESTINFORMATIONS;
}

bool PartyGuestInformations::operator==(const PartyGuestInformations &compared)
{
  if(guestId == compared.guestId)
  if(hostId == compared.hostId)
  if(name == compared.name)
  if(guestLook == compared.guestLook)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(status == compared.status)
  if(companions == compared.companions)
  return true;
  
  return false;
}

