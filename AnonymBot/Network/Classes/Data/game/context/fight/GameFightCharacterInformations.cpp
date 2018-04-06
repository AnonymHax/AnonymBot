#include "GameFightCharacterInformations.h"

void GameFightCharacterInformations::serialize(Writer *param1)
{
  this->serializeAs_GameFightCharacterInformations(param1);
}

void GameFightCharacterInformations::serializeAs_GameFightCharacterInformations(Writer *param1)
{
  GameFightFighterNamedInformations::serializeAs_GameFightFighterNamedInformations(param1);
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GameFightCharacterInformations -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  else
  {
    param1->writeByte(this->level);
    this->alignmentInfos.serializeAs_ActorAlignmentInformations(param1);
    param1->writeByte(this->breed);
    param1->writeBool(this->sex);
    return;
  }
}

void GameFightCharacterInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameFightCharacterInformations(param1);
}

void GameFightCharacterInformations::deserializeAs_GameFightCharacterInformations(Reader *param1)
{
  GameFightFighterNamedInformations::deserialize(param1);
  this->level = param1->readUByte();
  if(this->level < 0 || this->level > 255)
  {
    qDebug()<<"ERREUR - GameFightCharacterInformations -"<<"Forbidden value (" << this->level << ") on element of GameFightCharacterInformations.level.";
  }
  else
  {
    this->alignmentInfos = ActorAlignmentInformations();
    this->alignmentInfos.deserialize(param1);
    this->breed = param1->readByte();
    this->sex = param1->readBool();
    return;
  }
}

GameFightCharacterInformations::GameFightCharacterInformations()
{
  m_types<<ClassEnum::GAMEFIGHTCHARACTERINFORMATIONS;
}

bool GameFightCharacterInformations::operator==(const GameFightCharacterInformations &compared)
{
  if(level == compared.level)
  if(alignmentInfos == compared.alignmentInfos)
  if(breed == compared.breed)
  if(sex == compared.sex)
  return true;
  
  return false;
}

