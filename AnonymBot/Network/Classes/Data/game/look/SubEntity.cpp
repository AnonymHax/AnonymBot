#include "SubEntity.h"
#include "Network/Classes/Data/game/look/EntityLook.h"

void SubEntity::serialize(Writer *param1)
{
  this->serializeAs_SubEntity(param1);
}

void SubEntity::serializeAs_SubEntity(Writer *param1)
{
  param1->writeByte(this->bindingPointCategory);
  if(this->bindingPointIndex < 0)
  {
    qDebug()<<"ERREUR - SubEntity -"<<"Forbidden value (" << this->bindingPointIndex << ") on element bindingPointIndex.";
  }
  else
  {
    param1->writeByte(this->bindingPointIndex);
    this->subEntityLook->serializeAs_EntityLook(param1);
    return;
  }
}

void SubEntity::deserialize(Reader *param1)
{
  this->deserializeAs_SubEntity(param1);
}

void SubEntity::deserializeAs_SubEntity(Reader *param1)
{
  this->bindingPointCategory = param1->readByte();
  if(this->bindingPointCategory < 0)
  {
    qDebug()<<"ERREUR - SubEntity -"<<"Forbidden value (" << this->bindingPointCategory << ") on element of SubEntity.bindingPointCategory.";
  }
  else
  {
    this->bindingPointIndex = param1->readByte();
    if(this->bindingPointIndex < 0)
    {
      qDebug()<<"ERREUR - SubEntity -"<<"Forbidden value (" << this->bindingPointIndex << ") on element of SubEntity.bindingPointIndex.";
    }
    else
    {
      this->subEntityLook = QSharedPointer<EntityLook>(new EntityLook() );
      this->subEntityLook->deserialize(param1);
      return;
    }
  }
}

SubEntity::SubEntity()
{
  m_types<<ClassEnum::SUBENTITY;
}

bool SubEntity::operator==(const SubEntity &compared)
{
  if(bindingPointCategory == compared.bindingPointCategory)
  if(bindingPointIndex == compared.bindingPointIndex)
  if(subEntityLook == compared.subEntityLook)
  return true;
  
  return false;
}

