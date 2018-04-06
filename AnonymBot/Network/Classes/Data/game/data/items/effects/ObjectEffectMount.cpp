#include "ObjectEffectMount.h"

void ObjectEffectMount::serialize(Writer *param1)
{
  this->serializeAs_ObjectEffectMount(param1);
}

void ObjectEffectMount::serializeAs_ObjectEffectMount(Writer *param1)
{
  ObjectEffect::serializeAs_ObjectEffect(param1);
  if(this->mountId < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->mountId << ") on element mountId.";
  }
  else
  {
    param1->writeInt((int)this->mountId);
    if(this->date < -9.007199254740992E15 || this->date > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->date << ") on element date.";
    }
    else
    {
      param1->writeDouble(this->date);
      if(this->modelId < 0)
      {
        qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->modelId << ") on element modelId.";
      }
      else
      {
        param1->writeVarShort((int)this->modelId);
        return;
      }
    }
  }
}

void ObjectEffectMount::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectEffectMount(param1);
}

void ObjectEffectMount::deserializeAs_ObjectEffectMount(Reader *param1)
{
  ObjectEffect::deserialize(param1);
  this->mountId = param1->readInt();
  if(this->mountId < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->mountId << ") on element of ObjectEffectMount.mountId.";
  }
  else
  {
    this->date = param1->readDouble();
    if(this->date < -9.007199254740992E15 || this->date > 9.007199254740992E15)
    {
      qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->date << ") on element of ObjectEffectMount.date.";
    }
    else
    {
      this->modelId = param1->readVarUhShort();
      if(this->modelId < 0)
      {
        qDebug()<<"ERREUR - ObjectEffectMount -"<<"Forbidden value (" << this->modelId << ") on element of ObjectEffectMount.modelId.";
      }
      else
      {
        return;
      }
    }
  }
}

ObjectEffectMount::ObjectEffectMount()
{
  m_types<<ClassEnum::OBJECTEFFECTMOUNT;
}

bool ObjectEffectMount::operator==(const ObjectEffectMount &compared)
{
  if(mountId == compared.mountId)
  if(date == compared.date)
  if(modelId == compared.modelId)
  return true;
  
  return false;
}

