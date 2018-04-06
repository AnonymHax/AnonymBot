#include "GameRolePlayGroupMonsterInformations.h"

void GameRolePlayGroupMonsterInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayGroupMonsterInformations(param1);
}

void GameRolePlayGroupMonsterInformations::serializeAs_GameRolePlayGroupMonsterInformations(Writer *param1)
{
  GameRolePlayActorInformations::serializeAs_GameRolePlayActorInformations(param1);
  uint _loc2_ = 0;
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 0, this->keyRingBonus);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 1, this->hasHardcoreDrop);
  _loc2_ = BooleanByteWrapper::setFlag(_loc2_, 2, this->hasAVARewardToken);
  param1->writeByte(_loc2_);
  param1->writeShort((short)this->staticInfos->getTypes().last());
  this->staticInfos->serialize(param1);
  if(this->creationTime < 0 || this->creationTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayGroupMonsterInformations -"<<"Forbidden value (" << this->creationTime << ") on element creationTime.";
  }
  else
  {
    param1->writeDouble(this->creationTime);
    if(this->ageBonusRate < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayGroupMonsterInformations -"<<"Forbidden value (" << this->ageBonusRate << ") on element ageBonusRate.";
    }
    else
    {
      param1->writeInt((int)this->ageBonusRate);
      if(this->lootShare < -1 || this->lootShare > 8)
      {
        qDebug()<<"ERREUR - GameRolePlayGroupMonsterInformations -"<<"Forbidden value (" << this->lootShare << ") on element lootShare.";
      }
      else
      {
        param1->writeByte(this->lootShare);
        param1->writeByte(this->alignmentSide);
        return;
      }
    }
  }
}

void GameRolePlayGroupMonsterInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayGroupMonsterInformations(param1);
}

void GameRolePlayGroupMonsterInformations::deserializeAs_GameRolePlayGroupMonsterInformations(Reader *param1)
{
  GameRolePlayActorInformations::deserialize(param1);
  uint _loc2_ = param1->readByte();
  this->keyRingBonus = BooleanByteWrapper::getFlag(_loc2_, 0);
  this->hasHardcoreDrop = BooleanByteWrapper::getFlag(_loc2_, 1);
  this->hasAVARewardToken = BooleanByteWrapper::getFlag(_loc2_, 2);
  uint _loc3_ = param1->readUShort();
  this->staticInfos = qSharedPointerCast<GroupMonsterStaticInformations>(ClassManagerSingleton::get()->getClass(_loc3_));
  this->staticInfos->deserialize(param1);
  this->creationTime = param1->readDouble();
  if(this->creationTime < 0 || this->creationTime > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameRolePlayGroupMonsterInformations -"<<"Forbidden value (" << this->creationTime << ") on element of GameRolePlayGroupMonsterInformations.creationTime.";
  }
  else
  {
    this->ageBonusRate = param1->readInt();
    if(this->ageBonusRate < 0)
    {
      qDebug()<<"ERREUR - GameRolePlayGroupMonsterInformations -"<<"Forbidden value (" << this->ageBonusRate << ") on element of GameRolePlayGroupMonsterInformations.ageBonusRate.";
    }
    else
    {
      this->lootShare = param1->readByte();
      if(this->lootShare < -1 || this->lootShare > 8)
      {
        qDebug()<<"ERREUR - GameRolePlayGroupMonsterInformations -"<<"Forbidden value (" << this->lootShare << ") on element of GameRolePlayGroupMonsterInformations.lootShare.";
      }
      else
      {
        this->alignmentSide = param1->readByte();
        return;
      }
    }
  }
}

GameRolePlayGroupMonsterInformations::GameRolePlayGroupMonsterInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYGROUPMONSTERINFORMATIONS;
}

bool GameRolePlayGroupMonsterInformations::operator==(const GameRolePlayGroupMonsterInformations &compared)
{
  if(staticInfos == compared.staticInfos)
  if(creationTime == compared.creationTime)
  if(ageBonusRate == compared.ageBonusRate)
  if(lootShare == compared.lootShare)
  if(alignmentSide == compared.alignmentSide)
  if(keyRingBonus == compared.keyRingBonus)
  if(hasHardcoreDrop == compared.hasHardcoreDrop)
  if(hasAVARewardToken == compared.hasAVARewardToken)
  return true;
  
  return false;
}

