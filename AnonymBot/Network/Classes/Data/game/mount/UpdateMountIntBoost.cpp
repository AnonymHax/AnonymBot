#include "UpdateMountIntBoost.h"

void UpdateMountIntBoost::serialize(Writer *param1)
{
  this->serializeAs_UpdateMountIntBoost(param1);
}

void UpdateMountIntBoost::serializeAs_UpdateMountIntBoost(Writer *param1)
{
  UpdateMountBoost::serializeAs_UpdateMountBoost(param1);
  param1->writeInt((int)this->value);
}

void UpdateMountIntBoost::deserialize(Reader *param1)
{
  this->deserializeAs_UpdateMountIntBoost(param1);
}

void UpdateMountIntBoost::deserializeAs_UpdateMountIntBoost(Reader *param1)
{
  UpdateMountBoost::deserialize(param1);
  this->value = param1->readInt();
}

UpdateMountIntBoost::UpdateMountIntBoost()
{
  m_types<<ClassEnum::UPDATEMOUNTINTBOOST;
}

bool UpdateMountIntBoost::operator==(const UpdateMountIntBoost &compared)
{
  if(value == compared.value)
  return true;
  
  return false;
}

