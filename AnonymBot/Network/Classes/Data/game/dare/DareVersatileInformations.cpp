#include "DareVersatileInformations.h"

void DareVersatileInformations::serialize(Writer *param1)
{
  this->serializeAs_DareVersatileInformations(param1);
}

void DareVersatileInformations::serializeAs_DareVersatileInformations(Writer *param1)
{
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareVersatileInformations -"<<"Forbidden value (" << this->dareId << ") on element dareId.";
  }
  else
  {
    param1->writeDouble(this->dareId);
    if(this->countEntrants < 0)
    {
      qDebug()<<"ERREUR - DareVersatileInformations -"<<"Forbidden value (" << this->countEntrants << ") on element countEntrants.";
    }
    else
    {
      param1->writeInt((int)this->countEntrants);
      if(this->countWinners < 0)
      {
        qDebug()<<"ERREUR - DareVersatileInformations -"<<"Forbidden value (" << this->countWinners << ") on element countWinners.";
      }
      else
      {
        param1->writeInt((int)this->countWinners);
        return;
      }
    }
  }
}

void DareVersatileInformations::deserialize(Reader *param1)
{
  this->deserializeAs_DareVersatileInformations(param1);
}

void DareVersatileInformations::deserializeAs_DareVersatileInformations(Reader *param1)
{
  this->dareId = param1->readDouble();
  if(this->dareId < 0 || this->dareId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - DareVersatileInformations -"<<"Forbidden value (" << this->dareId << ") on element of DareVersatileInformations.dareId.";
  }
  else
  {
    this->countEntrants = param1->readInt();
    if(this->countEntrants < 0)
    {
      qDebug()<<"ERREUR - DareVersatileInformations -"<<"Forbidden value (" << this->countEntrants << ") on element of DareVersatileInformations.countEntrants.";
    }
    else
    {
      this->countWinners = param1->readInt();
      if(this->countWinners < 0)
      {
        qDebug()<<"ERREUR - DareVersatileInformations -"<<"Forbidden value (" << this->countWinners << ") on element of DareVersatileInformations.countWinners.";
      }
      else
      {
        return;
      }
    }
  }
}

DareVersatileInformations::DareVersatileInformations()
{
  m_types<<ClassEnum::DAREVERSATILEINFORMATIONS;
}

bool DareVersatileInformations::operator==(const DareVersatileInformations &compared)
{
  if(dareId == compared.dareId)
  if(countEntrants == compared.countEntrants)
  if(countWinners == compared.countWinners)
  return true;
  
  return false;
}

