#include "GuildMember.h"

void GuildMember::serialize(Writer *param1)
{
  this->serializeAs_GuildMember(param1);
}

void GuildMember::serializeAs_GuildMember(Writer *param1)
{
  CharacterMinimalInformations::serializeAs_CharacterMinimalInformations(param1);
  param1->writeByte(this->breed);
  param1->writeBool(this->sex);
  if(this->rank < 0)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->rank << ") on element rank.";
  }
  else
  {
    param1->writeVarShort((int)this->rank);
    if(this->givenExperience < 0 || this->givenExperience > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->givenExperience << ") on element givenExperience.";
    }
    else
    {
      param1->writeVarLong((double)this->givenExperience);
      if(this->experienceGivenPercent < 0 || this->experienceGivenPercent > 100)
      {
        qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->experienceGivenPercent << ") on element experienceGivenPercent.";
      }
      else
      {
        param1->writeByte(this->experienceGivenPercent);
        if(this->rights < 0)
        {
          qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->rights << ") on element rights.";
        }
        else
        {
          param1->writeVarInt((int)this->rights);
          param1->writeByte(this->connected);
          param1->writeByte(this->alignmentSide);
          if(this->hoursSinceLastConnection < 0 || this->hoursSinceLastConnection > 65535)
          {
            qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->hoursSinceLastConnection << ") on element hoursSinceLastConnection.";
          }
          else
          {
            param1->writeShort((short)this->hoursSinceLastConnection);
            if(this->moodSmileyId < 0)
            {
              qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->moodSmileyId << ") on element moodSmileyId.";
            }
            else
            {
              param1->writeVarShort((int)this->moodSmileyId);
              if(this->accountId < 0)
              {
                qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
              }
              else
              {
                param1->writeInt((int)this->accountId);
                param1->writeInt((int)this->achievementPoints);
                param1->writeShort((short)this->status->getTypes().last());
                this->status->serialize(param1);
                return;
              }
            }
          }
        }
      }
    }
  }
}

void GuildMember::deserialize(Reader *param1)
{
  this->deserializeAs_GuildMember(param1);
}

void GuildMember::deserializeAs_GuildMember(Reader *param1)
{
  CharacterMinimalInformations::deserialize(param1);
  this->breed = param1->readByte();
  this->sex = param1->readBool();
  this->rank = param1->readVarUhShort();
  if(this->rank < 0)
  {
    qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->rank << ") on element of GuildMember.rank.";
  }
  else
  {
    this->givenExperience = param1->readVarUhLong();
    if(this->givenExperience < 0 || this->givenExperience > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->givenExperience << ") on element of GuildMember.givenExperience.";
    }
    else
    {
      this->experienceGivenPercent = param1->readByte();
      if(this->experienceGivenPercent < 0 || this->experienceGivenPercent > 100)
      {
        qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->experienceGivenPercent << ") on element of GuildMember.experienceGivenPercent.";
      }
      else
      {
        this->rights = param1->readVarUhInt();
        if(this->rights < 0)
        {
          qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->rights << ") on element of GuildMember.rights.";
        }
        else
        {
          this->connected = param1->readByte();
          if(this->connected < 0)
          {
            qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->connected << ") on element of GuildMember.connected.";
          }
          else
          {
            this->alignmentSide = param1->readByte();
            this->hoursSinceLastConnection = param1->readUShort();
            if(this->hoursSinceLastConnection < 0 || this->hoursSinceLastConnection > 65535)
            {
              qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->hoursSinceLastConnection << ") on element of GuildMember.hoursSinceLastConnection.";
            }
            else
            {
              this->moodSmileyId = param1->readVarUhShort();
              if(this->moodSmileyId < 0)
              {
                qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->moodSmileyId << ") on element of GuildMember.moodSmileyId.";
              }
              else
              {
                this->accountId = param1->readInt();
                if(this->accountId < 0)
                {
                  qDebug()<<"ERREUR - GuildMember -"<<"Forbidden value (" << this->accountId << ") on element of GuildMember.accountId.";
                }
                else
                {
                  this->achievementPoints = param1->readInt();
                  uint _loc2_ = param1->readUShort();
                  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_loc2_));
                  this->status->deserialize(param1);
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

GuildMember::GuildMember()
{
  m_types<<ClassEnum::GUILDMEMBER;
}

bool GuildMember::operator==(const GuildMember &compared)
{
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(rank == compared.rank)
  if(givenExperience == compared.givenExperience)
  if(experienceGivenPercent == compared.experienceGivenPercent)
  if(rights == compared.rights)
  if(connected == compared.connected)
  if(alignmentSide == compared.alignmentSide)
  if(hoursSinceLastConnection == compared.hoursSinceLastConnection)
  if(moodSmileyId == compared.moodSmileyId)
  if(accountId == compared.accountId)
  if(achievementPoints == compared.achievementPoints)
  if(status == compared.status)
  return true;
  
  return false;
}

