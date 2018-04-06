#include "PaddockBuyableInformations.h"

void PaddockBuyableInformations::serialize(Writer *param1)
{
  this->serializeAs_PaddockBuyableInformations(param1);
}

void PaddockBuyableInformations::serializeAs_PaddockBuyableInformations(Writer *param1)
{
  PaddockInformations::serializeAs_PaddockInformations(param1);
  if(this->price < 0)
  {
    qDebug()<<"ERREUR - PaddockBuyableInformations -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  else
  {
    param1->writeVarInt((int)this->price);
    param1->writeBool(this->locked);
    return;
  }
}

void PaddockBuyableInformations::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockBuyableInformations(param1);
}

void PaddockBuyableInformations::deserializeAs_PaddockBuyableInformations(Reader *param1)
{
  PaddockInformations::deserialize(param1);
  this->price = param1->readVarUhInt();
  if(this->price < 0)
  {
    qDebug()<<"ERREUR - PaddockBuyableInformations -"<<"Forbidden value (" << this->price << ") on element of PaddockBuyableInformations.price.";
  }
  else
  {
    this->locked = param1->readBool();
    return;
  }
}

PaddockBuyableInformations::PaddockBuyableInformations()
{
  m_types<<ClassEnum::PADDOCKBUYABLEINFORMATIONS;
}

bool PaddockBuyableInformations::operator==(const PaddockBuyableInformations &compared)
{
  if(price == compared.price)
  if(locked == compared.locked)
  return true;
  
  return false;
}

