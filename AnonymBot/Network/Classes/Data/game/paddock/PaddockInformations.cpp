#include "PaddockInformations.h"

void PaddockInformations::serialize(Writer *param1)
{
  this->serializeAs_PaddockInformations(param1);
}

void PaddockInformations::serializeAs_PaddockInformations(Writer *param1)
{
  if(this->maxOutdoorMount < 0)
  {
    qDebug()<<"ERREUR - PaddockInformations -"<<"Forbidden value (" << this->maxOutdoorMount << ") on element maxOutdoorMount.";
  }
  else
  {
    param1->writeVarShort((int)this->maxOutdoorMount);
    if(this->maxItems < 0)
    {
      qDebug()<<"ERREUR - PaddockInformations -"<<"Forbidden value (" << this->maxItems << ") on element maxItems.";
    }
    else
    {
      param1->writeVarShort((int)this->maxItems);
      return;
    }
  }
}

void PaddockInformations::deserialize(Reader *param1)
{
  this->deserializeAs_PaddockInformations(param1);
}

void PaddockInformations::deserializeAs_PaddockInformations(Reader *param1)
{
  this->maxOutdoorMount = param1->readVarUhShort();
  if(this->maxOutdoorMount < 0)
  {
    qDebug()<<"ERREUR - PaddockInformations -"<<"Forbidden value (" << this->maxOutdoorMount << ") on element of PaddockInformations.maxOutdoorMount.";
  }
  else
  {
    this->maxItems = param1->readVarUhShort();
    if(this->maxItems < 0)
    {
      qDebug()<<"ERREUR - PaddockInformations -"<<"Forbidden value (" << this->maxItems << ") on element of PaddockInformations.maxItems.";
    }
    else
    {
      return;
    }
  }
}

PaddockInformations::PaddockInformations()
{
  m_types<<ClassEnum::PADDOCKINFORMATIONS;
}

bool PaddockInformations::operator==(const PaddockInformations &compared)
{
  if(maxOutdoorMount == compared.maxOutdoorMount)
  if(maxItems == compared.maxItems)
  return true;
  
  return false;
}

