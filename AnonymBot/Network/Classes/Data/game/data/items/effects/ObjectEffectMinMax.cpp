#include "ObjectEffectMinMax.h"

void ObjectEffectMinMax::serialize(Writer *param1)
{
  this->serializeAs_ObjectEffectMinMax(param1);
}

void ObjectEffectMinMax::serializeAs_ObjectEffectMinMax(Writer *param1)
{
  ObjectEffect::serializeAs_ObjectEffect(param1);
  if(this->min < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMinMax -"<<"Forbidden value (" << this->min << ") on element min.";
  }
  else
  {
    param1->writeVarInt((int)this->min);
    if(this->max < 0)
    {
      qDebug()<<"ERREUR - ObjectEffectMinMax -"<<"Forbidden value (" << this->max << ") on element max.";
    }
    else
    {
      param1->writeVarInt((int)this->max);
      return;
    }
  }
}

void ObjectEffectMinMax::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectEffectMinMax(param1);
}

void ObjectEffectMinMax::deserializeAs_ObjectEffectMinMax(Reader *param1)
{
  ObjectEffect::deserialize(param1);
  this->min = param1->readVarUhInt();
  if(this->min < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMinMax -"<<"Forbidden value (" << this->min << ") on element of ObjectEffectMinMax.min.";
  }
  else
  {
    this->max = param1->readVarUhInt();
    if(this->max < 0)
    {
      qDebug()<<"ERREUR - ObjectEffectMinMax -"<<"Forbidden value (" << this->max << ") on element of ObjectEffectMinMax.max.";
    }
    else
    {
      return;
    }
  }
}

ObjectEffectMinMax::ObjectEffectMinMax()
{
  m_types<<ClassEnum::OBJECTEFFECTMINMAX;
}

bool ObjectEffectMinMax::operator==(const ObjectEffectMinMax &compared)
{
  if(min == compared.min)
  if(max == compared.max)
  return true;
  
  return false;
}

