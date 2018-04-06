#include "ObjectEffectDuration.h"

void ObjectEffectDuration::serialize(Writer *param1)
{
  this->serializeAs_ObjectEffectDuration(param1);
}

void ObjectEffectDuration::serializeAs_ObjectEffectDuration(Writer *param1)
{
  ObjectEffect::serializeAs_ObjectEffect(param1);
  if(this->days < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->days << ") on element days.";
  }
  else
  {
    param1->writeVarShort((int)this->days);
    if(this->hours < 0)
    {
      qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->hours << ") on element hours.";
    }
    else
    {
      param1->writeByte(this->hours);
      if(this->minutes < 0)
      {
        qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->minutes << ") on element minutes.";
      }
      else
      {
        param1->writeByte(this->minutes);
        return;
      }
    }
  }
}

void ObjectEffectDuration::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectEffectDuration(param1);
}

void ObjectEffectDuration::deserializeAs_ObjectEffectDuration(Reader *param1)
{
  ObjectEffect::deserialize(param1);
  this->days = param1->readVarUhShort();
  if(this->days < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->days << ") on element of ObjectEffectDuration.days.";
  }
  else
  {
    this->hours = param1->readByte();
    if(this->hours < 0)
    {
      qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->hours << ") on element of ObjectEffectDuration.hours.";
    }
    else
    {
      this->minutes = param1->readByte();
      if(this->minutes < 0)
      {
        qDebug()<<"ERREUR - ObjectEffectDuration -"<<"Forbidden value (" << this->minutes << ") on element of ObjectEffectDuration.minutes.";
      }
      else
      {
        return;
      }
    }
  }
}

ObjectEffectDuration::ObjectEffectDuration()
{
  m_types<<ClassEnum::OBJECTEFFECTDURATION;
}

bool ObjectEffectDuration::operator==(const ObjectEffectDuration &compared)
{
  if(days == compared.days)
  if(hours == compared.hours)
  if(minutes == compared.minutes)
  return true;
  
  return false;
}

