#include "HavenBagFurnitureInformation.h"

void HavenBagFurnitureInformation::serialize(Writer *param1)
{
  this->serializeAs_HavenBagFurnitureInformation(param1);
}

void HavenBagFurnitureInformation::serializeAs_HavenBagFurnitureInformation(Writer *param1)
{
  if(this->cellId < 0)
  {
    qDebug()<<"ERREUR - HavenBagFurnitureInformation -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeVarShort((int)this->cellId);
    param1->writeInt((int)this->funitureId);
    if(this->orientation < 0)
    {
      qDebug()<<"ERREUR - HavenBagFurnitureInformation -"<<"Forbidden value (" << this->orientation << ") on element orientation.";
    }
    else
    {
      param1->writeByte(this->orientation);
      return;
    }
  }
}

void HavenBagFurnitureInformation::deserialize(Reader *param1)
{
  this->deserializeAs_HavenBagFurnitureInformation(param1);
}

void HavenBagFurnitureInformation::deserializeAs_HavenBagFurnitureInformation(Reader *param1)
{
  this->cellId = param1->readVarUhShort();
  if(this->cellId < 0)
  {
    qDebug()<<"ERREUR - HavenBagFurnitureInformation -"<<"Forbidden value (" << this->cellId << ") on element of HavenBagFurnitureInformation.cellId.";
  }
  else
  {
    this->funitureId = param1->readInt();
    this->orientation = param1->readByte();
    if(this->orientation < 0)
    {
      qDebug()<<"ERREUR - HavenBagFurnitureInformation -"<<"Forbidden value (" << this->orientation << ") on element of HavenBagFurnitureInformation.orientation.";
    }
    else
    {
      return;
    }
  }
}

HavenBagFurnitureInformation::HavenBagFurnitureInformation()
{
  m_types<<ClassEnum::HAVENBAGFURNITUREINFORMATION;
}

bool HavenBagFurnitureInformation::operator==(const HavenBagFurnitureInformation &compared)
{
  if(cellId == compared.cellId)
  if(funitureId == compared.funitureId)
  if(orientation == compared.orientation)
  return true;
  
  return false;
}

