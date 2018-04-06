#include "BasicGuildInformations.h"

void BasicGuildInformations::serialize(Writer *param1)
{
  this->serializeAs_BasicGuildInformations(param1);
}

void BasicGuildInformations::serializeAs_BasicGuildInformations(Writer *param1)
{
  AbstractSocialGroupInfos::serializeAs_AbstractSocialGroupInfos(param1);
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - BasicGuildInformations -"<<"Forbidden value (" << this->guildId << ") on element guildId.";
  }
  else
  {
    param1->writeVarInt((int)this->guildId);
    param1->writeUTF(this->guildName);
    if(this->guildLevel < 0 || this->guildLevel > 200)
    {
      qDebug()<<"ERREUR - BasicGuildInformations -"<<"Forbidden value (" << this->guildLevel << ") on element guildLevel.";
    }
    else
    {
      param1->writeByte(this->guildLevel);
      return;
    }
  }
}

void BasicGuildInformations::deserialize(Reader *param1)
{
  this->deserializeAs_BasicGuildInformations(param1);
}

void BasicGuildInformations::deserializeAs_BasicGuildInformations(Reader *param1)
{
  AbstractSocialGroupInfos::deserialize(param1);
  this->guildId = param1->readVarUhInt();
  if(this->guildId < 0)
  {
    qDebug()<<"ERREUR - BasicGuildInformations -"<<"Forbidden value (" << this->guildId << ") on element of BasicGuildInformations.guildId.";
  }
  else
  {
    this->guildName = param1->readUTF();
    this->guildLevel = param1->readUByte();
    if(this->guildLevel < 0 || this->guildLevel > 200)
    {
      qDebug()<<"ERREUR - BasicGuildInformations -"<<"Forbidden value (" << this->guildLevel << ") on element of BasicGuildInformations.guildLevel.";
    }
    else
    {
      return;
    }
  }
}

BasicGuildInformations::BasicGuildInformations()
{
  m_types<<ClassEnum::BASICGUILDINFORMATIONS;
}

bool BasicGuildInformations::operator==(const BasicGuildInformations &compared)
{
  if(guildId == compared.guildId)
  if(guildName == compared.guildName)
  if(guildLevel == compared.guildLevel)
  return true;
  
  return false;
}

