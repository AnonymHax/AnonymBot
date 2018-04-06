#include "FightDispellableEffectExtendedInformations.h"

void FightDispellableEffectExtendedInformations::serialize(Writer *param1)
{
  this->serializeAs_FightDispellableEffectExtendedInformations(param1);
}

void FightDispellableEffectExtendedInformations::serializeAs_FightDispellableEffectExtendedInformations(Writer *param1)
{
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - FightDispellableEffectExtendedInformations -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  else
  {
    param1->writeVarShort((int)this->actionId);
    if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - FightDispellableEffectExtendedInformations -"<<"Forbidden value (" << this->sourceId << ") on element sourceId.";
    }
    else
    {
      param1->writeDouble(this->sourceId);
      param1->writeShort((short)this->effect->getTypes().last());
      this->effect->serialize(param1);
      return;
    }
  }
}

void FightDispellableEffectExtendedInformations::deserialize(Reader *param1)
{
  this->deserializeAs_FightDispellableEffectExtendedInformations(param1);
}

void FightDispellableEffectExtendedInformations::deserializeAs_FightDispellableEffectExtendedInformations(Reader *param1)
{
  this->actionId = param1->readVarUhShort();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - FightDispellableEffectExtendedInformations -"<<"Forbidden value (" << this->actionId << ") on element of FightDispellableEffectExtendedInformations.actionId.";
  }
  else
  {
    this->sourceId = param1->readDouble();
    if(this->sourceId < -9.007199254740992E15 || this->sourceId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - FightDispellableEffectExtendedInformations -"<<"Forbidden value (" << this->sourceId << ") on element of FightDispellableEffectExtendedInformations.sourceId.";
    }
    else
    {
      uint _loc2_ = param1->readUShort();
      this->effect = qSharedPointerCast<AbstractFightDispellableEffect>(ClassManagerSingleton::get()->getClass(_loc2_));
      this->effect->deserialize(param1);
      return;
    }
  }
}

FightDispellableEffectExtendedInformations::FightDispellableEffectExtendedInformations()
{
  m_types<<ClassEnum::FIGHTDISPELLABLEEFFECTEXTENDEDINFORMATIONS;
}

bool FightDispellableEffectExtendedInformations::operator==(const FightDispellableEffectExtendedInformations &compared)
{
  if(actionId == compared.actionId)
  if(sourceId == compared.sourceId)
  if(effect == compared.effect)
  return true;
  
  return false;
}

