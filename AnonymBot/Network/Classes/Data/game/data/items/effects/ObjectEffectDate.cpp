#include "ObjectEffectDate.h"

void ObjectEffectDate::serialize(Writer *param1)
{
  this->serializeAs_ObjectEffectDate(param1);
}

void ObjectEffectDate::serializeAs_ObjectEffectDate(Writer *param1)
{
  ObjectEffect::serializeAs_ObjectEffect(param1);
  if(this->year < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->year << ") on element year.";
  }
  else
  {
    param1->writeVarShort((int)this->year);
    if(this->month < 0)
    {
      qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->month << ") on element month.";
    }
    else
    {
      param1->writeByte(this->month);
      if(this->day < 0)
      {
        qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->day << ") on element day.";
      }
      else
      {
        param1->writeByte(this->day);
        if(this->hour < 0)
        {
          qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->hour << ") on element hour.";
        }
        else
        {
          param1->writeByte(this->hour);
          if(this->minute < 0)
          {
            qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->minute << ") on element minute.";
          }
          else
          {
            param1->writeByte(this->minute);
            return;
          }
        }
      }
    }
  }
}

void ObjectEffectDate::deserialize(Reader *param1)
{
  this->deserializeAs_ObjectEffectDate(param1);
}

void ObjectEffectDate::deserializeAs_ObjectEffectDate(Reader *param1)
{
  ObjectEffect::deserialize(param1);
  this->year = param1->readVarUhShort();
  if(this->year < 0)
  {
    qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->year << ") on element of ObjectEffectDate.year.";
  }
  else
  {
    this->month = param1->readByte();
    if(this->month < 0)
    {
      qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->month << ") on element of ObjectEffectDate.month.";
    }
    else
    {
      this->day = param1->readByte();
      if(this->day < 0)
      {
        qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->day << ") on element of ObjectEffectDate.day.";
      }
      else
      {
        this->hour = param1->readByte();
        if(this->hour < 0)
        {
          qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->hour << ") on element of ObjectEffectDate.hour.";
        }
        else
        {
          this->minute = param1->readByte();
          if(this->minute < 0)
          {
            qDebug()<<"ERREUR - ObjectEffectDate -"<<"Forbidden value (" << this->minute << ") on element of ObjectEffectDate.minute.";
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

ObjectEffectDate::ObjectEffectDate()
{
  m_types<<ClassEnum::OBJECTEFFECTDATE;
}

bool ObjectEffectDate::operator==(const ObjectEffectDate &compared)
{
  if(year == compared.year)
  if(month == compared.month)
  if(day == compared.day)
  if(hour == compared.hour)
  if(minute == compared.minute)
  return true;
  
  return false;
}

