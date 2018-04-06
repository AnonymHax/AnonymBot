#include "AbstractFightDispellableEffect.h"

void AbstractFightDispellableEffect::serialize(Writer *param1)
{
  this->serializeAs_AbstractFightDispellableEffect(param1);
}

void AbstractFightDispellableEffect::serializeAs_AbstractFightDispellableEffect(Writer *param1)
{
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->uid << ") on element uid.";
  }
  else
  {
    param1->writeVarInt((int)this->uid);
    if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
    }
    else
    {
      param1->writeDouble(this->targetId);
      param1->writeShort((short)this->turnDuration);
      param1->writeByte(this->dispelable);
      if(this->spellId < 0)
      {
        qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
      }
      else
      {
        param1->writeVarShort((int)this->spellId);
        if(this->effectId < 0)
        {
          qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->effectId << ") on element effectId.";
        }
        else
        {
          param1->writeVarInt((int)this->effectId);
          if(this->parentBoostUid < 0)
          {
            qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->parentBoostUid << ") on element parentBoostUid.";
          }
          else
          {
            param1->writeVarInt((int)this->parentBoostUid);
            return;
          }
        }
      }
    }
  }
}

void AbstractFightDispellableEffect::deserialize(Reader *param1)
{
  this->deserializeAs_AbstractFightDispellableEffect(param1);
}

void AbstractFightDispellableEffect::deserializeAs_AbstractFightDispellableEffect(Reader *param1)
{
  this->uid = param1->readVarUhInt();
  if(this->uid < 0)
  {
    qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->uid << ") on element of AbstractFightDispellableEffect.uid.";
  }
  else
  {
    this->targetId = param1->readDouble();
    if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->targetId << ") on element of AbstractFightDispellableEffect.targetId.";
    }
    else
    {
      this->turnDuration = param1->readShort();
      this->dispelable = param1->readByte();
      if(this->dispelable < 0)
      {
        qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->dispelable << ") on element of AbstractFightDispellableEffect.dispelable.";
      }
      else
      {
        this->spellId = param1->readVarUhShort();
        if(this->spellId < 0)
        {
          qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->spellId << ") on element of AbstractFightDispellableEffect.spellId.";
        }
        else
        {
          this->effectId = param1->readVarUhInt();
          if(this->effectId < 0)
          {
            qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->effectId << ") on element of AbstractFightDispellableEffect.effectId.";
          }
          else
          {
            this->parentBoostUid = param1->readVarUhInt();
            if(this->parentBoostUid < 0)
            {
              qDebug()<<"ERREUR - AbstractFightDispellableEffect -"<<"Forbidden value (" << this->parentBoostUid << ") on element of AbstractFightDispellableEffect.parentBoostUid.";
            }
            else
            {
              return;
            }
          }
        }
      }
    }
  }
}

AbstractFightDispellableEffect::AbstractFightDispellableEffect()
{
  m_types<<ClassEnum::ABSTRACTFIGHTDISPELLABLEEFFECT;
}

bool AbstractFightDispellableEffect::operator==(const AbstractFightDispellableEffect &compared)
{
  if(uid == compared.uid)
  if(targetId == compared.targetId)
  if(turnDuration == compared.turnDuration)
  if(dispelable == compared.dispelable)
  if(spellId == compared.spellId)
  if(effectId == compared.effectId)
  if(parentBoostUid == compared.parentBoostUid)
  return true;
  
  return false;
}

