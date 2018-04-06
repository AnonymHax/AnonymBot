#include "Idol.h"

void Idol::serialize(Writer *param1)
{
  this->serializeAs_Idol(param1);
}

void Idol::serializeAs_Idol(Writer *param1)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  else
  {
    param1->writeVarShort((int)this->id);
    if(this->xpBonusPercent < 0)
    {
      qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->xpBonusPercent << ") on element xpBonusPercent.";
    }
    else
    {
      param1->writeVarShort((int)this->xpBonusPercent);
      if(this->dropBonusPercent < 0)
      {
        qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->dropBonusPercent << ") on element dropBonusPercent.";
      }
      else
      {
        param1->writeVarShort((int)this->dropBonusPercent);
        return;
      }
    }
  }
}

void Idol::deserialize(Reader *param1)
{
  this->deserializeAs_Idol(param1);
}

void Idol::deserializeAs_Idol(Reader *param1)
{
  this->id = param1->readVarUhShort();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->id << ") on element of Idol.id.";
  }
  else
  {
    this->xpBonusPercent = param1->readVarUhShort();
    if(this->xpBonusPercent < 0)
    {
      qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->xpBonusPercent << ") on element of Idol.xpBonusPercent.";
    }
    else
    {
      this->dropBonusPercent = param1->readVarUhShort();
      if(this->dropBonusPercent < 0)
      {
        qDebug()<<"ERREUR - Idol -"<<"Forbidden value (" << this->dropBonusPercent << ") on element of Idol.dropBonusPercent.";
      }
      else
      {
        return;
      }
    }
  }
}

Idol::Idol()
{
  m_types<<ClassEnum::IDOL;
}

bool Idol::operator==(const Idol &compared)
{
  if(id == compared.id)
  if(xpBonusPercent == compared.xpBonusPercent)
  if(dropBonusPercent == compared.dropBonusPercent)
  return true;
  
  return false;
}

