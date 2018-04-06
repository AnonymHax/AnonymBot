#include "EntityDispositionInformations.h"

void EntityDispositionInformations::serialize(Writer *param1)
{
  this->serializeAs_EntityDispositionInformations(param1);
}

void EntityDispositionInformations::serializeAs_EntityDispositionInformations(Writer *param1)
{
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - EntityDispositionInformations -"<<"Forbidden value (" << this->cellId << ") on element cellId.";
  }
  else
  {
    param1->writeShort((short)this->cellId);
    param1->writeByte(this->direction);
    return;
  }
}

void EntityDispositionInformations::deserialize(Reader *param1)
{
  this->deserializeAs_EntityDispositionInformations(param1);
}

void EntityDispositionInformations::deserializeAs_EntityDispositionInformations(Reader *param1)
{
  this->cellId = param1->readShort();
  if(this->cellId < -1 || this->cellId > 559)
  {
    qDebug()<<"ERREUR - EntityDispositionInformations -"<<"Forbidden value (" << this->cellId << ") on element of EntityDispositionInformations.cellId.";
  }
  else
  {
    this->direction = param1->readByte();
    if(this->direction < 0)
    {
      qDebug()<<"ERREUR - EntityDispositionInformations -"<<"Forbidden value (" << this->direction << ") on element of EntityDispositionInformations.direction.";
    }
    else
    {
      return;
    }
  }
}

EntityDispositionInformations::EntityDispositionInformations()
{
  m_types<<ClassEnum::ENTITYDISPOSITIONINFORMATIONS;
}

bool EntityDispositionInformations::operator==(const EntityDispositionInformations &compared)
{
  if(cellId == compared.cellId)
  if(direction == compared.direction)
  return true;
  
  return false;
}

