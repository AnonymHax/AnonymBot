#include "FriendSpouseInformations.h"

void FriendSpouseInformations::serialize(Writer *param1)
{
  this->serializeAs_FriendSpouseInformations(param1);
}

void FriendSpouseInformations::serializeAs_FriendSpouseInformations(Writer *param1)
{
  if(this->spouseAccountId < 0)
  {
    qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseAccountId << ") on element spouseAccountId.";
  }
  else
  {
    param1->writeInt((int)this->spouseAccountId);
    if(this->spouseId < 0 || this->spouseId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseId << ") on element spouseId.";
    }
    else
    {
      param1->writeVarLong((double)this->spouseId);
      param1->writeUTF(this->spouseName);
      if(this->spouseLevel < 1 || this->spouseLevel > 206)
      {
        qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseLevel << ") on element spouseLevel.";
      }
      else
      {
        param1->writeByte(this->spouseLevel);
        param1->writeByte(this->breed);
        param1->writeByte(this->sex);
        this->spouseEntityLook->serializeAs_EntityLook(param1);
        this->guildInfo->serializeAs_GuildInformations(param1);
        param1->writeByte(this->alignmentSide);
        return;
      }
    }
  }
}

void FriendSpouseInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FriendSpouseInformations(param1);
}

void FriendSpouseInformations::deserializeAs_FriendSpouseInformations(Reader *param1)
{
  this->spouseAccountId = param1->readInt();
  if(this->spouseAccountId < 0)
  {
    qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseAccountId << ") on element of FriendSpouseInformations.spouseAccountId.";
  }
  else
  {
    this->spouseId = param1->readVarUhLong();
    if(this->spouseId < 0 || this->spouseId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseId << ") on element of FriendSpouseInformations.spouseId.";
    }
    else
    {
      this->spouseName = param1->readUTF();
      this->spouseLevel = param1->readUByte();
      if(this->spouseLevel < 1 || this->spouseLevel > 206)
      {
        qDebug()<<"ERREUR - FriendSpouseInformations -"<<"Forbidden value (" << this->spouseLevel << ") on element of FriendSpouseInformations.spouseLevel.";
      }
      else
      {
        this->breed = param1->readByte();
        this->sex = param1->readByte();
        this->spouseEntityLook = QSharedPointer<EntityLook>(new EntityLook() );
        this->spouseEntityLook->deserialize(param1);
        this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
        this->guildInfo->deserialize(param1);
        this->alignmentSide = param1->readByte();
        return;
      }
    }
  }
}

FriendSpouseInformations::FriendSpouseInformations()
{
  m_types<<ClassEnum::FRIENDSPOUSEINFORMATIONS;
}

bool FriendSpouseInformations::operator==(const FriendSpouseInformations &compared)
{
  if(spouseAccountId == compared.spouseAccountId)
  if(spouseId == compared.spouseId)
  if(spouseName == compared.spouseName)
  if(spouseLevel == compared.spouseLevel)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(spouseEntityLook == compared.spouseEntityLook)
  if(guildInfo == compared.guildInfo)
  if(alignmentSide == compared.alignmentSide)
  return true;
  
  return false;
}

