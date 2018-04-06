#include "GameRolePlayMerchantInformations.h"

void GameRolePlayMerchantInformations::serialize(Writer *param1)
{
  this->serializeAs_GameRolePlayMerchantInformations(param1);
}

void GameRolePlayMerchantInformations::serializeAs_GameRolePlayMerchantInformations(Writer *param1)
{
  GameRolePlayNamedActorInformations::serializeAs_GameRolePlayNamedActorInformations(param1);
  if(this->sellType < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayMerchantInformations -"<<"Forbidden value (" << this->sellType << ") on element sellType.";
  }
  else
  {
    param1->writeByte(this->sellType);
    param1->writeShort((short)this->options.size());
    uint _loc2_ = 0;
    while(_loc2_ < this->options.size())
    {
      param1->writeShort((short)qSharedPointerCast<HumanOption>(this->options[_loc2_])->getTypes().last());
      qSharedPointerCast<HumanOption>(this->options[_loc2_])->serialize(param1);
      _loc2_++;
    }
    return;
  }
}

void GameRolePlayMerchantInformations::deserialize(Reader *param1)
{
  this->deserializeAs_GameRolePlayMerchantInformations(param1);
}

void GameRolePlayMerchantInformations::deserializeAs_GameRolePlayMerchantInformations(Reader *param1)
{
  uint _loc4_ = 0;
  QSharedPointer<HumanOption> _loc5_ ;
  GameRolePlayNamedActorInformations::deserialize(param1);
  this->sellType = param1->readByte();
  if(this->sellType < 0)
  {
    qDebug()<<"ERREUR - GameRolePlayMerchantInformations -"<<"Forbidden value (" << this->sellType << ") on element of GameRolePlayMerchantInformations.sellType.";
  }
  else
  {
    uint _loc2_ = param1->readUShort();
    uint _loc3_ = 0;
    while(_loc3_ < _loc2_)
    {
      _loc4_ = param1->readUShort();
      _loc5_ = qSharedPointerCast<HumanOption>(ClassManagerSingleton::get()->getClass(_loc4_));
      _loc5_->deserialize(param1);
      this->options.append(_loc5_);
      _loc3_++;
    }
    return;
  }
}

GameRolePlayMerchantInformations::GameRolePlayMerchantInformations()
{
  m_types<<ClassEnum::GAMEROLEPLAYMERCHANTINFORMATIONS;
}

bool GameRolePlayMerchantInformations::operator==(const GameRolePlayMerchantInformations &compared)
{
  if(sellType == compared.sellType)
  if(options == compared.options)
  return true;
  
  return false;
}

