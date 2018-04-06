#include "DungeonPartyFinderPlayer.h"

void DungeonPartyFinderPlayer::serialize(Writer *param1)
{
  this->serializeAs_DungeonPartyFinderPlayer(param1);
}

void DungeonPartyFinderPlayer::serializeAs_DungeonPartyFinderPlayer(Writer *param1)
{
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderPlayer -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    param1->writeUTF(this->playerName);
    param1->writeByte(this->breed);
    param1->writeBool(this->sex);
    if(this->level < 0 || this->level > 255)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderPlayer -"<<"Forbidden value (" << this->level << ") on element level.";
    }
    else
    {
      param1->writeByte(this->level);
      return;
    }
  }
}

void DungeonPartyFinderPlayer::deserialize(Reader *param1)
{
  this->deserializeAs_DungeonPartyFinderPlayer(param1);
}

void DungeonPartyFinderPlayer::deserializeAs_DungeonPartyFinderPlayer(Reader *param1)
{
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderPlayer -"<<"Forbidden value (" << this->playerId << ") on element of DungeonPartyFinderPlayer.playerId.";
  }
  else
  {
    this->playerName = param1->readUTF();
    this->breed = param1->readByte();
    if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::HUPPERMAGE)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderPlayer -"<<"Forbidden value (" << this->breed << ") on element of DungeonPartyFinderPlayer.breed.";
    }
    else
    {
      this->sex = param1->readBool();
      this->level = param1->readUByte();
      if(this->level < 0 || this->level > 255)
      {
        qDebug()<<"ERREUR - DungeonPartyFinderPlayer -"<<"Forbidden value (" << this->level << ") on element of DungeonPartyFinderPlayer.level.";
      }
      else
      {
        return;
      }
    }
  }
}

DungeonPartyFinderPlayer::DungeonPartyFinderPlayer()
{
  m_types<<ClassEnum::DUNGEONPARTYFINDERPLAYER;
}

bool DungeonPartyFinderPlayer::operator==(const DungeonPartyFinderPlayer &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(level == compared.level)
  return true;
  
  return false;
}

