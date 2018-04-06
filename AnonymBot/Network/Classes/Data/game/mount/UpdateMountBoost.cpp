#include "UpdateMountBoost.h"

void UpdateMountBoost::serialize(Writer *param1)
{
  this->serializeAs_UpdateMountBoost(param1);
}

void UpdateMountBoost::serializeAs_UpdateMountBoost(Writer *param1)
{
  param1->writeByte(this->type);
}

void UpdateMountBoost::deserialize(Reader *param1)
{
  this->deserializeAs_UpdateMountBoost(param1);
}

void UpdateMountBoost::deserializeAs_UpdateMountBoost(Reader *param1)
{
  this->type = param1->readByte();
  if(this->type < 0)
  {
    qDebug()<<"ERREUR - UpdateMountBoost -"<<"Forbidden value (" << this->type << ") on element of UpdateMountBoost.type.";
  }
  else
  {
    return;
  }
}

UpdateMountBoost::UpdateMountBoost()
{
  m_types<<ClassEnum::UPDATEMOUNTBOOST;
}

bool UpdateMountBoost::operator==(const UpdateMountBoost &compared)
{
  if(type == compared.type)
  return true;
  
  return false;
}

