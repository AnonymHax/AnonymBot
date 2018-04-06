#include "FriendOnlineInformations.h"

void FriendOnlineInformations::serialize(Writer *param1)
{
  this->serializeAs_FriendOnlineInformations(param1);
}

void FriendOnlineInformations::serializeAs_FriendOnlineInformations(Writer *param1)
{
  FriendInformations::serializeAs_FriendInformations(param1);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  else
  {
    param1->writeVarLong((double)this->playerId);
    param1->writeUTF(this->playerName);
    if(this->level < 0 || this->level > 206)
    {
      qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->level << ") on element level.";
    }
    else
    {
      param1->writeByte(this->level);
      param1->writeByte(this->alignmentSide);
      param1->writeByte(this->breed);
      param1->writeBool(this->sex);
      this->guildInfo->serializeAs_GuildInformations(param1);
      if(this->moodSmileyId < 0)
      {
        qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->moodSmileyId << ") on element moodSmileyId.";
      }
      else
      {
        param1->writeVarShort((int)this->moodSmileyId);
        param1->writeShort((short)this->status->getTypes().last());
        this->status->serialize(param1);
        return;
      }
    }
  }
}

void FriendOnlineInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FriendOnlineInformations(param1);
}

void FriendOnlineInformations::deserializeAs_FriendOnlineInformations(Reader *param1)
{
  FriendInformations::deserialize(param1);
  this->playerId = param1->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->playerId << ") on element of FriendOnlineInformations.playerId.";
  }
  else
  {
    this->playerName = param1->readUTF();
    this->level = param1->readUByte();
    if(this->level < 0 || this->level > 206)
    {
      qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->level << ") on element of FriendOnlineInformations.level.";
    }
    else
    {
      this->alignmentSide = param1->readByte();
      this->breed = param1->readByte();
      if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::HUPPERMAGE)
      {
        qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->breed << ") on element of FriendOnlineInformations.breed.";
      }
      else
      {
        this->sex = param1->readBool();
        this->guildInfo = QSharedPointer<GuildInformations>(new GuildInformations() );
        this->guildInfo->deserialize(param1);
        this->moodSmileyId = param1->readVarUhShort();
        if(this->moodSmileyId < 0)
        {
          qDebug()<<"ERREUR - FriendOnlineInformations -"<<"Forbidden value (" << this->moodSmileyId << ") on element of FriendOnlineInformations.moodSmileyId.";
        }
        else
        {
          uint _loc2_ = param1->readUShort();
          this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_loc2_));
          this->status->deserialize(param1);
          return;
        }
      }
    }
  }
}

FriendOnlineInformations::FriendOnlineInformations()
{
  m_types<<ClassEnum::FRIENDONLINEINFORMATIONS;
}

bool FriendOnlineInformations::operator==(const FriendOnlineInformations &compared)
{
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(level == compared.level)
  if(alignmentSide == compared.alignmentSide)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(guildInfo == compared.guildInfo)
  if(moodSmileyId == compared.moodSmileyId)
  if(status == compared.status)
  return true;
  
  return false;
}

