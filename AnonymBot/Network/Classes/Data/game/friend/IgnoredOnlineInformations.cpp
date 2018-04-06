#include "IgnoredOnlineInformations.h"

void IgnoredOnlineInformations::serialize(Writer *param1)
{
  this->serializeAs_IgnoredOnlineInformations(param1);
}

void IgnoredOnlineInformations::serializeAs_IgnoredOnlineInformations(Writer *param1)
{
  IgnoredInformations::serializeAs_IgnoredInformations(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IgnoredOnlineInformations -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    param1->writeUTF(this->playerName);
    param1->writeByte(this->breed);
    param1->writeBool(this->sex);
    return;
  }
}

void IgnoredOnlineInformations::deserialize(Reader *param1)
{
  this->deserializeAs_IgnoredOnlineInformations(param1);
}

void IgnoredOnlineInformations::deserializeAs_IgnoredOnlineInformations(Reader *param1)
{
  IgnoredInformations::deserialize(param1);
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - IgnoredOnlineInformations -"<<"Forbidden value (" << this->playerId << ") on element of IgnoredOnlineInformations.playerId.";
  }
  else
  {
    this->playerName = param1->readUTF();
    this->breed = param1->readByte();
    if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::HUPPERMAGE)
    {
      qDebug()<<"ERREUR - IgnoredOnlineInformations -"<<"Forbidden value (" << this->breed << ") on element of IgnoredOnlineInformations.breed.";
    }
    else
    {
      this->sex = param1->readBool();
      return;
    }
  }
}

IgnoredOnlineInformations::IgnoredOnlineInformations()
{
  m_types<<ClassEnum::IGNOREDONLINEINFORMATIONS;
}

bool IgnoredOnlineInformations::operator==(const IgnoredOnlineInformations &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(breed == compared.breed)
  if(sex == compared.sex)
  return true;
  
  return false;
}

